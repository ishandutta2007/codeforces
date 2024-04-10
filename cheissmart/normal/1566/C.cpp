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

const int INF = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	s = ' ' + s;
	t = ' ' + t;
	auto go = [&] (vi v) -> int{
		bool yes[2] = {};
		for(int i:v) {
			assert(i);
			yes[s[i] - '0'] = 1;
			yes[t[i] - '0'] = 1;
		}
		if(yes[0] == 0)
			return 0;
		if(yes[1] == 0)
			return 1;
		return 2;
	};
	vi dp(n + 1);
	for(int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + go({i});
		if(i - 2 >= 0)
			dp[i] = max(dp[i], dp[i - 2] + go({i - 1, i}));
	}
	cout << dp[n] << '\n';
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