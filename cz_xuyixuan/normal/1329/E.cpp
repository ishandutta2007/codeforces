#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 5;
const long long INF = 1e15;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
ll n, k, a[MAXN], b[MAXN]; int m;
ll getu() {
	ll l = 1, r = INF;
	while (l < r) {
		ll mid = (l + r) / 2, sum = 0;
		for (int i = 1; i <= m; i++)
			if (a[i] % mid == 0) sum += a[i] / mid;
			else sum += a[i] / mid + 1;
		if (sum <= k) r = mid;
		else l = mid + 1;
	}
	return l;
}
ll getd() {
	ll l = 1, r = INF;
	while (l < r) {
		ll mid = (l + r + 1) / 2, sum = 0;
		for (int i = 1; i <= m; i++) {
			if (a[i] / mid == 0) sum = -INF;
			else sum += a[i] / mid;
		}
		if (sum >= k) l = mid;
		else r = mid - 1;
	}
	return l;
}
int main() {
	int T; read(T);
	while (T--) {
		read(n), read(m), read(k);
		for (int i = 1; i <= m; i++)
			read(b[i]);
		b[++m] = n, k += m;
		for (int i = 1; i <= m; i++)
			a[i] = b[i] - b[i - 1];
		ll u = getu(), d = getd();
		vector <pair <ll, ll>> inc;
		for (int i = 1; i <= m; i++) {
			ll x = a[i] / u;
			if (a[i] % u != 0) x++;
			if (a[i] / x < d) {
				ll y = a[i] / d;
				x = a[i] / x;
				if (a[i] % y == 0) y = a[i] / y;
				else y = a[i] / y + 1;
				if (x == 0) inc.emplace_back(-INF, y);
				else inc.emplace_back(x, y);
			}
		}
		if (inc.empty()) printf("%lld\n", u - d);
		else {
			sort(inc.begin(), inc.end(), [&] (pair <ll, ll> a, pair <ll, ll> b) {
				return a.first < b.first;
			});
			ll Max = u, ans = INF;
			for (auto x : inc) {
				chkmin(ans, Max - x.first);
				chkmax(Max, x.second);
			}
			chkmin(ans, Max - d);
			printf("%lld\n", ans);
		}
	}
	return 0;
}