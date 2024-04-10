#include <cstdio>
using namespace std;
// codeforces submission -- round 0x86 -- betaveros

#define IMPOSS 1234567
#define MAXOPS 1000001

int targetOps, result; // <= 10^6

void readInput(){
	scanf("%d %d", &targetOps, &result);
	targetOps--; // ignore op 01 -> 11 (done: corner)
}

bool opswap[MAXOPS];
bool bestOpswap[MAXOPS];
char opstring[MAXOPS];
int ops;
int mistakes;
int minMistakes = IMPOSS;


bool fail = false;

void countOps(int a, int b){
	ops = 0;
	mistakes = -1; // first one doesn't count
	while (a != b){
		// printf("%d %d", a, b);
		if (a < b) {
			int t = a;
			a = b;
			b = t;
			opswap[ops] = true;
		} else {
			opswap[ops] = false;
			mistakes++;
		}
		// printf(" %c\n", (opswap[ops] ? 'T' : 'F'));
		a -= b;
		ops++;
	}
	fail = (a > 1);

}

void solve(){
	if (targetOps == 0 && result == 1){
		minMistakes = 0;
	}
	for (int other = 1; other < result; other++){
		countOps(result, other);
		if (!fail) {
			// printf("nonfail: %d; ops = %d; mistakes: %d\n", other, ops, mistakes);
			if (ops == targetOps){
				if (mistakes < minMistakes){
					minMistakes = mistakes;
					for (int i = 0; i < ops; i++){
						bestOpswap[i] = opswap[i];
					}
				}
			}
		} // else printf("fail: %d\n", other);
	}
}

void printSolution(){
	if (minMistakes == IMPOSS){
		printf("IMPOSSIBLE");
	} else {
		printf("%d\n", minMistakes);
		printf("T");
		bool lastSwap = true;
		bool top = true;
		for (int i = 0; i < targetOps; i++){
			top ^= lastSwap;
			printf("%c", (top ? 'T' : 'B'));
			lastSwap = bestOpswap[targetOps - i - 1];
		}
	}
}

int main(){
	readInput();
	solve();
	printSolution();
	// countOps(144, 89);
	// countOps(153, 86);
}