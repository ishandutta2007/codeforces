#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())
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

const int INF = 1e9 + 7;

map<pair<ll, ll>, ll> memo;

ll go(ll n, ll m, ll tot) {
	if(memo.count({n, m}) == 0) {
		memo[{n, m}] = [&] () {
			// match [0, m - 1] and [n, n + m - 1]
			assert(n + m - 1 < tot);
			if(n == 0) return m;
			assert(tot > 1);
			// [0, tot / 2 - 1], [tot / 2, tot]
			if(n + m - 1 < tot / 2)
				return go(n, m, tot / 2);
			if(n >= tot / 2)
				return m - go(n - tot / 2, m, tot / 2);
			return go(n, tot / 2 - n, tot) + n + m - tot / 2 - go(tot / 2 - n, n + m - tot / 2, tot);
		}();
	}
	return memo[{n, m}];
}

void solve() {
	ll n, m;
	cin >> n >> m;
	cout << m - go(n, m, 1LL << 61) << endl;
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	
}