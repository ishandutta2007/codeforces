#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
const ll I2 = 500000004;

ll N, M, K;
ll D[2020][2020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d%d", &N, &M, &K);
		D[1][0] = 0; D[1][1] = K;

		for(int i = 2; i <= N; i++) {
			D[i][0] = 0; D[i][i] = (ll)K * i % MOD;
			for(int j = 1; j < i; j++) {
				D[i][j] = (D[i - 1][j] + D[i - 1][j - 1]) * I2 % MOD;
			}
		}
		printf("%lld\n", D[N][M]);
	}
	return 0;
}