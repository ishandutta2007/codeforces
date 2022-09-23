#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int N, M;
ll D[202020][10];

int main() {
	for(int i = 0; i <= 9; i++) D[0][i] = 1;
	for(int i = 1; i <= 200000; i++) {
		for(int j = 0; j < 9; j++) {
			D[i][j] = D[i - 1][j + 1];
		}
		D[i][9] = (D[i - 1][0] + D[i - 1][1]) % MOD;
	}

	int tc; scanf("%d", &tc);
	while(tc--) {
		int N, M; scanf("%d%d", &N, &M);
		int ans = 0;
		while(N) {
			ans = (ans + D[M][N % 10]) % MOD;
			N /= 10;
		}
		printf("%d\n", ans);
	}
	return 0;
}