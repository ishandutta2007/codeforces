#include <bits/stdc++.h>

using namespace std;

int N;
char A[303030];
int L[303030];
int R[303030];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A + 1);
		for(int i = 1; i <= N; i++) {
			L[i] = 0;
			if(A[i] != 'L') continue;
			if(i == 1 || A[i - 1] == 'L') { L[i] = 1; continue; }
			L[i] = L[i - 2] + 2;
		}
		R[N] = 0;
		for(int i = N - 1; i >= 0; i--) {
			R[i] = 0;
			if(A[i + 1] != 'R') continue;
			if(i == N - 1 || A[i + 2] == 'R') { R[i] = 1; continue; }
			R[i] = R[i + 2] + 2;
		}
		for(int i = 0; i <= N; i++) printf("%d ", L[i] + R[i] + 1); puts("");
	}
	return 0;
}