#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

ll D[1010][1010];
ll E[1010][1010];
int N, M;

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) {
		for(int j = i; j <= N; j++) D[i][j] = 1;
	}
	for(int i = 2; i <= M; i++) {
		for(int j = 1; j <= N; j++) {
			for(int k = N; k >= j; k--) {
				E[j][k] = (E[j - 1][k] + E[j][k + 1] + MOD - E[j - 1][k + 1] + D[j][k]) % MOD;
			}
		}
		for(int j = 1; j <= N; j++) for(int k = j; k <= N; k++) D[j][k] = E[j][k];
	}
	
	ll ans = 0;
	for(int i = 1; i <= N; i++) for(int j = i; j <= N; j++) ans = (ans + D[i][j]) % MOD;
	printf("%lld\n", ans);

	return 0;
}