//vsp
#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; (a) <= i; i--)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

const int N = 800200;

struct seg {
	ll l, r;
	bool operator< (seg o) const {
		if (l != o.l)
			return l < o.l;
		return r > o.r;
	}
};

vector<seg> fix(vector<seg> v) {
	vector<seg> res;
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	ll rmax = 2e18;
	for (auto [l, r] : v) {
		if (rmax <= r)
			continue;
		res.push_back({l, r});
		rmax = min(rmax, r);
	}
	sort(res.begin(), res.end());
	return res;
}

int n, m;
ll a[N], l[N], r[N], dp[N];
vector<seg> v;

void solve() {
	cin >> n >> m;

	FOR(i, n)
		cin >> a[i];
	a[n++] = 1e18;
	sort(a, a + n);

	v.clear();
	FOR(i, m) {
		int l, r;
		cin >> l >> r;
		auto it = lower_bound(a, a + n, l);
		if (*it <= r)
			continue;
		v.push_back({l, r});
	}

	FOR(i, n)
		v.push_back({a[i], a[i]});

	v = fix(v);
	m = sz(v);

	FOR(i, m - 1) {
		assert(v[i].l < v[i + 1].l);
		assert(v[i].r < v[i + 1].r);
	}

	int j = 0;
	FOR(i, n) {
		l[i] = j;
		while (j < m && v[j].r <= a[i])
			j++;
		r[i] = j - 1;
	}

	FOR(i, m) dp[i] = 1e18;
	dp[m - 1] = 0;

	per(i, 0, n - 1) {
		set<ll> S;
		ll best = 1e18;

		rep(j, r[i], r[i + 1]) {
			assert(v[j].l >= a[i]);
			S.insert(v[j].l + dp[j + 1]);
		}

		int p = r[i];
		per(j, l[i], r[i] + 1) {
			assert(v[j].r <= a[i]);
			while (p < r[i + 1] && v[p].l - a[i] <= a[i] - v[j].r) {
				S.erase(v[p].l + dp[p + 1]);
				best = min(best, 2 * v[p].l + dp[p + 1]);
				p++;
			}
			dp[j] = best - 2 * a[i] + a[i] - v[j].r;
			if (!S.empty())
				dp[j] = min(dp[j], *S.begin() - a[i] + 2 * (a[i] - v[j].r));
		}
	}
	cout << dp[0] << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}