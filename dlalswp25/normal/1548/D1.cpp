#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll cnt[4];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		int x, y; scanf("%d%d", &x, &y);
		cnt[(x >> 1 & 1) << 1 | (y >> 1 & 1)]++;
	}

	ll ans = 0;
	for(int i = 0; i < 4; i++) {
		ans = (ans + cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6);
	}

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if(i == j) continue;
			ans = (ans + cnt[i] * cnt[j] * (cnt[j] - 1) / 2);
		}
	}
	printf("%lld\n", ans);

	return 0;
}