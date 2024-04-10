#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 1e6 + 5;

int n, a[N];
int cnt[N]; ll sc[N];
ll sum;

ll divx(ll x, ll y) {
	return x / y + 1;
}

ll ans;

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d", &n);
	fo(i, 1, n) scanf("%d", &a[i]), cnt[a[i]] ++;
	sort(a + 1, a + n + 1);
	fo(i, 1, 1e6) sc[i] = sc[i - 1] + cnt[i];
	fo(y, 2, 5e5) {
		sum = 0;
		fo(i, 1, 5e5 / y) sum += (sc[i * y + y - 1] - (i == 0 ?0 : sc[i * y - 1])) * i;
		if(sum == 0) continue;
		ll x = 0;
		for(ll l = 1, r = 5e5; l <= r;) {
			ll m = l + r >> 1;
			if(m <= sum - 2 * divx(m, y) + 2) x = m, l = m + 1; else r = m - 1;
		}
		x = min(x, (ll) a[n - 1]);
		fo(i, 0, 2) {
			if(x <= 1) break;
			int cnt1 = 0;
			fo(j, x / y, 5e5 / y) cnt1 += sc[j * y + y - 1] - sc[j * y + x % y - 1];
			ll t = sum - 2 * divx(x, y) + min(2, cnt1);
			if(x <= t) ans = max(ans, (ll) y * x);
			x --;
		}
	}
	fo(y, 2, 5e5) {
		sum = 0;
		fo(i, 1, 5e5 / y) sum += (sc[i * y + y - 1] - (i == 0 ? 0 : sc[i * y - 1])) * i;
		if(sum == 0) continue;
		ll x = 0;
		for(ll l = 1, r = 5e5; l <= r;) {
			ll m = l + r >> 1;
			if(m <= sum - divx(2 * m, y) + 1) x = m, l = m + 1; else r = m - 1;
		}
		x = min(x, (ll) a[n] / 2);
		fo(i, 0, 2) {
			if(x <= 1) break;
			int cnt1 = 0;
			ll c = 2 * x % y;
			fo(j, 2 * x / y, 5e5 / y) cnt1 += sc[j * y + y - 1] - sc[j * y + c - 1];
			ll t = sum - divx(2 * x, y) + min(1, cnt1);
			if(x <= t) ans = max(ans, (ll) y * x);
			x --;
		}
	}
	pp("%I64d\n", ans);
}