#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int cnt[34];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		for(int i = 0; i <= 30; i++) cnt[i] = 0;
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			int x; scanf("%d", &x);
			int b = 0;
			while(x) { b++; x >>= 1; }
			cnt[b]++;
		}
		ll ans = 0;
		for(int i = 1; i <= 30; i++) ans += (ll)cnt[i] * (cnt[i] - 1) / 2;
		printf("%lld\n", ans);
	}
	return 0;
}