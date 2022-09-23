#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
bool ok[101010];
int mx[101010];
int mn[101010];
int cnt[1010101];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		int x; scanf("%d", &x);

		mx[i] = -1, mn[i] = 10101010;
		for(int j = 1; j <= x; j++) {
			int y; scanf("%d", &y);
			if(mn[i] < y) ok[i] = true;
			mn[i] = min(mn[i], y); mx[i] = max(mx[i], y);
		}

		if(!ok[i]) cnt[mx[i]]++;
	}

	for(int i = 1; i <= 1000000; i++) cnt[i] += cnt[i - 1];

	ll ans = 0;
	for(int i = 1; i <= N; i++) {
		if(ok[i]) continue;
		ans += cnt[mn[i]];
	}

	printf("%lld\n", (ll)N * N - ans);
	return 0;
}