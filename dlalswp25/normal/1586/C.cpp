#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
vector<vector<char> > A;
int C[1010101];
char S[1010101];

int main() {
	scanf("%d%d", &N, &M);
	A.resize(N + 1);

	for(int i = 1; i <= N; i++) {
		A[i].resize(M + 1);
		scanf("%s", S + 1);
		for(int j = 1; j <= M; j++) A[i][j] = S[j];
	}

	for(int i = 1; i < N; i++) {
		for(int j = 2; j <= M; j++) {
			if(A[i][j] == 'X' && A[i + 1][j - 1] == 'X') C[j]++;
		}
	}

	for(int j = 2; j <= M; j++) C[j] += C[j - 1];

	scanf("%d", &Q);
	while(Q--) {
		int a, b; scanf("%d%d", &a, &b);
		puts(C[b] - C[a] ? "NO" : "YES");
	}
	
	return 0;
}