#include <bits/stdc++.h>

using namespace std;

int N, K;
char S[303030];
int A[303030];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		for(int i = 0; i < K; i++) A[i] = -1;
		scanf("%s", S);

		bool ok = true;
		for(int i = 0; i < N; i++) {
			if(S[i] == '?') continue;
			if(A[i % K] != -1) {
				if(A[i % K] != S[i] - '0') ok = false;
			}
			else A[i % K] = S[i] - '0';
		}

		if(!ok) { puts("NO"); continue; }

		int c0 = 0, c1 = 0;
		for(int i = 0; i < K; i++) {
			if(A[i] == 0) c0++;
			else if(A[i] == 1) c1++;
		}
		if(c0 > K / 2 || c1 > K / 2) puts("NO");
		else puts("YES");
	}

	return 0;
}