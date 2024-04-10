#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int N;
char A[2020];
char B[2020];
ll D[2020][4040];
ll E[2020][4040];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A + 1);
		scanf("%s", B + 1);
		for(int i = 0; i <= N + 1; i++) for(int j = 0; j <= N + N; j++) D[i][j] = E[i][j] = 0;
		D[0][N] = 1;
		for(int i = 1; i <= N; i++) {
			for(int j = 0; j <= N + N; j++) {
				for(int k = 0; k < 2; k++) {
					if(A[i] != '?' && A[i] != k + '0') continue;
					for(int l = 0; l < 2; l++) {
						if(B[i] != '?' && B[i] != l + '0') continue;
						int tj = (i & 1 ? j + l - k : j - l + k);
						if(tj < 0 || tj > N + N) continue;
						D[i][tj] = (D[i][tj] + D[i - 1][j]) % MOD;
					}
				}
			}
		}
		E[N + 1][N] = 1;
		for(int i = N; i >= 1; i--) {
			for(int j = 0; j <= N + N; j++) {
				for(int k = 0; k < 2; k++) {
					if(A[i] != '?' && A[i] != k + '0') continue;
					for(int l = 0; l < 2; l++) {
						if(B[i] != '?' && B[i] != l + '0') continue;
						int tj = (~i & 1 ? j + l - k : j - l + k);
						if(tj < 0 || tj > N + N) continue;
						E[i][tj] = (E[i][tj] + E[i + 1][j]) % MOD;
					}
				}
			}
		}

		ll ans = 0;
		for(int i = 1; i < N; i++) {
			for(int j = 0; j <= N + N; j++) {
				ans = (ans + abs(j - N) * D[i][j] % MOD * E[i + 1][j]) % MOD;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}