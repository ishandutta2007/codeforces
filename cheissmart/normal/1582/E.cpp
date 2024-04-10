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
const ll oo = 1e18;

void solve() {
	int n;
	cin >> n;
	vi a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	V<V<ll>> dp(n + 1, V<ll>(500, -oo));
	dp[n][0] = oo;
	for(int i = n - 1; i >= 0; i--) {
		dp[i][0] = oo;		
		ll sum = 0;
		for(int j = 1; j < 500 && i + j <= n; j++) {
			dp[i][j] = dp[i + 1][j];
			sum += a[i + j - 1];
			if(sum < dp[i + j][j - 1])
				dp[i][j] = max(dp[i][j], sum);
		}
	}
	int ans = 0;
	for(int i = 1; i < 500; i++)
		if(dp[0][i] > 0)
			ans = i;
	cout << ans << '\n';
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