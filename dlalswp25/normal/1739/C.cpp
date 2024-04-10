#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;
const int MX = 60;

int N;
ll ncr[66][66];
ll D[66][2];

int main() {
	for(int i = 0; i <= MX; i++) ncr[i][0] = 1;
	for(int i = 1; i <= MX; i++) {
		for(int j = 1; j <= i; j++) ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % MOD;
	}
	D[2][0] = 1; D[2][1] = 0;
	for(int i = 4; i <= MX; i += 2) {
		D[i][0] = (D[i - 2][1] + ncr[i - 2][i / 2 - 2] + ncr[i - 2][i / 2 - 1]) % MOD;
		D[i][1] = (D[i - 2][0] + ncr[i - 2][i / 2 - 2]) % MOD;
	}

	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		printf("%lld %lld 1\n", D[N][0], D[N][1]);
	}
	return 0;
}