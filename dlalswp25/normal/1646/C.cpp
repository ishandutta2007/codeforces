#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int B = 14;
const int INF = 1010101010;

ll F[15];

int f(ll x) {
	int ret = 0;
	while(x) {
		ret += x & 1;
		x >>= 1;
	}
	return ret;
}

int main() {
	F[0] = 1;
	for(int i = 1; i <= B; i++) F[i] = F[i - 1] * i;
	int tc; scanf("%d", &tc);
	while(tc--) {
		ll N; scanf("%lld", &N);
		int ans = INF;
		for(int i = 0; i < 1 << B - 2; i++) {
			ll s = 0;
			int cnt = 0;
			for(int j = 0; j < B - 2; j++) {
				if(i & 1 << j) {
					cnt++;
					s += F[j + 3];
				}
			}
			if(s > N) continue;
			ans = min(ans, cnt + f(N - s));
		}
		printf("%d\n", ans);
	}
	return 0;
}