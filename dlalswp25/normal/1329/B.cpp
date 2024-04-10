#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll C[35];
ll D[35][35];
ll X, M;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		for(int i = 0; i < 35; i++) for(int j = 0; j < 35; j++) D[i][j] = 0;
		for(int i = 0; i < 35; i++) C[i] = 0;
		scanf("%lld%lld", &X, &M);

		for(int i = 0; i < 30; i++) {
			if((1 << (i + 1)) > X) {
				C[i] = X - (1 << i) + 1;
				break;
			}
			else C[i] = (1 << i);
		}

		// for(int i = 0; i < 30; i++) printf("%lld ", C[i]); puts("");

		for(int i = 0; i < 30; i++) D[1][i] = C[i] % M;
		for(int i = 2; i <= 30; i++) {
			for(int j = 0; j < 30; j++) {
				for(int k = 0; k < j; k++) {
					D[i][j] = (D[i][j] + D[i - 1][k]) % M;
				}
				D[i][j] = D[i][j] * C[j] % M;
			}
		}

		ll ans = 0;
		for(int i = 1; i <= 30; i++) {
			for(int j = 0; j < 30; j++) {
				ans = (ans + D[i][j]) % M;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}