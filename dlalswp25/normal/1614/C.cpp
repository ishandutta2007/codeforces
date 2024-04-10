#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int N, M;
int ans[202020];
int D[30][202020];
ll pw[202020];

int main() {
	pw[0] = 1;
	for(int i = 1; i <= 200000; i++) pw[i] = pw[i - 1] * 2 % MOD;
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 0; i < 30; i++) for(int j = 1; j <= N; j++) D[i][j] = 0;
		for(int i = 1; i <= N; i++) ans[i] = (1 << 30) - 1;
		for(int i = 1; i <= M; i++) {
			int a, b, c; scanf("%d%d%d", &a, &b, &c);
			for(int j = 0; j < 30; j++) {
				if(~c & 1 << j) {
					D[j][a]++; D[j][b + 1]--;
				}
			}
		}

		for(int i = 0; i < 30; i++) {
			int s = 0;
			for(int j = 1; j <= N; j++) {
				s += D[i][j];
				if(s > 0) ans[j] ^= 1 << i;
			}
		}

		ll tot = 0;
		for(int i = 0; i < 30; i++) {
			int cnt1 = 0;
			for(int j = 1; j <= N; j++) if(ans[j] & 1 << i) cnt1++;
			if(!cnt1) continue;
			ll t = pw[cnt1 - 1] * (1 << i) % MOD * pw[N - cnt1] % MOD;
			tot = (tot + t) % MOD;
		}
		printf("%lld\n", tot);
	}
	return 0;
}