#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int X[1005];
int Y[1005];
int A[1005];
int B[1005];
map<pii, int> M;

int main() {
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d%d", &X[i], &Y[i]);
	for(int i = 1; i <= N; i++) scanf("%d%d", &A[i], &B[i]);

	bool fin = false;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(fin) break;
			int x = X[i] + A[j];
			int y = Y[i] + B[j];
			M[{x, y}]++;
			if(M[{x, y}] >= N) {
				fin = true;
				printf("%d %d\n", x, y);
			}
		}
	}
	return 0;
}