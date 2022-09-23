#include <bits/stdc++.h>

using namespace std;

int S[202020];
int N;
int basis[20];
vector<int> B;
int X = 0;

void printAns(int n) {
	if(!n) { printf("%d ", X); return; }
	printAns(n - 1);
	X ^= B[n - 1];
	printAns(n - 1);
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &S[i]);
	for(int x = 18; x >= 0; x--) {
		B.clear();
		for(int i = 0; i <= 17; i++) basis[i] = 0;
		for(int i = 1; i <= N; i++) {
			if(S[i] >= (1 << (x))) continue;
			int now = S[i];
			for(int j = 17; j >= 0; j--) {
				if(now < (1 << j)) continue;
				if(basis[j]) now ^= basis[j];
				else {
					basis[j] = now;
					B.push_back(S[i]);
					break;
				}
			}
		}
		if(B.size() < x) continue;
		else break;
	}
	printf("%d\n", B.size());
	//for(int i : B) printf("%d ", i);

	printAns((int)B.size());
	puts("");

	return 0;
}