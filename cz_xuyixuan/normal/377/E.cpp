#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int INF  = 1e8 + 7;
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
int n, m; ll goal;
pair <int, int> a[MAXN];
pair <int, int> dp[MAXN];
ll getvalue(pair <int, ll> s, int x) {
	return 1ll * x * s.first + s.second;
}
int main() {
	read(m), read(goal);
	for (int i = 1; i <= m; i++)
		read(a[i].second), read(a[i].first);
	sort(a + 1, a + m + 1, [&] (pair <int, int> x, pair <int, int> y) {
		return x.first < y.first || (x.first == y.first && x.second > y.second);
	});
	for (int i = 1; i <= m + 1; i++)
		if (a[i].second > a[n].second) {
			a[++n] = a[i];
			dp[n] = make_pair(INF, 0);
		}
	if (a[1].first != 0) {
		cout << 0 << endl;
		return 0;
	}
	dp[1] = make_pair(0, 0); int l = 1, r = 1;
	static pair <pair <int, ll>, pair <int, int>> s[MAXN];
	s[1] = make_pair(make_pair(a[1].second, 0), make_pair(0, INF));
	for (int i = 2; i <= n; i++) {
		while (getvalue(s[l].first, s[l].second.second) < a[i].first) l++;
		dp[i].first = (a[i].first - s[l].first.second - 1) / s[l].first.first + 1;
		dp[i].second = (s[l].first.second + 1ll * s[l].first.first * dp[i].first) - a[i].first;
		s[l].second.first = dp[i].first;
		
		pair <int, ll> cur = make_pair(a[i].second, dp[i].second - 1ll * dp[i].first * a[i].second);
		while (l <= r && getvalue(cur, s[r].second.first) >= getvalue(s[r].first, s[r].second.first)) r--;
		if (l > r) s[++r] = make_pair(cur, make_pair(dp[i].first, INF));
		else {
			s[r].second.second = INF;
			if (getvalue(cur, s[r].second.second) <= getvalue(s[r].first, s[r].second.second)) continue;
			int ql = s[r].second.first, qr = INF;
			while (ql < qr) {
				int mid = (ql + qr + 1) / 2;
				if (getvalue(cur, mid) <= getvalue(s[r].first, mid)) ql = mid;
				else qr = mid - 1;
			}
			s[r].second.second = ql;
			s[++r] = make_pair(cur, make_pair(ql + 1, INF));
		}
	}
	ll ans = LLONG_MAX;
	for (int i = 1; i <= n; i++) {
		if (dp[i].second >= goal) chkmin(ans, 1ll * dp[i].first);
		else {
			ll delta = goal - dp[i].second;
			chkmin(ans, dp[i].first + (delta - 1) / a[i].second + 1);
		}
	}
	cout << ans << endl;
	return 0;
}