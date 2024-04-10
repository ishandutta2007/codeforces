#include <cstdio>
using namespace std;

int e[101][2]; // enemies of #i
int ec[101]; // enemy count
bool checked[101];
int n;

void reset(){
	for (int i = 0; i < 101; i++){
		ec[i] = 0;
		checked[i] = false;
	}
}

void readInput(){
	reset();
	int m, e1, e2;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++){
		scanf("%d %d", &e1, &e2);
		e[e1][ec[e1]] = e2;
		e[e2][ec[e2]] = e1;
		ec[e1]++;
		ec[e2]++;
	}
}

int otherEnemy(int x, int enemy){
	if (ec[x] == 1) return 0;
	return (e[x][0] + e[x][1] - enemy);
}

void checkAll(int v1, int v2){
	if (v2 == 0) return;
	checked[v2] = true;
	checkAll(v2, otherEnemy(v2, v1));
}

bool isInOddCycle(int i){
	checked[i] = true;
	if (ec[i] == 0) return false;
	if (ec[i] == 1) {
		// no odd cycle anyway
		checkAll(i, e[i][0]);
	}
	int v1 = i;
	int v2 = e[i][0];
	checked[v2] = true;
	int dist = 1;
	// v2 is dist enemy-relations away from i
	while (true){
		int t = otherEnemy(v2, v1);
		v1 = v2;
		v2 = t;
		dist++;
		if (v2 == 0) {
			// no cycle, dead-end
			checkAll(i, e[i][1]);
			return false;
		} else if (v2 == i) {
			checked[v2] = true;
			return (dist % 2 == 1);
		}
		checked[v2] = true;
	}
}

int minBenched(){
	int oddCycles = 0;
	for (int i = 1; i <= n; i++){ // i hate one-indexed
		if (!checked[i]){
			if (isInOddCycle(i)){
				oddCycles++;
			}
		}
	}
	return oddCycles + (((n - oddCycles) % 2 == 0) ? 0 : 1);
}

int main(){
	readInput();
	printf("%d", minBenched());
}