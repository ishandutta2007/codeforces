#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll read() {
	char c = getchar(); ll x = 0, f = 1;
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

const int N = 1000005;

int n, buc[N], cnt[N]; int tp;
ll a[N], stk[N]; ll ans = 1;

void divide(ll x) {
	tp = 0;
	for (ll i = 1; i * i <= x; i++)
		if (x % i == 0) {
			stk[++tp] = i; if (i * i != x) stk[++tp] = x / i;
		}
	sort(stk + 1, stk + tp + 1);
}
int lar_rand() {
	return (rand() << 10) | rand();
}

int main() {
	srand(time(NULL));
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int tt = 1; tt <= 10; tt++) {
		ll now = a[lar_rand() % n + 1]; divide(now);
		for (int i = 1; i <= tp; i++) buc[i] = cnt[i] = 0;
		for (int i = 1; i <= n; i++) {
			int p = lower_bound(stk + 1, stk + tp + 1, __gcd(now, a[i])) - stk; 
			buc[p]++;
		}
		for (int i = 1; i <= tp; i++)
			for (int j = i; j <= tp; j++) if (stk[j] % stk[i] == 0) cnt[i] += buc[j];
		for (int i = 1; i <= tp; i++)
			if (cnt[i] >= ((n + 1) >> 1)) ans = max(ans, stk[i]); 
	}
	printf("%lld\n", ans);
	return 0;
}