#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll A[5050];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	ll ans = 1LL << 60;
	for(int i = 1; i <= N; i++) {
		ll cnt = 0;
		ll x = 0;
		for(int j = i - 1; j >= 1; j--) {
			ll t = x / A[j] + 1;
			cnt += t;
			x = t * A[j];
		}
		x = 0;
		for(int j = i + 1; j <= N; j++) {
			ll t = x / A[j] + 1;
			cnt += t;
			x = t * A[j];
		}
		ans = min(ans, cnt);
	}
	printf("%lld\n", ans);
	return 0;
}