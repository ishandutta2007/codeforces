#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e4 + 5;
const int MAXM = 1e6 + 5;
const int MAXLOG = 18;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
int n, m, tot, a[MAXN];
pair <int, int> b[MAXM];
namespace rmq {
	int g[MAXN][MAXLOG], Log[MAXN];
	int query(int l, int r) {
		int len = r - l + 1, tmp = Log[len];
		return __gcd(g[l][tmp], g[r - (1 << tmp) + 1][tmp]);
	}
	void init() {
		for (int i = 1; i <= n; i++) {
			g[i][0] = a[i];
			Log[i] = Log[i - 1];
			if ((1 << (Log[i] + 1)) <= i) Log[i]++;
		}
		for (int t = 1; t < MAXLOG; t++)
		for (int i = 1, j = (1 << (t - 1)) + 1; j <= n; i++, j++)
			g[i][t] = __gcd(g[i][t - 1], g[j][t - 1]);
	}
}
ll func(int x, int y) {
	ll ans = y * (y + 1ll) / 2;
	ans += 1ll * y * (x - y);
	return ans;
}
ll solve(ll n, ll a, ll b, ll c) {
	if (a == 0) return (c / b) * (n + 1);
	else if (a >= b || c >= b) return solve(n, a % b, b, c % b) + n * (n + 1) / 2 * (a / b) + (n + 1) * (c / b);
	else {
		ll m = (n * a + c) / b;
		return n * m - solve(m - 1, b, a, b - c - 1);
	}
}
ll rangecnt(ll sum, ll a, ll b, ll n, ll m) {
	if (sum < 0) return 0;
	ll ans = 0;
	if (sum >= b * m) {
		ll tmp = (sum - b * m) / a;
		if (tmp >= n) return (n + 1) * (m + 1);
		ans += (tmp + 1) * (m + 1);
		sum -= (tmp + 1) * a;
		n -= tmp + 1;
	}
	if (sum < 0) return ans;
	chkmin(n, sum / a);
	ll c = sum - n * a;
	return ans + n + 1 + solve(n, a, b, c);
}
ll getcnt(ll sum) {
	ll ans = 0;
	for (int i = 1; i <= m; i++)
		ans += func(b[i].second, min(sum / b[i].first, 0ll + b[i].second));
	ll len = 0, cnt = 0;
	for (int i = 1, j = 1; i <= m; i++) {
		while (j < i && len + 1ll * b[i].first * b[i].second > sum) {
			cnt -= b[j].second;
			len -= 1ll * b[j].first * b[j].second; j++;
		}
		ans += b[i].second * cnt;
		ll tmp = len;
		for (int k = j - 1; k >= 1 && tmp <= sum; k--) {
			ans += rangecnt(sum - tmp - b[k].first - b[i].first, b[i].first, b[k].first, b[i].second - 1, b[k].second - 1);
			tmp += 1ll * b[k].first * b[k].second;
		}
		cnt += b[i].second;
		len += 1ll * b[i].first * b[i].second;
	}
	return ans;
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	rmq :: init();
	for (int i = 1; i <= n; i++) {
		int pos = i;
		while (pos <= n) {
			int g = rmq :: query(i, pos);
			int l = pos, r = n;
			while (l < r) {
				int mid = (l + r + 1) / 2;
				if (rmq :: query(i, mid) == g) l = mid;
				else r = mid - 1;
			}
			b[++tot] = make_pair(g, l - pos + 1);
			pos = l + 1;
		}
	}
	sort(b + 1, b + tot + 1);
	for (int i = 1; i <= tot; i++)
		if (b[i].first == b[m].first) b[m].second += b[i].second;
		else b[++m] = b[i];
	ll l = 0, r = 1e16, rk = n * (n + 1ll) / 2;
	rk = rk * (rk + 1) / 2, rk = (rk + 1) / 2;
	while (l < r) {
		ll mid = (l + r) / 2;
		if (getcnt(mid) < rk) l = mid + 1;
		else r = mid;
	}
	writeln(l);
	return 0;
}