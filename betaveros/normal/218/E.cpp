#include <cstdio>
using namespace std;

#define FC0 1
#define FC1 8
#define FCQ 6

char formula[1000003];

int fcEval(char opchar, int fcA, int fcB){
	int fcRet = 0;
	for (int apair = 0; apair < 4; apair++){
		if (((fcA >> apair) & 1) == 1){
			for (int bpair = 0; bpair < 4; bpair++){
				if (((fcB >> bpair) & 1) == 1){
					int rpair = -1;
					switch (opchar){
						case '&':
							rpair = apair & bpair;
							break;
						case '|':
							rpair = apair | bpair;
							break;
						case '^':
							rpair = apair ^ bpair;
							break;
					}
					fcRet |= (1 << rpair);
				}
			}
		}
	}
	return fcRet;
}

int fcParse(int start, int& end){
	if (formula[start] == '0') { /*printf("fc0");*/ end = start + 1; return FC0; }
	if (formula[start] == '1') { /*printf("fc1");*/ end = start + 1; return FC1; }
	if (formula[start] == '?') { /*printf("fc?");*/ end = start + 1; return FCQ; }

	if (formula[start] == '(') {
		//printf("(");
		int opi;
		int fcA = fcParse(start+1, opi);
		char opchar = formula[opi];
		//printf(" %c ", opchar);
		int bend;
		int fcB = fcParse(opi+1, bend);
		end = bend + 1;
		int evalue = fcEval(opchar, fcA, fcB);
		//printf(" = %d)", evalue);
		return evalue;
	}
	return -1;

}

int main(){
	int n;
	scanf("%d\n", &n);
	fgets(formula, 1000001, stdin);
	int waste;
	if ((fcParse(0, waste) & 2) != 0){
		printf("YES");
	} else {
		printf("NO");
	}
}