#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

void solve() {
	int n, k;
	string s;
 	cin >> n >> k >> s;
	V<string> dp(n + 1, string(1, char('z' + 1)));
	dp[0] = "";
	for(int i = 1; i <= n; i++) {
		char c = s[i - 1];
		char cc = min({c, char('a' + (c - 'a' + 1) % k), char('a' + (c - 'a' + k - 1) % k)});
		// D or U
		dp[i] = min(dp[i], dp[i - 1] + cc);
		// L
		if(i >= 2)
			dp[i] = min(dp[i], dp[i - 1].substr(0, i - 2) + c + dp[i - 1].back());
		// R + (U or D)
		if(i >= 2)
			dp[i] = min(dp[i], dp[i - 2] + cc + s[i - 2]);
		// RL
		if(i >= 3)
			dp[i] = min(dp[i], dp[i - 2].substr(0, i - 3) + s[i - 1] + dp[i - 2].back() + s[i - 2]);
	}	
	cout << dp[n] << '\n';
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) solve();

}