#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll D[2020202][2];
ll E[2020202];

int main() {
	int T; scanf("%d", &T);

	// D[3][0] = 4;

	// for(int i = 4; i <= 2000000; i++) {
	// 	D[i][0] = max(4 + 2 * D[i - 2][1] + D[i - 1][1], 2 * D[i - 2][0] + D[i - 1][0]);
	// 	D[i][1] = 2 * D[i - 2][0] + D[i - 1][0];
	// }

	int t = 0;
	for(int i = 3; i <= 2000000; i++) {
		if(t == 0 || t == 2) E[i] = (E[i - 1] * 2 + 4) % MOD;
		else if(t == 1) E[i] = (E[i - 1] * 2 + MOD - 4) % MOD;
		else E[i] = E[i - 1] * 2 % MOD;
		t = (t + 1) % 6;
	}

	// for(int i = 1; i <= 100; i++) printf("%lld\n", D[i][0]);

	while(T--) {
		int N; scanf("%d", &N);
		printf("%lld\n", E[N]);
	}
	return 0;
}