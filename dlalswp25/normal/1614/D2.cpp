#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MX = 20000000;

int N;
map<int, int> mp;
int cnt[20202020];
ll D[20202020];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		int a; scanf("%d", &a);
		for(int j = 1; j * j <= a; j++) {
			if(a % j) continue;
			cnt[j]++;
			if(j * j != a) cnt[a / j]++;
		}
	}

	ll ans = 0;
	for(int i = MX; i >= 1; i--) {
		if(!cnt[i]) continue;
		D[i] = (ll)cnt[i] * i;
		for(int j = i + i; j <= MX; j += i) {
			if(cnt[j]) D[i] = max(D[i], D[j] + (ll)(cnt[i] - cnt[j]) * i);
		}
		ans = max(ans, D[i]);
	}
	printf("%lld\n", ans);

	return 0;
}