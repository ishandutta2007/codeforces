#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;

int N;
int A[101010];
ll S[101010];
ll D[2][101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			S[i] = S[i - 1] + A[i];
		}

		for(int i = 1; i <= N; i++) D[0][i] = D[1][i] = INF;
		D[0][N + 1] = INF;
		for(int k = 1; ; k++) {
			D[k & 1][N + 1] = 0;
			for(int i = N; i >= 1; i--) {
				if(i + k - 1 > N) { D[k & 1][i] = 0; continue; }
				D[k & 1][i] = D[k & 1][i + 1];
				if(S[i + k - 1] - S[i - 1] < D[k + 1 & 1][i + k]) {
					D[k & 1][i] = max(D[k & 1][i], S[i + k - 1] - S[i - 1]);
				}
			}
			if(!D[k & 1][1]) { printf("%d\n", k - 1); break; }
		}
	}
	return 0;
}