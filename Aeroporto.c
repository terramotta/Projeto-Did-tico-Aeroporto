/*
* Lab. de Programaçao de Computadores I - Trabalho prático
*
* Aluno: Pedro Terra da Silva Motta
*
* Data: 12/04/2021


	Aeroporto

	
*/


# include <stdio.h>             	//Adiciona a biblioteca que permite a comunicação entre meu código e os recursos do meu monitor
# include <locale.h>           	 	//Adiciona a biblioteca que permite o uso de caractéres da lingua portuguesa
# include <stdlib.h>			//Adiciona a biblioteca que permite o uso de funções envolvendo alocação de memória, controle de processos, conversões e outras.
# include <time.h>			//Adiciona a biblioteca que permite o uso de funções para manipulação de tempo
# include <string.h>			//Adiciona a biblioteca que permite o uso de funções para manipulação de strings
# define LIMITE_PASSAGEIRO 1000		//Define a Constante LIMITE_PASSAGEIRO para 1000
# define LIMITE_VOO        100		//Define a Constante LIMITE_VOO para 100
# define LIMITE_PASSAGEM   1000		//Define a Constante LIMITE_PASSAGEM para 1000


int aux_voo_nulo = 0, aux_voo_exclusao = 0;					//Variaveis auxiliares para contar voos confirmados e excluidos
int aux_passageiro_nulo = 0, aux_passageiro_exclusao = 0;	//Variaveis auxiliares para contar passageiros confirmados e excluidos
int aux_passagem_nulo = 0, aux_passagem_exclusao = 0;		//Variaveis auxiliares para contar passagem confirmadas e excluidas
int aux_passagem[LIMITE_PASSAGEM] = {0};					//Vetor auxiliar para conter o número de passagens confirmadas pra cada voo

//Estrutura das variáveis do voo
struct voo{
		
	int  nulo;							//Auxiliar que, quando nulo == 1, faz com que este voo seja considerado anulado	
	int	 Identificador;					//Identificador usado como referência para este voo
	int	 Numero_Aeronave; 
	char Empresa[100];
        char Origem[100];
        char Destino[100];
  	char Data[11];
	char Horario[6];
	int  Quantidade_Passageiros;
	
};

//Estrutura das variáveis do passageiro
struct passageiro{
         		
	int  nulo;							//Auxiliar que, quando nulo == 1, faz com que este passageiro seja considerado anulado
	int  Identificador;					//Identificador usado como referência para este passageiro
	char Nome[200];
	char Identidade[14];
	char CPF[14];
	char Endereco[200];
	char Telefone[16];
	char Sexo;
		
};

//Estrutura das variáveis da passagem
struct passagem{
		
	int   nulo;							//Auxiliar que, quando nulo == 1, faz com que esta passagem seja considerada anulada
	int	  Numero; 
	int	  Identificador_Passageiro;		//Identificador usado como referência de passageiro para passagem
	int	  Identificador_Voo;			//Identificador usado como referência de voo para passagem
	int	  Numero_Poltrona;
	float Valor;
	char  Data_Venda[11];
		
};


struct voo Voo_Global[LIMITE_VOO];				//Vetor global onde estarão armazenados todos os voos (anulados ou não)
struct passageiro Passageiro_Global[LIMITE_PASSAGEIRO];		// Vetor global onde estarão armazenados todos os passageiros (anulados ou não)
struct passagem Passagem_Global[LIMITE_PASSAGEM];		// Vetor global onde estarão armazenados todas as passsagens (anuladas ou não)

/* 	Aqui fizemos de forma que, em nossos vetores de dados (vetores acima), cada voo ocupará a posição
	identificador-1 deste voo. Ou seja, se um voo tem identificador = 5, sua posição no vetor será a posição 
	Voo_Global[4].
*/

/*
Objetivo: - Interface do sub menu
Entrada: - Opções da interface
Retorno: - 	Operações concluidas e interface pronta
*/
void sub_menu(int opcao){
	
	int escolha, i;
	// Interface do Sub Menu
	do{
		printf("\n\n\t\t 1 - Inclusão\n");
		printf("\n\n\t\t 2 - Alteração\n");
		printf("\n\n\t\t 3 - Exclusão\n");
		printf("\n\n\t\t 4 - Consulta\n");
		printf("\n\n\t\t 5 - Relatório\n");
		printf("\n\n\t\t 6 - Voltar ao menu principal\n");
		printf("\n\n\t\t Escolha uma opção: ");
		scanf("%d%*c", &escolha);
		while(escolha < 1 || escolha > 6){
			printf("\n\n\t\t Escolha uma opção correta: ");
			scanf("%d", &escolha);
		}
		system("cls");
		
		switch (opcao){
			case 1:		//Voos
				
				switch (escolha){
					case 1:
						
						inclusao_voo();
						system("cls");
						break;
						
					case 2:
						
						if(aux_voo_nulo == aux_voo_exclusao){
							printf("\n\n\t\t Não existem voos registrados");
							sleep(2);
						}
						else{
							alterar_voo();
						}
						system("cls");
						break;
						
					case 3:
						
						if(aux_voo_nulo == aux_voo_exclusao){
							printf("\n\n\t\t Não existem voos registrados");
							sleep(2);
						}
						else{
							exclusao_voo();
							sleep(2);
						}
						system("cls");
						break;
						
					case 4:
						
						if(aux_voo_nulo == aux_voo_exclusao){
							printf("\n\n\t\t Não existem voos registrados");
							sleep(2);
						}
						else{
							consulta_voo();
							sleep(5);
						}
						system("cls");
						break;
					
					case 5:
						if(aux_voo_nulo == 0){
							printf("\n\n\t\t Não existem voos registrados");
							sleep(2);
							system("cls");
							break;
						}
						relatorio_voos();
						system("cls");
						break;
					
				}
				break;
					
			case 2:		//Passageiros
				
				switch (escolha){
					case 1:
						
						inclusao_passageiro();
						system("cls");
						break;	
						
					case 2:
						
						if(aux_passageiro_nulo == aux_passageiro_exclusao){
							printf("\n\n\t\t Não existem passageiros registrados");
							sleep(2);
						}
						else{
							alterar_passageiro();
						}
						system("cls");
						break;
						
					case 3:
						
						if(aux_passageiro_nulo == aux_passageiro_exclusao){
							printf("\n\n\t\t Não existem passageiros registrados");
							sleep(2);
						}
						else{
							exclusao_passageiro();
							sleep(2);
						}
						system("cls");
						break;
					
					case 4:
						
						if(aux_passageiro_nulo == aux_passageiro_exclusao){
							printf("\n\n\t\t Não existem passageiros registrados");
							sleep(2);
						}
						else{
							consulta_passageiro();
							sleep(5);
						}
						system("cls");
						break;
					
					case 5:
						if(aux_passageiro_nulo == 0){
							printf("\n\n\t\t Não existem passsageiros registrados");
							sleep(2);
							system("cls");
							break;
						}
						relatorio_passageiro();
						system("cls");
						break;
						
				}
				break;
				
			case 3:		//Passagens
				
				switch (escolha){
					
					case 1:
						
						if(aux_voo_nulo == aux_voo_exclusao){
							
							printf("\n\n\t\t Não existem voos registrados");
							sleep(2);
							
						}
						else if(aux_passageiro_nulo == aux_passageiro_exclusao){
							
							printf("\n\n\t\t Não existem passageiros registrados");
							sleep(2);
							
						}
						else{
							
							inclusao_passagem();
						}
						system("cls");
						break;
						
					case 2:
						
						if(aux_voo_nulo == aux_voo_exclusao){
							
							printf("\n\n\t\t Não existem voos registrados");
							sleep(2);
							
						}
						else if(aux_passageiro_nulo == aux_passageiro_exclusao){
							
							printf("\n\n\t\t Não existem passageiros registrados");
							sleep(2);
							
						}
						else if(aux_passagem_nulo == aux_passagem_exclusao){
							
							printf("\n\n\t\t Não existem passagens registradas");
							sleep(2);
							
						}
						else{
							
							alterar_passagem();
							
						}
						system("cls");
						break;
						
					case 3:
						
						if(aux_voo_nulo == aux_voo_exclusao){
							
							printf("\n\n\t\t Não existem voos registrados");
							sleep(2);
							
						}
						else if(aux_passageiro_nulo == aux_passageiro_exclusao){
							
							printf("\n\n\t\t Não existem passageiros registrados");
							sleep(2);
							
						}
						else if(aux_passagem_nulo == aux_passagem_exclusao){
							
							printf("\n\n\t\t Não existem passagens registradas");
							sleep(2);
							
						}
						else{
							
							exclusao_passagem();
							sleep(2);
							
						}
						system("cls");
						break;
					
					case 4:
					
						if(aux_voo_nulo == aux_voo_exclusao){
							
							printf("\n\n\t\t Não existem voos registrados");
							sleep(2);
							
						}
						else if(aux_passageiro_nulo == aux_passageiro_exclusao){
							
							printf("\n\n\t\t Não existem passageiros registrados");
							sleep(2);
							
						}
						else if(aux_passagem_nulo == aux_passagem_exclusao){
							
							printf("\n\n\t\t Não existem passagens registradas");
							sleep(2);
							
						}
						else{
							
							consulta_passagem();
							sleep(5);
							
						}
						system("cls");
						break;	
						
					case 5:
						
						if(aux_voo_nulo == aux_voo_exclusao){
							
							printf("\n\n\t\t Não existem voos registrados");
							sleep(2);
							
						}
						else if(aux_passageiro_nulo == aux_passageiro_exclusao){
							
							printf("\n\n\t\t Não existem passageiros registrados");
							sleep(2);
							
						}
						else if(aux_passagem_nulo == aux_passagem_exclusao){
							
							printf("\n\n\t\t Não existem passagens registradas");
							sleep(2);
							
						}
						else{
							
							relatorio_passagem();
							sleep(5);
							
						}
						system("cls");
						break;	
				}
				break;
				
		}
		
	}while(escolha!=6); 	//Opção para retornar ao menu, localizado na main()
		main();
}

/*
Objetivo: - Fazer a inclusão dos voos
Entrada: -	Dados do voo
Retorno: -	Preenchimento na variavel global com os dados
*/
void inclusao_voo(){
	
	int i, j, aux = 0;
	int isLetter = 0;
	char dia[3] = "", mes[3] = "", ano[5] = "";
	char hora[3] = "", min[3] = "";
	i = aux_voo_nulo;
	
/* 	
	Aqui, aux_voo_nulo diz quantos voos foram cadastrados, e aux_voo_exclusao diz quantos voos foram cancelados.
 	Assim, a diferença entre eles (aux_voo_nulo - aux_voo_exclusao) é o número de voos confirmados, ou seja,
 	que de fato ocorrerão, não deixando passar do limite de forma nenhuma.
*/
	if((aux_voo_nulo - aux_voo_exclusao) > LIMITE_VOO){
		printf("\n\n\t\t Limite de voos atingido \2");
		return; 
	}
	
	//Inserção de dados
	printf("\n\n\t\t Insira o número da Aeronave: ");
	scanf("%d%*c", &Voo_Global[i].Numero_Aeronave);
	
	//Condicionamento de entrada de dados do Número da Aeronave, tendo que ser positiva
	while(Voo_Global[i].Numero_Aeronave < 0){							
	
		printf("\n\n\t\t Número de Aeronave inserido inválido.");
		printf("\n\n\t\t Insira novamente: ");
		scanf("%d%*c", &Voo_Global[i].Numero_Aeronave);
	
	}
	
	//Inserção de dados
	printf("\n\n\t\t Insira o nome da Empresa: ");
	gets(Voo_Global[i].Empresa);
	
	//Inserção de dados
	printf("\n\n\t\t Insira a Origem do voo: ");
	
	//Condicionamento de entrada de dados da Origem, tendo que ser uma string sem números
	isLetter = 0;
	while(isLetter == 0){
		
		isLetter = 1;
		gets(Voo_Global[i].Origem);
		j = 0;
		while(j<strlen(Voo_Global[i].Origem) && isLetter == 1){
  			if(Voo_Global[i].Origem[j] <= '0' || Voo_Global[i].Origem[j] >= '9'){
  				
  				isLetter = 1;
  				
			  }	
  			else{
  		
  				isLetter = 0;
  		
		 	 }
		  	
  			j++;
  		
		}
		
		if(isLetter == 0){
			printf("\n\n\t\t Origem do voo inválida.");
			printf("\n\n\t\t Insira novamente: ");
		}	
	}
	
	//Inserção de dados
	printf("\n\n\t\t Insira o destino do voo: ");
	
	//Condicionamento de entrada de dados do Destino, tendo que ser uma string sem números
	isLetter = 0;
	while(isLetter == 0){
		
		isLetter = 1;
		gets(Voo_Global[i].Destino);
		j = 0;
		while(j<strlen(Voo_Global[i].Destino) && isLetter == 1){
  			if(Voo_Global[i].Destino[j] <= '0' || Voo_Global[i].Destino[j] >= '9'){
  				
  				isLetter = 1;
  				
			  }	
  			else{
  		
  				isLetter = 0;
  		
		 	 }
		  	
  			j++;
  		
		}
		
		if(isLetter == 0){
			printf("\n\n\t\t Destino do voo inválida.");
			printf("\n\n\t\t Insira novamente: ");
		}	
	}
	
	//Inserção de dados
	printf("\n\n\t\t Insira a data do voo: ");
	
	//Condicionamento de entrada de dados da Data, formatando o formato para XX/XX/XXXX
	while(aux < 2){
		
		gets(Voo_Global[i].Data);
		
		for(j=0; j < strlen(Voo_Global[i].Data); j++){
	
			if(j == 2 || j == 5){
				
				if(Voo_Global[i].Data[j] == '/'){
					
					aux ++;
					
				}
				else{
					
					aux = 0;
					
				}	
			}	
		}
		
		if(aux < 2){
			
			printf("\n\n\t\t Formato de data inválido.");
			printf("\n\n\t\t Insira novamente (xx/xx/xxxx): ");
			
		}		
	}
	
	//Condicionamento de entrada de dados da Data, formatando para ser uma string com apenas números
	aux = 1;
	while(aux == 1){
		
		aux = 0;
		if(Voo_Global[i].Data[0] < '0' || Voo_Global[i].Data[0] > '9' ||
		Voo_Global[i].Data[1] < '0' || Voo_Global[i].Data[1] > '9' ||
		Voo_Global[i].Data[3] < '0' || Voo_Global[i].Data[3] > '9' ||
		Voo_Global[i].Data[4] < '0' || Voo_Global[i].Data[4] > '9' ||
		Voo_Global[i].Data[6] < '0' || Voo_Global[i].Data[6] > '9' ||
		Voo_Global[i].Data[7] < '0' || Voo_Global[i].Data[7] > '9' ||
		Voo_Global[i].Data[8] < '0' || Voo_Global[i].Data[8] > '9' ||
		Voo_Global[i].Data[9] < '0' || Voo_Global[i].Data[9] > '9'){
		
			printf("\n\n\t\t Formato de data inválido.");
			printf("\n\n\t\t Insira novamente (xx/xx/xxxx): ");
			gets(Voo_Global[i].Data);
			aux = 1;	
		
		}
	}
	
	//Condicionamento de entrada de dados da Data, limitando para datas reais
	while(aux == 0){
		
		aux = 1;
		dia[0] = Voo_Global[i].Data[0];
		dia[1] = Voo_Global[i].Data[1];
		mes[0] = Voo_Global[i].Data[3];
		mes[1] = Voo_Global[i].Data[4];
		ano[0] = Voo_Global[i].Data[6];
		ano[1] = Voo_Global[i].Data[7];
		ano[2] = Voo_Global[i].Data[8];
		ano[3] = Voo_Global[i].Data[9];
		
		if (strcmp(dia, "31") > 0 || strcmp(dia, "0") < 0 ||
		strcmp(mes, "12") > 0 || strcmp(mes, "0") < 0 ||
		strcmp(ano, "9999") > 0 || strcmp(ano, "2021") < 0){
		
			printf("\n\n\t\t Os valores ultrapassaram o limite.");
			printf("\n\n\t\t Formato de data inválido.");
			printf("\n\n\t\t Insira novamente: ");
			gets(Voo_Global[i].Data);
			aux = 0;
			
		}
	}
	
	//Inserção de dados
	printf("\n\n\t\t Insira o horário do voo: ");
	
	//Condicionamento de entrada de dados do Horario, formatando o formato para XX:XX
	aux = 0;
	while(aux == 0){
		
		gets(Voo_Global[i].Horario);
		
		for(j=0; j < strlen(Voo_Global[i].Horario); j++){
			
			if(j == 2){
				
				if(Voo_Global[i].Horario[j] == ':'){
					
					aux = 1;
					
				}
				else{
					
					aux = 0;
					
				}	
			}	
		}
		
		if(aux == 0){
			
			printf("\n\n\t\t Formato de horário inválido.");
			printf("\n\n\t\t Insira novamente (xx:xx): ");
			
		}	
	}
	
	//Condicionamento de entrada de dados do Horario, formatando para ser uma string com apenas números
	while(aux == 1){
		
		aux = 0;
		if(Voo_Global[i].Horario[0] < '0' || Voo_Global[i].Horario[0] > '9' ||
		Voo_Global[i].Horario[1] < '0' || Voo_Global[i].Horario[1] > '9' ||
		Voo_Global[i].Horario[3] < '0' || Voo_Global[i].Horario[3] > '9' ||
		Voo_Global[i].Horario[4] < '0' || Voo_Global[i].Horario[4] > '9'){
		
			printf("\n\n\t\t Formato de Horário inválido.");
			printf("\n\n\t\t Insira novamente (xx:xx): ");
			gets(Voo_Global[i].Horario);
			aux = 1;	
		
		}
	}
	
	//Condicionamento de entrada de dados do Horario, limitando para datas reais, dentro do sistema 24 horas
	while(aux == 0){
		
		aux = 1;
		hora[0] = Voo_Global[i].Horario[0];
		hora[1] = Voo_Global[i].Horario[1];
		min[0] = Voo_Global[i].Horario[3];
		min[1] = Voo_Global[i].Horario[4];
		
		if (strcmp(hora, "24") > 0 || strcmp(hora, "0") < 0 ||
		strcmp(min, "59") > 0 || strcmp(min, "0") < 0){
		
			printf("\n\n\t\t Os valores ultrapassaram o limite.");
			printf("\n\n\t\t Formato de hora inválido.");
			printf("\n\n\t\t Insira novamente: ");
			gets(Voo_Global[i].Horario);
			aux = 0;
			
		}
	}
	
	//Inserção de dados
	printf("\n\n\t\t Insira a quantidade de passageiros do voo: ");
	scanf("%d", &Voo_Global[i].Quantidade_Passageiros);
	
	//Condicionamento de entrada de dados do Número de Passageiros, tendo que ser positiva
	while(Voo_Global[i].Quantidade_Passageiros < 0){							
	
		printf("\n\n\t\t Número de quantidade de passageiros inserido inválido.");
		printf("\n\n\t\t Insira novamente: ");
		scanf("%d%*c", &Voo_Global[i].Quantidade_Passageiros);
	
	}
	
	//Chama o identificador deste voo para ser um número uma unidade acima da sua posição no vetor global que armazena os voos (nossa convenção)
	Voo_Global[i].Identificador = i + 1;
	
	//Atribui o valor 0 ao nulo desse novo voo, para que ele não seja considerado como um voo nulo
	Voo_Global[i].nulo = 0;
	
	//Incrementa para poder registrar o numero de voos totais cadastrados
	aux_voo_nulo++;
	
}

/*
Objetivo: - Fazer a alteração dos dados de algum voo previamente inserido
Entrada: -	Voo a ser alterado
Retorno: - Repreenchimento dos dados na variável
*/
void alterar_voo(){
	
	int alterar_iden, i;
	
	printf("\n\n\t\t Voos disponíveis:\n");	
	
//Imprime uma breve informação de cada voo disponível para o operador poder escolher qual prefere alterar as informações.
	
	for (i=0; i < aux_voo_nulo; i++){ 											//Percorrerá todos os voos do vetor global que os armazena.
		if (Voo_Global[i].nulo == 0) {											// Apenas voos que não tem sua flag "nulo" == 1. Ou seja, voos nao anulados.
			printf("\n\n\t\t Identificador número: %d",Voo_Global[i].Identificador);
			printf("\n\n\t\t Empresa: %s",Voo_Global[i].Empresa);
			printf("\n\n\t\t Data: %s",Voo_Global[i].Data);
			printf("\n\n\t\t Horário: %s",Voo_Global[i].Horario);
			printf("\n\n");
		}
		else if  (Voo_Global[i].nulo == 1) {									//Voos considerados anulados não seram imprimidos
			printf("");
		}
	}
	
	//Escolha do voo a ser alterado
	printf("\n\n\t\t Escreva o identificador do voo a ser alterado: ");   
	scanf("%d", &alterar_iden);
	
	system("cls");
	
	printf("\n\n\t\t ***** Alterando informações do voo %d *****", alterar_iden);
	
	sleep(2);
	
//Inicio da alteração dos dados
	printf("\n\n\t\t Insira o número da Aeronave: ");
	scanf("%d%*c", &Voo_Global[alterar_iden - 1].Numero_Aeronave);
	
	printf("\n\n\t\t Insira o nome da Empresa: ");
	gets(Voo_Global[alterar_iden - 1].Empresa);
	
	printf("\n\n\t\t Insira a Origem do voo: ");
	gets(Voo_Global[alterar_iden - 1].Origem);
	
	printf("\n\n\t\t Insira o destino do voo: ");
	gets(Voo_Global[alterar_iden - 1].Destino);
	
	printf("\n\n\t\t Insira a data do voo: ");
	gets(Voo_Global[alterar_iden - 1].Data);
	
	printf("\n\n\t\t Insira o horário do voo: ");
	gets(Voo_Global[alterar_iden - 1].Horario);
	
	printf("\n\n\t\t Insira a quantidade de passageiros do voo: ");
	scanf("%d", &Voo_Global[alterar_iden - 1]);
	
	Voo_Global[alterar_iden - 1].nulo = 0;
	
	printf("\n\n");
//Final da alteração dos dados
}

/*
Objetivo: - Fazer a exclusão de algum voo previamente inserido
Entrada: -	Voo a ser excluido 
Retorno: -	Anulamento do voo
*/
void exclusao_voo(){
	
	int cancelar_iden, i, confirmar_exclusao;
	
	printf("\n\n\t\t Voos disponíveis:\n");

//Imprime uma breve informação de cada voo disponível para o operador poder escolher qual prefere alterar as informações.
	
	for (i=0; i < aux_voo_nulo; i++){							//Percorrerá todos os voos do vetor global que os armazena.
		if (Voo_Global[i].nulo == 0) {							// Apenas voos que não tem sua flag "nulo" == 1. Ou seja, voos nao anulados.
		
			printf("\n\n\t\t Identificador número: %d",Voo_Global[i].Identificador);
			printf("\n\n\t\t Empresa: %s",Voo_Global[i].Empresa);
			printf("\n\n\t\t Data: %s",Voo_Global[i].Data);
			printf("\n\n\t\t Horário: %s",Voo_Global[i].Horario);
			printf("\n\n");
			
		}
		else if  (Voo_Global[i].nulo == 1) {					//Voos considerados anulados não seram imprimidos
			printf("");
		}	
	}
	
	//Escolha do voo a ser cancelado
	printf("\n\n\t\t Escreva o identificador do voo a ser cancelado: ");
	scanf("%d", &cancelar_iden);
	
	system("cls");
	
	//Condição onde um voo não pode ser apagado se tiver ao menos uma passagem confirmada para ele
	for(i=0; i < aux_passagem_nulo; i++){
		if(Voo_Global[cancelar_iden - 1].Identificador == Passagem_Global[i].Identificador_Voo && Passagem_Global[i].nulo == 0){
			
			printf("\n\n\t\t Impossível cancelar esse voo.");
			printf("\n\n\t\t Passagens cadastradas neste voo.");
			sleep(2);
			system("cls");
			sub_menu(1);
			
		}
	}
	
	//Confirmação de exclusão	
	printf("\n\n\t\t Você tem certeza que quer cancelar este voo? (1 para Sim e 2 para Não): ");
	scanf("%d", &confirmar_exclusao);
	
	if (confirmar_exclusao == 1){
		
		//Confirmado a exclusão, altera o argumento nulo para verdadeiro, ou seja, 1 e acresce 1 a variavel que conta os voos excluidos.
		Voo_Global[(cancelar_iden - 1)].nulo = 1;
		printf("\n\n\t\t Voo de identificador %d anulado com sucesso.", cancelar_iden);
		aux_voo_exclusao++;
		    
		
	} 
	else if (confirmar_exclusao != 1) {
		
		//Não confirmado a exclusão, retorna ao sub menu
		printf("\n\n\t\t Ok, voltando ao menu...");
			
	}
}

/*
Objetivo: - Fazer a consulta dos dados de algum voo previamente inserido
Entrada: -	Voo a ser consultado
Retorno: - Todos os dados do voo
*/
void consulta_voo(){
	
	int consultar_iden, i;
	
	printf("\n\n\t\t Voos disponíveis:\n");

//Imprime uma breve informação de cada voo disponível para o operador poder escolher qual prefere alterar as informações.	
	for (i=0; i < aux_voo_nulo; i++){						//Percorrerá todos os voos do vetor global que os armazena.
		if (Voo_Global[i].nulo == 0) {						//Apenas voos que não tem sua flag "nulo" == 1. Ou seja, voos nao anulados.
			
			printf("\n\n\t\t Identificador número: %d",Voo_Global[i].Identificador);
			printf("\n\n\t\t Empresa: %s",Voo_Global[i].Empresa);
			printf("\n\n\t\t Data: %s",Voo_Global[i].Data);
			printf("\n\n\t\t Horário: %s",Voo_Global[i].Horario);
			printf("\n\n");
			
		}
		else if  (Voo_Global[i].nulo == 1) {				//Voos considerados anulados não seram imprimidos	
			printf("");
		}	
	}
	
	//Escolha do voo a ser consultado
	printf("\n\n\t\t Escreva o identificador do voo a ser consultado: ");
	scanf("%d", &consultar_iden);
	
	system("cls");
	
	//Impressão dos dados do voo escolhido 
	printf("\n\n\t\t Essas são as informações do voo escolhido:");
		
		printf("\n\n\t\t Identificador número: %d", Voo_Global[ (consultar_iden - 1) ].Identificador);
		printf("\n\n\t\t Aeronave de número: %d", Voo_Global[ (consultar_iden - 1) ].Numero_Aeronave);
		printf("\n\n\t\t Nome da Empresa: %s", Voo_Global[ (consultar_iden - 1) ].Empresa);	
		printf("\n\n\t\t Origem do voo: %s", Voo_Global[ (consultar_iden - 1) ].Origem);
		printf("\n\n\t\t Destino do voo: %s", Voo_Global[ (consultar_iden - 1) ].Destino);		
		printf("\n\n\t\t Data do voo: %s", Voo_Global[ (consultar_iden - 1) ].Data);
		printf("\n\n\t\t Horario do voo: %s", Voo_Global[ (consultar_iden - 1) ].Horario);
		printf("\n\n\t\t Quantidade de pessoas no voo: %d", Voo_Global[ (consultar_iden - 1) ].Quantidade_Passageiros);
		printf("\n\n");

}

/*
Objetivo: - Gerar o relatório de todos os voos inseridos
Entrada: -	Dados de todos os voos inseridos
Retorno: -  Voos confirmados e voos excluidos
*/
void relatorio_voos(){
	
	int i;
	
	printf("\n\n\t\t ***** Registros cadastrados pelo usuário *****");
	printf("\n\n");
	
	printf("\n\n\t\t Os seguintes voos foram confirmados: ");
	printf("\n\n");
	
	for(i=0; i < aux_voo_nulo; i++){		//Percorrerá todos os voos do vetor global que os armazena.
		if(Voo_Global[i].nulo == 0){		//Apenas voos que não tem sua flag "nulo" == 1. Ou seja, voos nao anulados.
		
		//Impressão dos dados de todos os voos confirmados
			printf("\n\n\t\t Identificador número: %d",Voo_Global[i].Identificador);
			printf("\n\n\t\t Aeronave de número: %d",Voo_Global[i].Numero_Aeronave);
			printf("\n\n\t\t Nome da Empresa: %s",Voo_Global[i].Empresa);	
			printf("\n\n\t\t Origem do voo: %s",Voo_Global[i].Origem);
			printf("\n\n\t\t Destino do voo: %s",Voo_Global[i].Destino);		
			printf("\n\n\t\t Data do voo: %s",Voo_Global[i].Data);
			printf("\n\n\t\t Horario do voo: %s",Voo_Global[i].Horario);
			printf("\n\n\t\t Quantidade de pessoas no voo: %d",Voo_Global[i].Quantidade_Passageiros);
			printf("\n\n");
			sleep(1);
				
		}
	}
	
	//Caso a quantidade de voos cadastrados forem iguais aos excluidos, nenhum foi confirmado
	if(aux_voo_nulo == aux_voo_exclusao){
		
		printf("\n\n\t\t Nenhum voo foi confirmado.");
		sleep(1);
			
	}
	
	printf("\n\n");
	printf("\n\n\t\t Atenção! Os seguintes voos foram cancelados: ");
	printf("\n\n");
	
	for(i=0; i < aux_voo_nulo; i++){			//Percorrerá todos os voos do vetor global que os armazena.	
		if(Voo_Global[i].nulo == 1){			//Apenas voos que tem sua flag "nulo" == 1. Ou seja, voos anulados.
			
		//Impressão dos dados de todos os voos cancelados	
			printf("\n\n\t\t Identificador número: %d",Voo_Global[i].Identificador);
			printf("\n\n\t\t Aeronave de número: %d",Voo_Global[i].Numero_Aeronave);
			printf("\n\n\t\t Nome da Empresa: %s",Voo_Global[i].Empresa);	
			printf("\n\n\t\t Origem do voo: %s",Voo_Global[i].Origem);
			printf("\n\n\t\t Destino do voo: %s",Voo_Global[i].Destino);		
			printf("\n\n\t\t Data do voo: %s",Voo_Global[i].Data);
			printf("\n\n\t\t Horario do voo: %s",Voo_Global[i].Horario);
			printf("\n\n\t\t Quantidade de pessoas no voo: %d",Voo_Global[i].Quantidade_Passageiros);
			printf("\n\n");
			sleep(1);
			
		}			
	}
	
	//Caso a quantidade de voos excluidos for 0, nenhum foi cancelado
	if(aux_voo_exclusao == 0){
		
		printf("\n\n\t\t Nenhum voo foi cancelado.");
		sleep(1);
			
	}
	
	//Proporcionalidade do delay na interface de relatorios com base no tanto que foram cadastrados
	sleep(aux_voo_nulo*5);
	
}

/*
Objetivo: - Fazer a inclusão dos passageiros
Entrada: -	Dados do passageiro
Retorno: - Preenchimento na variavel global com os dados
*/
void inclusao_passageiro(){
	
	int i, j, aux = 0;
	int isLetter = 0;
	i = aux_passageiro_nulo;

/* 
	Aqui, aux_passageiro_nulo diz quantos passageiros foram cadastrados, e aux_passageiro_exclusao diz 
 	quantos passageiros foram cancelados. Assim, a diferença entre eles (aux_passageiro_nulo - aux_passageiro_exclusao)
 	é o número de passageiros confirmados, ou seja, que de fato ocorrerão, não deixando passar do limite de forma nenhuma.
*/	
	if((aux_passageiro_nulo - aux_passageiro_exclusao) > LIMITE_PASSAGEIRO){
		printf("\n\n\t\t Limite de passageiros foi atingido \2");
		return; 
	}
	
	//Inserção de dados
	printf("\n\n\t\t Insira o nome do passageiro: ");
	
	//Condicionamento de entrada de dados do Nome do Passageiro, tendo que ser uma string sem números
	isLetter = 0;
	while(isLetter == 0){
		
		isLetter = 1;
		gets(Passageiro_Global[i].Nome);
		j = 0;
		while(j<strlen(Passageiro_Global[i].Nome) && isLetter == 1){
  			if(Passageiro_Global[i].Nome[j] <= '0' || Passageiro_Global[i].Nome[j] >= '9'){
  				
  				isLetter = 1;
  				
			  }	
  			else{
  		
  				isLetter = 0;
  		
		 	 }
		  	
  			j++;
  		
		}
		
		if(isLetter == 0){
			printf("\n\n\t\t Nome do passageiro inválido.");
			printf("\n\n\t\t Insira novamente: ");
		}	
	}
	
	//Inserção de dados
	printf("\n\n\t\t Insira a identidade do passageiro: ");
	gets(Passageiro_Global[i].Identidade);
	
	//Inserção de dados
	printf("\n\n\t\t Insira o CPF do passageiro: ");
	
	//Condicionamento de entrada de dados do CPF, formatando o formato para XXX.XXX.XXX-XX
	while(aux < 3){
		
		gets(Passageiro_Global[i].CPF);
		
		for(j=0; j < strlen(Passageiro_Global[i].CPF); j++){
	
			if(j == 3 || j == 7 || j == 11){
				
				if(Passageiro_Global[i].CPF[j] == '.'){
					
					aux++;
					
				}
				else if(Passageiro_Global[i].CPF[j] == '-'){
					
					aux++;
					
				}
				else{
					
					aux = 0;
					
				}	
			}	
		}
		
		if(aux < 3){
			
			printf("\n\n\t\t Formato de CPF inválido.");
			printf("\n\n\t\t Insira novamente (xxx.xxx.xxx-xx): ");
			
		}		
	}
	
	//Condicionamento de entrada de dados do CPF, formatando para ser uma string com apenas números
	aux = 1;
	while(aux == 1){
		
		aux = 0;
		if(Passageiro_Global[i].CPF[0] < '0' || Passageiro_Global[i].CPF[0] > '9' ||
		Passageiro_Global[i].CPF[1] < '0' || Passageiro_Global[i].CPF[1] > '9' ||
		Passageiro_Global[i].CPF[2] < '0' || Passageiro_Global[i].CPF[2] > '9' ||
		Passageiro_Global[i].CPF[4] < '0' || Passageiro_Global[i].CPF[4] > '9' ||
		Passageiro_Global[i].CPF[5] < '0' || Passageiro_Global[i].CPF[5] > '9' ||
		Passageiro_Global[i].CPF[6] < '0' || Passageiro_Global[i].CPF[6] > '9' ||
		Passageiro_Global[i].CPF[8] < '0' || Passageiro_Global[i].CPF[8] > '9' ||
		Passageiro_Global[i].CPF[9] < '0' || Passageiro_Global[i].CPF[9] > '9' ||
		Passageiro_Global[i].CPF[10] < '0' || Passageiro_Global[i].CPF[10] > '9' ||
		Passageiro_Global[i].CPF[12] < '0' || Passageiro_Global[i].CPF[12] > '9' ||
		Passageiro_Global[i].CPF[13] < '0' || Passageiro_Global[i].CPF[13] > '9'){
		
			printf("\n\n\t\t Formato de CPF inválido.");
			printf("\n\n\t\t Insira novamente (xxx.xxx.xxx-xx): ");
			gets(Passageiro_Global[i].CPF);
			aux = 1;	
		
		}
	}
	
	//Inserção de dados
	printf("\n\n\t\t Insira o endereço do passageiro: ");
	gets(Passageiro_Global[i].Endereco);
	
	//Inserção de dados
	printf("\n\n\t\t Insira o telefone do passageiro: ");
	
	//Condicionamento de entrada de dados do Telefone, formatando o formato para (XX) XXXXX-XXXX
	while(aux < 4){
		
		gets(Passageiro_Global[i].Telefone);
		
		for(j=0; j < strlen(Passageiro_Global[i].Telefone); j++){
	
			if(j == 0 || j == 3 || j == 4 || j == 10){
				
				if(Passageiro_Global[i].Telefone[j] == '('){
					
					aux++;
					
				}
				else if(Passageiro_Global[i].Telefone[j] == '-'){
					
					aux++;
					
				}
				else if(Passageiro_Global[i].Telefone[j] == ')'){
					
					aux++;
					
				}
				else if(Passageiro_Global[i].Telefone[j] == ' '){
					
					aux++;
					
				}
				else{
					
					aux = 0;
					
				}	
			}	
		}
		
		if(aux < 4){

			printf("\n\n\t\t Formato de Telefone inválido.");
			printf("\n\n\t\t Insira novamente ((xx) xxxxx-xxxx): ");
			
		}		
	}
	
	//Condicionamento de entrada de dados do Telefone, formatando para ser uma string com apenas números
	aux = 1;
	while(aux == 1){
		
		aux = 0;
		if(Passageiro_Global[i].Telefone[1] < '0' || Passageiro_Global[i].Telefone[1] > '9' ||
		Passageiro_Global[i].Telefone[2] < '0' || Passageiro_Global[i].Telefone[2] > '9' ||
		Passageiro_Global[i].Telefone[5] < '0' || Passageiro_Global[i].Telefone[5] > '9' ||
		Passageiro_Global[i].Telefone[6] < '0' || Passageiro_Global[i].Telefone[6] > '9' ||
		Passageiro_Global[i].Telefone[7] < '0' || Passageiro_Global[i].Telefone[7] > '9' ||
		Passageiro_Global[i].Telefone[8] < '0' || Passageiro_Global[i].Telefone[8] > '9' ||
		Passageiro_Global[i].Telefone[9] < '0' || Passageiro_Global[i].Telefone[9] > '9' ||
		Passageiro_Global[i].Telefone[11] < '0' || Passageiro_Global[i].Telefone[11] > '9' ||
		Passageiro_Global[i].Telefone[12] < '0' || Passageiro_Global[i].Telefone[12] > '9' ||
		Passageiro_Global[i].Telefone[13] < '0' || Passageiro_Global[i].Telefone[13] > '9' ||
		Passageiro_Global[i].Telefone[14] < '0' || Passageiro_Global[i].Telefone[14] > '9'){
		
			printf("\n\n\t\t Formato de Telefone inválido.");
			printf("\n\n\t\t Insira novamente ((xx) xxxxx-xxxx): ");
			gets(Passageiro_Global[i].Telefone);
			aux = 1;	
		
		}
	}
	
	//Inserção de dados
	printf("\n\n\t\t Insira o sexo do passageiro: ");
	
	//Condicionamento de entrada de dados do Sexo, podendo ser ou "M" ou "F"
	while(aux == 0){
		
		scanf("%c", &Passageiro_Global[i].Sexo);
	
		if(Passageiro_Global[i].Sexo == 'M' || Passageiro_Global[i].Sexo == 'F'){
				
			aux = 1;
				
		}
		else{
					
			aux = 0;
			printf("\n\n\t\t Formato de Sexo inválido.");
			printf("\n\n\t\t Insira novamente (M ou F): ");
					
		}				
	}
	
	//Chama o identificador deste passageiro para ser um número uma unidade acima da sua posição no vetor global que armazena os passageiros (nossa convenção)
	Passageiro_Global[i].Identificador = i + 1;
	
	//Atribui o valor 0 ao nulo desse novo passageiro, para que ele não seja considerado como um passageiro nulo
	Passageiro_Global[i].nulo = 0;
	
	//Incrementa para poder registrar o numero de passageiros totais cadastrados
	aux_passageiro_nulo++;
	
}

/*
Objetivo: - Fazer a alteração dos dados de algum passageiro previamente inserido
Entrada: -	Passageiro a ser alterado
Retorno: -	Repreenchimento dos dados na variável
*/
void alterar_passageiro(){
	
	int alterar_iden, i;
	
	printf("\n\n\t\t Passageiros disponíveis:\n");	

//Imprime uma breve informação de cada passageiro disponível para o operador poder escolher qual prefere alterar as informações

	for (i=0; i < aux_passageiro_nulo; i++){				//Percorrerá todos os passageiros do vetor global que os armazena
		if (Passageiro_Global[i].nulo == 0) {				//Apenas passageiros que não tem sua flag "nulo" == 1. Ou seja, passageiros nao anulados
			
			printf("\n\n\t\t Identificador número: %d",Passageiro_Global[i].Identificador);
			printf("\n\n\t\t Nome: %s",Passageiro_Global[i].Nome);
			printf("\n\n\t\t CPF: %s",Passageiro_Global[i].CPF);
			printf("\n\n\t\t Telefone: %s",Passageiro_Global[i].Telefone);
			printf("\n\n");
			
		}
		else if  (Passageiro_Global[i].nulo == 1) {			//Passageiros considerados anulados não seram imprimidos
			printf("");
		}
	}
	
	//Escolha do passageiro a ser alterado
	printf("\n\n\t\t Escreva o identificador do passageiro a ser alterado: ");   
	scanf("%d%*c", &alterar_iden);
	
	system("cls");
	
	printf("\n\n\t\t ***** Alterando informações do passageiro %d *****", alterar_iden);
	
	sleep(2);

//Inicio da alteração dos dados	
	printf("\n\n\t\t Insira o nome do passageiro: ");
	gets(Passageiro_Global[alterar_iden - 1].Nome);
	
	printf("\n\n\t\t Insira a identidade do passageiro: ");
	gets(Passageiro_Global[alterar_iden - 1].Identidade);
	
	printf("\n\n\t\t Insira o CPF do passageiro: ");
	gets(Passageiro_Global[alterar_iden - 1].CPF);
	
	printf("\n\n\t\t Insira o endereço do passageiro: ");
	gets(Passageiro_Global[alterar_iden - 1].Endereco);
	
	printf("\n\n\t\t Insira o telefone do passageiro: ");
	gets(Passageiro_Global[alterar_iden - 1].Telefone);
	
	printf("\n\n\t\t Insira o sexo do passageiro: ");
	scanf("%c", &Passageiro_Global[alterar_iden - 1].Sexo);
	
	Passageiro_Global[alterar_iden - 1].nulo = 0;
	
	printf("\n\n");
//Final da alteração dos dados
}

/*
Objetivo: - Fazer a exclusão de algum passageiro previamente inserido
Entrada: -	Passageiro a ser excluido 
Retorno: -	Anulamento do passageiro
*/
void exclusao_passageiro(){
	
	int cancelar_iden, i, confirmar_exclusao;
	
	printf("\n\n\t\t Passageiros disponíveis:\n");	

//Imprime uma breve informação de cada passageiro disponível para o operador poder escolher qual prefere alterar as informações
	
	for (i=0; i < aux_passageiro_nulo; i++){					//Percorrerá todos os passageiros do vetor global que os armazena
		if (Passageiro_Global[i].nulo == 0) {					//Apenas passageiros que não tem sua flag "nulo" == 1. Ou seja, passageiros nao anulados
		
			printf("\n\n\t\t Identificador número: %d",Passageiro_Global[i].Identificador);
			printf("\n\n\t\t Nome: %s",Passageiro_Global[i].Nome);
			printf("\n\n\t\t CPF: %s",Passageiro_Global[i].CPF);
			printf("\n\n\t\t Telefone: %s",Passageiro_Global[i].Telefone);
			printf("\n\n");
		}
		else if  (Passageiro_Global[i].nulo == 1) {				//Passageiros considerados anulados não seram imprimidos
			printf("");
		}
	}
	
	//Escolha do passageiro a ser cancelado
	printf("\n\n\t\t Escreva o identificador do passageiro a ser cancelado: ");
	scanf("%d", &cancelar_iden);
	
	system("cls");
	
	//Condição onde um passageiro não pode ser apagado se tiver ao menos uma passagem cadastrada e confirmada.
	for(i=0; i < aux_passagem_nulo; i++){
		if(Passageiro_Global[cancelar_iden - 1].Identificador == Passagem_Global[i].Identificador_Passageiro && Passagem_Global[i].nulo == 0){
			
			printf("\n\n\t\t Impossível excluir esse passageiro.");
			printf("\n\n\t\t Esse passageiro possui uma passagem cadastrada.");
			sleep(2);
			system("cls");
			sub_menu(2);
			
		}
	}  
	
	//Confirmação de exclusão	
	printf("\n\n\t\t Você tem certeza que quer cancelar este passageiro? (1 para Sim e 2 para Não): ");
	scanf("%d", &confirmar_exclusao);
	
	if (confirmar_exclusao == 1){
		
		//Confirmado a exclusão, altera o argumento nulo para verdadeiro, ou seja, 1 e acresce 1 a variavel que conta os passageiros excluidos.
		Passageiro_Global[(cancelar_iden - 1)].nulo = 1;
		printf("\n\n\t\t Passageiro de identificador %d anulado com sucesso.", cancelar_iden);
		aux_passageiro_exclusao++;
	
	} 
	else if (confirmar_exclusao != 1) {
		
		//Não confirmado a exclusão, retorna ao sub menu
		printf("\n\n\t\t Ok, voltando ao menu...");
			
	}	
}

/*
Objetivo: - Fazer a consulta dos dados de algum passageiro previamente inserido
Entrada: -	Passageiro a ser consultado
Retorno: - Todos os dados do passageiro
*/
void consulta_passageiro(){
	
	int consultar_iden, i;
	
	printf("\n\n\t\t Passageiros disponíveis:\n");	

//Imprime uma breve informação de cada passageiro disponível para o operador poder escolher qual prefere alterar as informações
	
	for (i=0; i < aux_passageiro_nulo; i++){					//Percorrerá todos os passageiros do vetor global que os armazena
		if (Passageiro_Global[i].nulo == 0) {					//Apenas passageiros que não tem sua flag "nulo" == 1. Ou seja, passageiros nao anulados
			
			printf("\n\n\t\t Identificador número: %d",Passageiro_Global[i].Identificador);
			printf("\n\n\t\t Nome: %s",Passageiro_Global[i].Nome);
			printf("\n\n\t\t CPF: %s",Passageiro_Global[i].CPF);
			printf("\n\n\t\t Telefone: %s",Passageiro_Global[i].Telefone);
			printf("\n\n");
			
		}
		else if  (Passageiro_Global[i].nulo == 1) {				//Passageiros considerados anulados não seram imprimidos
			printf("");
		}
	}
	
	//Escolha do passageiro a ser consultado
	printf("\n\n\t\t Escreva o identificador do passageiro a ser consultado: ");
	scanf("%d", &consultar_iden);
	
	system("cls");
	
	//Impressão dos dados do passageiro escolhido 
	printf("\n\n\t\t Essas são as informações do passageiro escolhido:");
		
		printf("\n\n\t\t Identificador número: %d", Passageiro_Global[ (consultar_iden - 1) ].Identificador);
		printf("\n\n\t\t Nome: %s", Passageiro_Global[ (consultar_iden - 1) ].Nome);
		printf("\n\n\t\t Identidade: %s", Passageiro_Global[ (consultar_iden - 1) ].Identidade);	
		printf("\n\n\t\t CPF: %s", Passageiro_Global[ (consultar_iden - 1) ].CPF);
		printf("\n\n\t\t Endereço: %s", Passageiro_Global[ (consultar_iden - 1) ].Endereco);		
		printf("\n\n\t\t Telefone: %s", Passageiro_Global[ (consultar_iden - 1) ].Telefone);
		printf("\n\n\t\t Sexo: %c", Passageiro_Global[ (consultar_iden - 1) ].Sexo);
		printf("\n\n");

}
	
/*
Objetivo: - Gerar o relatório de todos os passageiros inseridos
Entrada: -	Dados de todos os passageiros inseridos
Retorno: -  Passageiros confirmados e passageiros excluidos
*/
void relatorio_passageiro(){
	
	int i;
	
	printf("\n\n\t\t ***** Registros cadastrados pelo usuário *****");
	printf("\n\n");
	
	printf("\n\n\t\t Os seguintes passageiros foram confirmado: ");
	printf("\n\n");
	
	for(i=0; i < aux_passageiro_nulo; i++){				//Percorrerá todos os passageiros do vetor global que os armazena.
		if(Passageiro_Global[i].nulo == 0){				//Apenas passageiros que nao tem sua flag "nulo" == 1. Ou seja, passageiros nao anulados.
		
		//Impressão dos dados de todos os passageiros confirmados
			printf("\n\n\t\t Identificador número: %d", Passageiro_Global[i].Identificador);
			printf("\n\n\t\t Nome: %s", Passageiro_Global[i].Nome);
			printf("\n\n\t\t Identidade: %s", Passageiro_Global[i].Identidade);	
			printf("\n\n\t\t CPF: %s", Passageiro_Global[i].CPF);
			printf("\n\n\t\t Endereço: %s", Passageiro_Global[i].Endereco);		
			printf("\n\n\t\t Telefone: %s", Passageiro_Global[i].Telefone);
			printf("\n\n\t\t Sexo: %c", Passageiro_Global[i].Sexo);
			printf("\n\n");
			sleep(1);
				
		}
	}
	
	//Caso a quantidade de passageiros cadastrados forem iguais aos excluidos, nenhum foi confirmado
	if(aux_passageiro_nulo == aux_passageiro_exclusao){
		
		printf("\n\n\t\t Nenhum passageiro foi confirmado.");
		sleep(1);
			
	}
	
	printf("\n\n");
	printf("\n\n\t\t Atenção! Os seguintes passageiros foram excluidos: ");
	printf("\n\n");
	
	for(i=0; i < aux_passageiro_nulo; i++){				//Percorrerá todos os passageiros do vetor global que os armazena.
		if(Passageiro_Global[i].nulo == 1){				//Apenas passageiros que tem sua flag "nulo" == 1. Ou seja, passageiros anulados.
			
		//Impressão dos dados de todos os passageiros cancelados
			printf("\n\n\t\t Identificador número: %d", Passageiro_Global[i].Identificador);
			printf("\n\n\t\t Nome: %s", Passageiro_Global[i].Nome);
			printf("\n\n\t\t Identidade: %s", Passageiro_Global[i].Identidade);	
			printf("\n\n\t\t CPF: %s", Passageiro_Global[i].CPF);
			printf("\n\n\t\t Endereço: %s", Passageiro_Global[i].Endereco);		
			printf("\n\n\t\t Telefone: %s", Passageiro_Global[i].Telefone);
			printf("\n\n\t\t Sexo: %c", Passageiro_Global[i].Sexo);
			printf("\n\n");
			sleep(1);
			
		}			
	}
	
	//Caso a quantidade de passageiros excluidos for 0, nenhum foi cancelado
	if(aux_passageiro_exclusao == 0){
		
		printf("\n\n\t\t Nenhum passageiro foi excluído.");
		sleep(1);
			
	}
	
	//Proporcionalidade do delay na interface de relatorios com base no tanto que foram cadastrados
	sleep(aux_passageiro_nulo*5);

}

/*
Objetivo: - Fazer a inclusão das passagens
Entrada: -	Dados da passagem
Retorno: - Preenchimento na variavel global com os dados
*/
void inclusao_passagem(){
	
	int i, inclusao_iden, inclusao_iden_2, j, x;
	int aux = 0;
	char dia[3] = "", mes[3] = "", ano[5] = "";
	j = aux_passagem_nulo;

/*
	Aqui, aux_passagem_nulo diz quantas passagens foram cadastradss, e aux_passagem_exclusao diz quantas
 	passagens foram cancelados. Assim, a diferença entre eles (aux_passagem_nulo - aux_passagem_exclusao)
 	é o número de passagens confirmados, ou seja, que de fato ocorrerão, não deixando passar do limite de forma nenhuma.
*/
	if((aux_passagem_nulo - aux_passagem_exclusao) > LIMITE_PASSAGEM){
		printf("\n\n\t\t Limite de voos atingido \2");
		return; 
	}
	
	printf("\n\n\t\t Voos disponíveis:\n");	

//Aqui imprimiremos uma breve informação de cada voo disponível para o operador poder escolher em qual voo cadastrar aquela passagem	
	for (i=0; i < aux_voo_nulo; i++){
		if (Voo_Global[i].nulo == 0) {
			
			printf("\n\n\t\t Identificador número: %d",Voo_Global[i].Identificador);
			printf("\n\n\t\t Empresa: %s",Voo_Global[i].Empresa);
			printf("\n\n\t\t Data: %s",Voo_Global[i].Data);
			printf("\n\n\t\t Horário: %s",Voo_Global[i].Horario);
			printf("\n\n");
			
		}
		else if  (Voo_Global[i].nulo == 1) {
			printf("");
		}
	}
	
	//Escolha do voo que será cadastrado a passagem
	printf("\n\n\t\t Escreva o identificador do voo a ser comprado: ");   
	scanf("%d", &inclusao_iden);
	
	system("cls");
	
	printf("\n\n\t\t Passageiros disponíveis:\n");	

//Aqui imprimiremos uma breve informação de cada passageiro disponível para o operador poder escolher em qual passageiro cadastrar aquela passagem	
	for (i=0; i < aux_passageiro_nulo; i++){
		if (Passageiro_Global[i].nulo == 0) {
			
			printf("\n\n\t\t Identificador número: %d",Passageiro_Global[i].Identificador);
			printf("\n\n\t\t Nome: %s",Passageiro_Global[i].Nome);
			printf("\n\n\t\t CPF: %s",Passageiro_Global[i].CPF);
			printf("\n\n\t\t Telefone: %s",Passageiro_Global[i].Telefone);
			printf("\n\n");
			
		}
		else if  (Passageiro_Global[i].nulo == 1) {
			printf("");
		}
	}
	
	//Escolha do passageiro que será cadastrado a passagem
	printf("\n\n\t\t Escreva o identificador do passageiro que irá comprar: ");   
	scanf("%d", &inclusao_iden_2);
	
	system("cls");
	
	//Condição para que a mesma passagem não possa ser associada ao mesmo passageiro e voo
	for(i=0; i < aux_passagem_nulo; i++){
		if(Passageiro_Global[inclusao_iden_2 - 1].Identificador == Passagem_Global[i].Identificador_Passageiro && 
		Voo_Global[inclusao_iden - 1].Identificador == Passagem_Global[i].Identificador_Voo){
				
			printf("\n\n\t\t Passageiro já esta cadastrado neste voo.");
			sleep(2);
			system("cls");
			sub_menu(3); 
				
		}	
	}
	
	
	//Condição para que um mesmo passageiro não esteja em dois ou mais voos na mesma data e horário
	for(i=0; i < aux_passagem_nulo; i++){
		if(Passageiro_Global[inclusao_iden_2 - 1].Identificador == Passagem_Global[i].Identificador_Passageiro){
			if(strcmp(Voo_Global[i].Data, Voo_Global[inclusao_iden - 1].Data) == 0 &&
			strcmp(Voo_Global[i].Horario, Voo_Global[inclusao_iden - 1].Horario) == 0){
				
				printf("\n\n\t\t Passageiro já esta cadastrado em um voo neste horário e nesta data.");
				sleep(2);
				system("cls");
				sub_menu(3);
				
			}
		}
	}
	
	//Condição para que só possa cadastrar passagens até o limite daquele voo previamente escolhido
	if (aux_passagem[inclusao_iden - 1] < Voo_Global[inclusao_iden - 1].Quantidade_Passageiros){
		
		//Chama o identificador desta passagem para ser um número uma unidade acima da sua posição no vetor global que armazena as passagens (nossa convenção)
		Passagem_Global[inclusao_iden - 1].Numero = j + 1;
	
		//Associa o passageiro previamente selecionado com a passagem
		Passagem_Global[inclusao_iden - 1].Identificador_Passageiro = Passageiro_Global[inclusao_iden_2 - 1].Identificador;
		
		//Associa o voo previamente selecionado com a passagem
		Passagem_Global[inclusao_iden - 1].Identificador_Voo = Voo_Global[inclusao_iden - 1].Identificador;

		//Inserção de dados
		printf("\n\n\t\t Insira o número da Poltrona: ");	
		scanf("%d%*c", &Passagem_Global[inclusao_iden - 1].Numero_Poltrona);
		
		//Condicionamente de entrada de dados do Número da Poltrona, tendo que ser inferior a capacidade da aeronave
		while(Passagem_Global[inclusao_iden - 1].Numero_Poltrona > Voo_Global[inclusao_iden - 1].Quantidade_Passageiros){
			
			printf("\n\n\t\t Número da poltrona maior que o suportado no voo.");
			printf("\n\n\t\t Insira o número da Poltrona novamente: ");
			scanf("%d%*c", &Passagem_Global[inclusao_iden - 1].Numero_Poltrona);
			
		}
		
		//Condicionamento de entrada de dados do Número da Poltrona, tendo que ser positiva
		while (Passagem_Global[inclusao_iden - 1].Numero_Poltrona < 0 ){
			
			printf("\n\n\t\t Número da poltrona inválido.");
			printf("\n\n\t\t Insira novamente: ");
			scanf("%d%*c", &Passagem_Global[inclusao_iden - 1].Numero_Poltrona);
			
		}
		
		//Inserção de dados
		printf("\n\n\t\t Insira o valor da passagem: ");
		scanf("%f%*c", &Passagem_Global[inclusao_iden - 1].Valor);
		
		//Condicionamento de entrada de dados do Número da Poltrona, tendo que ser positiva
		while (Passagem_Global[inclusao_iden - 1].Valor < 0 ){
			
			printf("\n\n\t\t Número do valor da passagem inválido.");
			printf("\n\n\t\t Insira novamente: ");
			scanf("%f%*c", &Passagem_Global[inclusao_iden - 1].Valor);
			
		}
		
		//Inserção de dados
		printf("\n\n\t\t Insira a data da venda da passagem: ");
		
		//Condicionamento de entrada de dados da Data, formatando o formato para XX/XX/XXXX
		while(aux < 2){
		
			gets(Passagem_Global[inclusao_iden - 1].Data_Venda);
		
		for(x=0; x < strlen(Passagem_Global[inclusao_iden - 1].Data_Venda); x++){
	
			if(x == 2 || x == 5){
				
				if(Passagem_Global[inclusao_iden - 1].Data_Venda[x] == '/'){
					
					aux ++;
					
				}
				else{
					
					aux = 0;
					
				}	
			}	
		}
		
		if(aux < 2){
			
			printf("\n\n\t\t Formato de data inválido.");
			printf("\n\n\t\t Insira novamente (xx/xx/xxxx): ");
			
		}		
	}
		
		//Condicionamento de entrada de dados da Data, formatando para ser uma string com apenas números
		aux = 1;
		while(aux == 1){
		
			aux = 0;
			
			if(Passagem_Global[inclusao_iden - 1].Data_Venda[0] < '0' || Passagem_Global[inclusao_iden - 1].Data_Venda[0] > '9' ||
			Passagem_Global[inclusao_iden - 1].Data_Venda[1] < '0' || Passagem_Global[inclusao_iden - 1].Data_Venda[1] > '9' ||
			Passagem_Global[inclusao_iden - 1].Data_Venda[3] < '0' || Passagem_Global[inclusao_iden - 1].Data_Venda[3] > '9' ||
			Passagem_Global[inclusao_iden - 1].Data_Venda[4] < '0' || Passagem_Global[inclusao_iden - 1].Data_Venda[4] > '9' ||
			Passagem_Global[inclusao_iden - 1].Data_Venda[6] < '0' || Passagem_Global[inclusao_iden - 1].Data_Venda[6] > '9' ||
			Passagem_Global[inclusao_iden - 1].Data_Venda[7] < '0' || Passagem_Global[inclusao_iden - 1].Data_Venda[7] > '9' ||
			Passagem_Global[inclusao_iden - 1].Data_Venda[8] < '0' || Passagem_Global[inclusao_iden - 1].Data_Venda[8] > '9' ||
			Passagem_Global[inclusao_iden - 1].Data_Venda[9] < '0' || Passagem_Global[inclusao_iden - 1].Data_Venda[9] > '9'){
		
				printf("\n\n\t\t Formato de data inválido.");
				printf("\n\n\t\t Insira novamente (xx/xx/xxxx): ");
				gets(Passagem_Global[inclusao_iden - 1].Data_Venda);
				aux = 1;	
		
			}
		}
		
		//Condicionamento de entrada de dados da Data, limitando para datas reais
		while(aux == 0){
		
			aux = 1;
			dia[0] = Passagem_Global[inclusao_iden - 1].Data_Venda[0];
			dia[1] = Passagem_Global[inclusao_iden - 1].Data_Venda[1];
			mes[0] = Passagem_Global[inclusao_iden - 1].Data_Venda[3];
			mes[1] = Passagem_Global[inclusao_iden - 1].Data_Venda[4];
			ano[0] = Passagem_Global[inclusao_iden - 1].Data_Venda[6];
			ano[1] = Passagem_Global[inclusao_iden - 1].Data_Venda[7];
			ano[2] = Passagem_Global[inclusao_iden - 1].Data_Venda[8];
			ano[3] = Passagem_Global[inclusao_iden - 1].Data_Venda[9];
		
			if (strcmp(dia, "31") > 0 || strcmp(dia, "0") < 0 ||
			strcmp(mes, "12") > 0 || strcmp(mes, "0") < 0 ||
			strcmp(ano, "9999") > 0 || strcmp(ano, "2021") < 0){
		
				printf("\n\n\t\t Os valores ultrapassaram o limite.");
				printf("\n\n\t\t Formato de data inválido.");
				printf("\n\n\t\t Insira novamente: ");
				gets(Passagem_Global[inclusao_iden - 1].Data_Venda);
				aux = 0;
			
			}
		}
		
		//Atribui o valor 0 ao nulo dessa nova passagem, para que ela não seja considerada como uma passagem nula
		Passagem_Global[inclusao_iden - 1].nulo = 0;
		
		//Incrementa a quantidade de passagens dentro de um mesmo voo	
		aux_passagem[inclusao_iden - 1]++;
	}
	
	//Incrementa para poder registrar o numero de passagens totais cadastradas
	aux_passagem_nulo++;
	
}

/*
Objetivo: - Fazer a alteração dos dados de alguma passagem previamente inserida
Entrada: -	Passagem a ser alterada
Retorno: -	Repreenchimento dos dados na variável
*/
void alterar_passagem(){
	
	int alterar_iden, i;
	
	printf("\n\n\t\t Passagens disponíveis:\n");	
	
//Imprime uma breve informação de cada passagem disponível para o operador poder escolher qual prefere alterar as informações
	
	for (i=0; i < aux_passagem_nulo; i++){            //Percorrerá todas as passagens do vetor global que os armazena
		if (Passagem_Global[i].nulo == 0) {           //Apenas passagens que não tem sua flag "nulo" == 1. Ou seja, passageiros nao anulados
		
			printf("\n\n\t\t Passagem número: %d", Passagem_Global[i].Numero);
			printf("\n\n\t\t Identificador do Passageiro: %d", Passagem_Global[i].Identificador_Passageiro);
			printf("\n\n\t\t Identificador do Voo: %d", Passagem_Global[i].Identificador_Voo);
			printf("\n\n\t\t Número da Poltrona: %d", Passagem_Global[i].Numero_Poltrona);
			printf("\n\n");
		}
		else if  (Passagem_Global[i].nulo == 1) {     //Passagens consideradas anuladas não seram imprimidas
			printf("");
		}
	}
	
//Escolha do passagem a ser alterado
	printf("\n\n\t\t Escreva o número da passagem a ser alterada: ");   
	
	scanf("%d", &alterar_iden);
	
	system("cls");
	
//Inicio da alteração dos dados	
	printf("\n\n\t\t ***** Alterando informações da passagem %d *****", alterar_iden);
	
	sleep(2);
	
	printf("\n\n\t\t Insira o número da Poltrona: ");
	scanf("%d%*c", &Passagem_Global[alterar_iden - 1].Numero_Poltrona);

	printf("\n\n\t\t Insira o valor da passagem: ");
	scanf("%f%*c", &Passagem_Global[alterar_iden - 1].Valor);

	printf("\n\n\t\t Insira a data da venda da passagem: ");
	gets(Passagem_Global[alterar_iden - 1].Data_Venda);

	Passagem_Global[alterar_iden - 1].nulo = 0;
	
	printf("\n\n");
	
//Final da alteração dos dados
}

/*
Objetivo: - Fazer a exclusão de alguma passagem previamente inserida
Entrada: -	Passagem a ser excluida 
Retorno: -	Anulamento da passagem
*/
void exclusao_passagem(){
	
	int cancelar_iden, i, confirmar_exclusao;
	
	printf("\n\n\t\t Passagens disponíveis:\n");	
	
//Imprime uma breve informação de cada passagem disponível para o operador poder escolher qual prefere alterar as informações
	
	for (i=0; i < aux_passagem_nulo; i++){           //Percorrerá todos as passagens do vetor global que as armazena
		if (Passagem_Global[i].nulo == 0) {          //Apenas passagens que não tem sua flag "nulo" == 1. Ou seja, passageiros nao anulados
		
			printf("\n\n\t\t Passagem número: %d", Passagem_Global[i].Numero);
			printf("\n\n\t\t Identificador do Passageiro: %d", Passagem_Global[i].Identificador_Passageiro);
			printf("\n\n\t\t Identificador do Voo: %d", Passagem_Global[i].Identificador_Voo);
			printf("\n\n\t\t Número da Poltrona: %d", Passagem_Global[i].Numero_Poltrona);
			printf("\n\n");
		}
		else if  (Passagem_Global[i].nulo == 1) {    //Passagens consideradas anuladas não seram imprimidas
			printf("");
		}
	}
	
	//Escolha do passagem a ser cancelada
	printf("\n\n\t\t Escreva o número da passagem a ser cancelada: ");
	scanf("%d", &cancelar_iden);
	
	system("cls");   
		
    //Confirmação de exclusão
	printf("\n\n\t\t Você tem certeza que quer cancelar esta passagem? (1 para Sim e 2 para Não): ");
	scanf("%d", &confirmar_exclusao);
	
	if (confirmar_exclusao == 1){
		
        //Confirmado a exclusão, altera o argumento nulo para verdadeiro, ou seja, 1 e acresce 1 a variavel que conta as passagens excluídas.
		Passagem_Global[(cancelar_iden - 1)].nulo = 1;
		printf("\n\n\t\t Passagem de número %d anulada com sucesso.", cancelar_iden);
		aux_passagem_exclusao++;
	
	} 
	else if (confirmar_exclusao != 1) {
		//Não confirmado a exclusão, retorna ao sub menu
		printf("\n\n\t\t Ok, voltando ao menu...");
			
	}		
}

/*
Objetivo: - Fazer a consulta dos dados de alguma passagem previamente inserida
Entrada: -	Passagem a ser consultada
Retorno: - Todos os dados da passagem
*/
void consulta_passagem(){
	
	int consultar_iden, i;
	
	printf("\n\n\t\t Passagens disponíveis:\n");	
	
//Imprime uma breve informação de cada passagem disponível para o operador poder escolher qual prefere alterar as informações
	
	for (i=0; i < aux_passagem_nulo; i++){                 //Percorrerá todos os passagens do vetor global que as armazena
		if (Passagem_Global[i].nulo == 0) {                //Apenas passagens que não tem sua flag "nulo" == 1. Ou seja, passageiros nao anulados
		
			printf("\n\n\t\t Passagem número: %d", Passagem_Global[i].Numero); 
			printf("\n\n\t\t Identificador do Passageiro: %d", Passagem_Global[i].Identificador_Passageiro);
			printf("\n\n\t\t Identificador do Voo: %d", Passagem_Global[i].Identificador_Voo);
			printf("\n\n\t\t Número da Poltrona: %d", Passagem_Global[i].Numero_Poltrona);
			printf("\n\n");
		}
		else if  (Passagem_Global[i].nulo == 1) {          //Passagens consideradas anuladas não seram imprimidas
			printf("");
		}
	}
	
	//Escolha do passagem a ser consultada
	printf("\n\n\t\t Escreva o número da passagem a ser consultado: ");
	scanf("%d", &consultar_iden);
	
	system("cls");
	
	//Impressão dos dados da passagem escolhida
	printf("\n\n\t\t Essas são as informações da passagem escolhida:");
		
		printf("\n\n\t\t Passagem de número: %d", Passagem_Global[consultar_iden - 1].Numero);
		printf("\n\n\t\t Identificador do passageiro: %d", Passagem_Global[consultar_iden - 1].Identificador_Passageiro);
		printf("\n\n\t\t Identificador do voo: %d", Passagem_Global[consultar_iden - 1].Identificador_Voo);	
		printf("\n\n\t\t Número da Poltrona: %d", Passagem_Global[consultar_iden - 1].Numero_Poltrona);
		printf("\n\n\t\t Valor da Passagem: %.2f", Passagem_Global[consultar_iden - 1].Valor);		
		printf("\n\n\t\t Data da venda: %s", Passagem_Global[consultar_iden - 1].Data_Venda);
		printf("\n\n");
	
}

/*
Objetivo: - Gerar o relatório de todas as passagens inseridas
Entrada: -	Dados de todas as passagens inseridas
Retorno: -  Passagens confirmadas e passagens excluidas
*/
void relatorio_passagem(){
	
	int i;
	
	printf("\n\n\t\t ***** Registros cadastrados pelo usuário *****");
	printf("\n\n");
	
	printf("\n\n\t\t As seguintes passagens foram confirmadas: ");
	printf("\n\n");
	
	for(i=0; i < aux_passagem_nulo; i++){                  //Percorrerá todos as passagens do vetor global que as armazena.
		if(Passagem_Global[i].nulo == 0){                  //Apenas passagens que nao tem sua flag "nulo" == 1. Ou seja, passageiros nao anulados.
		
			//Impressão dos dados de todas as passagens confirmadas
			printf("\n\n\t\t Passagem de número: %d", Passagem_Global[i].Numero);
			printf("\n\n\t\t Identificador do passageiro: %d", Passagem_Global[i].Identificador_Passageiro);
			printf("\n\n\t\t Identificador do voo: %d", Passagem_Global[i].Identificador_Voo);	
			printf("\n\n\t\t Número da Poltrona: %d", Passagem_Global[i].Numero_Poltrona);
			printf("\n\n\t\t Valor da Passagem: %.2f", Passagem_Global[i].Valor);		
			printf("\n\n\t\t Data da venda: %s", Passagem_Global[i].Data_Venda);
			printf("\n\n");
			sleep(1);
				
		}
	}
	
	//Caso a quantidade de passagens cadastradas seja igual as excluídas, nenhuma foi confirmada
	if(aux_passagem_nulo == aux_passagem_exclusao){
		
		printf("\n\n\t\t Nenhuma passagem foi confirmada.");
		sleep(1);
			
	}
	
	printf("\n\n");
	printf("\n\n\t\t Atenção! As seguintes passagens foram excluidas: ");
	printf("\n\n");
	
	for(i=0; i < aux_passagem_nulo; i++){           //Percorrerá todos as passagens do vetor global que as armazena.
		if  (Passagem_Global[i].nulo == 1) {        //Apenas passagens que tem sua flag "nulo" == 1. Ou seja, passagens anuladas.
		
			//Impressão dos dados de todas as passagens	
			printf("\n\n\t\t Passagem de número: %d", Passagem_Global[i].Numero);
			printf("\n\n\t\t Identificador do passageiro: %d", Passagem_Global[i].Identificador_Passageiro);
			printf("\n\n\t\t Identificador do voo: %d", Passagem_Global[i].Identificador_Voo);	
			printf("\n\n\t\t Número da Poltrona: %d", Passagem_Global[i].Numero_Poltrona);
			printf("\n\n\t\t Valor da Passagem: %.2f", Passagem_Global[i].Valor);		
			printf("\n\n\t\t Data da venda: %s", Passagem_Global[i].Data_Venda);
			printf("\n\n");
			sleep(1);
			
		}			
	}
	
	//Caso a quantidade de passagens excluídas for 0, nenhuma foi cancelada
	if(aux_passagem_exclusao == 0){
		
		printf("\n\n\t\t Nenhuma passagem foi excluída.");
		sleep(1);
			
	}
	
	//Proporcionalidade do delay na interface de relatorios com base no tanto que foram cadastrados
	sleep(aux_passagem_nulo*5);
	
}

/*
Objetivo: - Inicializar o menu principal
Entrada: -	Opção do menu
Retorno: -	Alteração da tela com base na opção escolhida  
*/
int main(){
	
	int escolha_1;
	setlocale(LC_ALL,"Portuguese");
	
	// Menu Principal
	do{
		printf("\n\n\t\t ********************************************************************");
		printf("\n\t\t                   Bem vindo a Lobo Airlines                   ");
		printf("\n\t\t ********************************************************************");
		printf("\n\n\t\t 1 - Voos\n");
		printf("\n\n\t\t 2 - Passageiros\n");
		printf("\n\n\t\t 3 - Passagens\n");
		printf("\n\n\t\t 4 - Sair\n");
		printf("\n\n\t\t Escolha uma opção: ");
		scanf("%d", &escolha_1);
		while(escolha_1 < 1 || escolha_1 > 4){
			printf("\n\n\t\t Escolha uma opção correta: ");
			scanf("%d", &escolha_1);
		}
	system("cls");
	
	if(escolha_1 != 4){
		sub_menu(escolha_1);	
	}
	
	}while(escolha_1!=4);			//Finaliza o Programa
		system("cls");
		printf("\n\n\t\t Obrigado pela preferência! \2\n");
		exit(0);	
}








