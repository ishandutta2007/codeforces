#include <cstdio>
using namespace std;
#define BIG    100000
#define BIGGER 100001

int ql[BIG], qr[BIG];
int a[BIG];
int len, qn;
int relevant[BIG];
int answers[BIG] = {0};
int relevantLen;

void readInput(){
	scanf("%d %d", &len, &qn);
	for (int i = 0; i < len; i++){
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < qn; i++){
		int ql1, qr1;
		scanf("%d %d", &ql1, &qr1);
		// half-open zero-indexed
		ql[i] = ql1 - 1;
		qr[i] = qr1;
	}
}

void scanRelevant(){
	int histogram[BIGGER] = {0};
	for (int i = 0; i < len; i++){
		if (a[i] <= BIG) histogram[a[i]]++;
	}
	for (int i = 1; i <= BIG; i++){
		if (histogram[i] >= i) relevant[relevantLen++] = i;
	}
}

void addPartialAnswers(int r){
	int cumsum[BIGGER] = {0};
	for (int i = 1; i <= len; i++){
		cumsum[i] = cumsum[i-1] + (a[i-1] == r ? 1 : 0);
	}
	for (int qi = 0; qi < qn; qi++){
		int mult = cumsum[qr[qi]] - cumsum[ql[qi]];
		if (cumsum[qr[qi]] - cumsum[ql[qi]] == r) answers[qi]++;
	}
}

void computeAnswers(){
	scanRelevant();
	for (int i = 0; i < relevantLen; i++){
		addPartialAnswers(relevant[i]);
	}
}

void printAnswers(){
	for (int qi = 0; qi < qn; qi++){
		printf("%d\n", answers[qi]);
	}
}

int main(){
	readInput();
	computeAnswers();
	printAnswers();
}