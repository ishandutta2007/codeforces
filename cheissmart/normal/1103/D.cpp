#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7, N = 1e6 + 7, M = 12000;

ll a[N], dp[12][1 << 11], pw[11][50];
vi ok_mask[N], ok_i[1 << 11];
int e[N];

signed main()
{
	IO_OP;
	
	int n;
	ll k, g = 0;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		g = __gcd(g, a[i]);
	}
	for(int i = 0; i < n; i++)
		cin >> e[i];
	V<ll> ps;
	for(ll i = 2; i * i <= g; i++)
		if(g % i == 0) {
			ps.PB(i);
			while(g % i == 0) g /= i;
		}
	if(g != 1) ps.PB(g);

	if(ps.empty()) return cout << 0 << '\n', 0;
	assert(int(ps.size()) <= 11);

	for(int i = 0; i < int(ps.size()); i++) {
		pw[i][0] = 1;
		for(int j = 1; j < 50 && pw[i][j - 1] < ll(1e12); j++)
			pw[i][j] = pw[i][j - 1] * ps[i];
	}

	auto normalize = [&] (ll x) {
		vi res(ps.size());
		for(int i = 0; i < int(ps.size()); i++) {
			while(x % ps[i] == 0) {
				x /= ps[i];
				res[i]++;
			}
		}
		return res;
	};

	map<vi, vi> mp;
	for(int i = 0; i < n; i++) {
		vi res = normalize(a[i]);
		mp[res].PB(i);
	}

	auto add = [&] (vi v, int i) {
		function<void(int, int, ll)> dfs = [&] (int j, int mask, ll x) {
			if(x > k) return;
			if(j == int(ps.size())) {
				// ok_mask[i].PB(mask);
				ok_i[mask].PB(i);
				return;
			}
			dfs(j + 1, mask, x);
			dfs(j + 1, mask | (1 << j), x * pw[j][v[j]]);
		};
		dfs(0, 0, 1);
	};

	for(auto& p:mp) {
		sort(ALL(p.S), [&] (int i, int j) {
			return e[i] < e[j];
		});
		for(int i = 0; i < int(min(p.S.size(), ps.size())); i++) {
			add(p.F, p.S[i]);
		}
	}
	for(int mask = 1; mask < (1 << ps.size()); mask++) {
		sort(ALL(ok_i[mask]), [&] (int i, int j) {
			return e[i] < e[j];
		});
		for(int i = 0; i < int(min(ps.size(), ok_i[mask].size())); i++)
			ok_mask[ok_i[mask][i]].PB(mask);
	}

	memset(dp, -1, sizeof dp);
	dp[0][0] = 0;
	auto upd = [&] (ll& dp_val, ll val) {
		assert(val != -1);
		if(dp_val == -1) dp_val = val;
		else dp_val = min(dp_val, val);
	};
	for(int i = 0; i < n; i++) {
		for(int j = int(ps.size()) - 1; j >= 0; j--) {
			for(int mask:ok_mask[i]) {
				int tot = ((1 << ps.size()) - 1) ^ mask;
				for(int from = tot; ; from = tot & (from - 1)) {
					if(dp[j][from] != -1)
						upd(dp[j + 1][from | mask], dp[j][from] + e[i]);
					if(from == 0) break;
				}
			}
		}
	}
	ll ans = -1;
	int mask = ((1 << ps.size()) - 1);
	debug(mask);
	for(int i = 0; i <= int(ps.size()); i++)
		if(dp[i][mask] != -1)
			upd(ans, dp[i][mask] * i);

	cout << ans << '\n';

}