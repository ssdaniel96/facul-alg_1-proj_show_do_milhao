#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define totalQuestions 20
#define alternatives 3

struct questions{
	int id;
	char question[100];
	char replies[3][100];
	int correct;
};

float jpots[20];
int alreadyQuestioned[totalQuestions];
int questionCounter = 0;
int rightAnswerCounter = 0;
int lives = 3;
int helps = 2;
int stop = 0;
char nome[100];
struct questions q[totalQuestions];



int alreadyQtned(int nNumber, int alreadyQuestion[totalQuestions]){
	int equal = 0;
	for (int i = 0; i < totalQuestions; i++){
		if (alreadyQuestion[i] == nNumber){
			equal = 1;
		}
	}
	return equal;
}

int questionRandom(){
	int newQn;
	int count = 0;
	int nN = 0;

	do{
		if (count > 5){
			newQn = nN;
			nN++;
		}
		else{
			srand(time(NULL));
			newQn = rand() % totalQuestions;
			count++;
		}
	}
	while(alreadyQtned(newQn, alreadyQuestioned));


	if (newQn >= totalQuestions) newQn = 0;

	alreadyQuestioned[questionCounter] = newQn;
	return newQn;
}

void loadQuestions(){
	q[0].id = 1;
	strcpy(q[0].question, "Quando foi criada a seleção Brasileira?");
	strcpy(q[0].replies[0], "1917");
	strcpy(q[0].replies[1], "1914");
	strcpy(q[0].replies[2], "1915");
	q[0].correct = 2;

	q[1].id = 2;
	strcpy(q[1].question, "Qual o jogador com mais partidas na seleção brasileira?");
	strcpy(q[1].replies[0], "Pelé");
	strcpy(q[1].replies[1], "Cafú");
	strcpy(q[1].replies[2], "Rivelino");
	q[1].correct = 2;

	q[2].id = 3;
	strcpy(q[2].question, "Quantos gols o maior artilheiro (Pelé) fez com a camisa do Brasil?");
	strcpy(q[2].replies[0], "77");
	strcpy(q[2].replies[1], "83");
	strcpy(q[2].replies[2], "92");
	q[2].correct = 1;

	q[3].id = 4;
	strcpy(q[3].question, "Qual a seleção fez a maior goleada no Brasil, sem ser a Alemanha?");
	strcpy(q[3].replies[0], "Italia 5x0");
	strcpy(q[3].replies[1], "Argentina 4x0");
	strcpy(q[3].replies[2], "Uruguai 6x0");
	q[3].correct = 3;

	q[4].id = 5;
	strcpy(q[4].question, "Qual destes times já foi rebaixado?");
	strcpy(q[4].replies[0], "São Paulo");
	strcpy(q[4].replies[1], "Corinthians");
	strcpy(q[4].replies[2], "Santos");
	q[4].correct = 2;

	q[5].id = 6;
	strcpy(q[5].question, "Com quantos jogadores um time de futebol entra em campo?");
	strcpy(q[5].replies[0], "11");
	strcpy(q[5].replies[1], "12");
	strcpy(q[5].replies[2], "10");
	q[5].correct = 1;

	q[6].id = 7;
	strcpy(q[6].question, "Qual é o formato do campo de beisebol?");
	strcpy(q[6].replies[0], "Diamante");
	strcpy(q[6].replies[1], "Triangular");
	strcpy(q[6].replies[2], "Quadrado");
	q[6].correct = 1;

	q[7].id = 8;
	strcpy(q[7].question, "Como é chamado o jogador que pega as bolas longas que são rebatidas?");
	strcpy(q[7].replies[0], "Rebatedor");
	strcpy(q[7].replies[1], "Receptor");
	strcpy(q[7].replies[2], "Jardineiro");
	q[7].correct = 3;

	q[8].id = 9;
	strcpy(q[8].question, "Como é chamado a rebatida quando a bola sai do estádio?");
	strcpy(q[8].replies[0], "Home Run");
	strcpy(q[8].replies[1], "Gol");
	strcpy(q[8].replies[2], "Strike");
	q[8].correct = 1;

	q[9].id = 10;
	strcpy(q[9].question, "O beisebol é um esporte muito popular em que País?");
	strcpy(q[9].replies[0], "México");
	strcpy(q[9].replies[1], "Portugal");
	strcpy(q[9].replies[2], "Estados Unidos");
	q[9].correct = 3;

	q[10].id = 11;
	strcpy(q[10].question, "Em qual cidade brasileira foram realizados os Jogos de 2016?");
	strcpy(q[10].replies[0], "São Paulo");
	strcpy(q[10].replies[1], "Rio de Janeiro");
	strcpy(q[10].replies[2], "Salvador");
	q[10].correct = 2;

	q[11].id = 12;
	strcpy(q[11].question, "Em que país será realizada a edição dos Jogos Olímpicos de 2020?");
	strcpy(q[11].replies[0], "Tóquio");
	strcpy(q[11].replies[1], "Nairóbi");
	strcpy(q[11].replies[2], "Berlim");
	q[11].correct = 1;

	q[12].id = 13;
	strcpy(q[12].question, "A cada quantos anos se é realizada uma edição dos Jogos Olímpicos?");
	strcpy(q[12].replies[0], "2");
	strcpy(q[12].replies[1], "4");
	strcpy(q[12].replies[2], "6");
	q[12].correct = 2;

	q[13].id = 14;
	strcpy(q[13].question, "No vôlei, o que acontece quando a bola que um jogador tocou bate na rede?");
	strcpy(q[13].replies[0], "É ponto para o time do jogador");
	strcpy(q[13].replies[1], "É ponto para os dois times");
	strcpy(q[13].replies[2], "É ponto para o time adversário");
	q[13].correct = 3;

	q[14].id = 15;
	strcpy(q[14].question, "No rugby, ou futebol americano, qual é o formato da bola usada durante o jogo?");
	strcpy(q[14].replies[0], "Oval");
	strcpy(q[14].replies[1], "Redonda");
	strcpy(q[14].replies[2], "Quadrada");
	q[14].correct = 2;

	q[15].id = 16;
	strcpy(q[15].question, "Quantos jogadores possuem um time de Handebol?");
	strcpy(q[15].replies[0], "7");
	strcpy(q[15].replies[1], "8");
	strcpy(q[15].replies[2], "9");
	q[15].correct = 1;

	q[16].id = 17;
	strcpy(q[16].question, "Em que ano foi criado o Handebol?");
	strcpy(q[16].replies[0], "1919");
	strcpy(q[16].replies[1], "1920");
	strcpy(q[16].replies[2], "1921");
	q[16].correct = 1;

	q[17].id = 18;
	strcpy(q[17].question, "NÃO é uma arte macial?");
	strcpy(q[17].replies[0], "Taekwondo");
	strcpy(q[17].replies[1], "Jiu Jitsu");
	strcpy(q[17].replies[2], "Balé");
	q[17].correct = 3;

	q[18].id = 19;
	strcpy(q[18].question, "Na mobilidade 'nada livre' qual é o estilo mais usado?");
	strcpy(q[18].replies[0], "Cwal");
	strcpy(q[18].replies[1], "Peito");
	strcpy(q[18].replies[2], "Costas");
	q[18].correct = 1;

	q[19].id = 20;
	strcpy(q[19].question, "Qual é o nome que se dá para o ato de o nadador 'cair na água e sair nadando'?");
	strcpy(q[19].replies[0], "Mergulho");
	strcpy(q[19].replies[1], "Tiro");
	strcpy(q[19].replies[2], "Saída");
	q[19].correct = 3;


}

void loadJpots(){
	jpots[0]=1000;
	jpots[1]=2000;
	jpots[2]=3000;
	jpots[3]=4000;
	jpots[4]=5000;
	jpots[5]=10000;
	jpots[6]=15000;
	jpots[7]=20000;
	jpots[8]=30000;
	jpots[9]=40000;
	jpots[10]=50000;
	jpots[11]=75000;
	jpots[12]=100000;
	jpots[13]=150000;
	jpots[14]=200000;
	jpots[15]=250000;
	jpots[16]=300000;
	jpots[17]=400000;
	jpots[18]=500000;
	jpots[19]=1000000;
}

int stopPlay(float amount){
	system("cls");
	int opc;
	int inv = 0;
	do{
		if(inv){
			printf("Opção inválida! \n");
		}
		printf("Deseja PARAR garantindo metade do prêmio de R$ %.2f, no valor de: R$ %.2f \n[Você tem mais %d vidas, se chegar a 0 perde TUDO)\n", amount, amount / 2, lives);
		printf("\n\t1 - SIM - Parar parar e receber o prêmio\n\t0 - NÃO - Para continuar no jogo\n(1/0): ");
		scanf("%d", &opc);
		inv = 1;
		system("cls");	
	}while (opc != 1 && opc != 0);

	if (opc == 1){
		inv = 0;
		return 0;
	}
	else{
		inv = 0;
		return 1;
	}

}

void gameOver(){
	system("cls");
	printf("Que pena %s, você perdeu tudo!", nome);
}

int doQuestion(){
	int questioN = questionRandom();
	int rightAnswer = 0;

	int requestedHelp = 0;
	do{
		int chosenOpc;

		do{
			printf("%dº PERGUNTA - Valendo %.2f\n", questionCounter+1, jpots[rightAnswerCounter]);
			printf("- %s\n", q[questioN].question);
			for (int i = 0; i < alternatives; i++ ){
				printf("\t%d - %s\n",i+1, q[questioN].replies[i]);
			}
			if (helps > 0 && requestedHelp == 0){
				printf("\t%d - Ajuda aos universitários [Ajudas restantes: %d]\n", alternatives+1, helps);
			}
			else if (helps >= 0 && requestedHelp == 1){
				printf("\nOs universitários acham que a resposta é a alternativa: %d\n", q[questioN].correct);
				requestedHelp = 0;
			}
			printf("Alternativa: ");
			scanf("%d", &chosenOpc);
			printf("\n");
		}
		while(!((chosenOpc > 0  && chosenOpc <= alternatives) || (chosenOpc == alternatives+1 && helps > 0)));

		if (chosenOpc==(q[questioN].correct)){
			printf("Resposta certa\n");
			rightAnswer =1;
		}
		else if(chosenOpc == alternatives+1){
			requestedHelp=1;
			helps--;
		}
		else{
			printf("Que pena! Você errou!\n");
			rightAnswer =0;
		}
		system("pause");
	}
	while(requestedHelp);
	questionCounter++;

	return rightAnswer;
}

void statusMenu(float amount, int rightAnswers){
	printf("Show do milhão!!!\n");
	printf("Nome: %s\t Vidas: %d \t Ajuda de universtiários restantes: %d \n", nome, lives, helps);
	float totalAmount = 0;
	totalAmount = jpots[questionCounter];
	float prizeAmount  = 0;
	prizeAmount = jpots[rightAnswerCounter];
	
	
	
	printf("Perguntas respondidas: %d\t Total de acertos: %d\t Premio acumulado: R$ %.2f\nPremio [possivel] total: R$ %.2f \tValor Total (com perdas): R$ %.2f\n", questionCounter, rightAnswers, amount, prizeAmount, totalAmount);
}

int main()
{
	float amount = 0.0;
	setlocale(LC_ALL, "");
	loadQuestions();
	loadJpots();
	printf("Bem vindo ao Show do Milhão!!!\n");
	printf("Digite seu nome: ");
	gets(nome);
	do{
		int win = 0;
		system("cls");
		statusMenu(amount, rightAnswerCounter);
		win = doQuestion();
		if (win==0){
			lives--;
			if (lives == 0){
				gameOver();
				break;
			}
		}
		else{
			rightAnswerCounter++;
			if (rightAnswerCounter == 0){
				amount = 0;
			}
			else{
				amount = jpots[rightAnswerCounter-1];
			}
		}
	} while (stopPlay(amount) && questionCounter < totalQuestions);
	system("cls");

	if (lives == 0){
		printf("Você perdeu, não ganhará nada");
	}
	else if(stop == 1){
		amount = amount / 2;
	}

	printf("Parabéns %s você ganhou %.2f\n", nome, amount);
	printf("Obrigado por jogar\n");

	return (0);
}











void testar_questionRandom(){
	printf("Iniciar testes: \n");
	while(questionCounter < 4){
		printf("totalQuestionCounter: %d\n", questionCounter);
		for (int i = 0; i < questionCounter; i++){
			printf("alreadyQuestioned#%d: %d\n", i, alreadyQuestioned[i]);
		}
		printf("newNum: %d\n", questionRandom(alreadyQuestioned, questionCounter));
	}
}

