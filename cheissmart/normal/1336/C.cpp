#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 3003, M = 998244353;

int dp[N][N];

signed main()
{
	IO_OP;
	
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	s = ' ' + s;
	t = ' ' + t;
	for(int i=1;i<=m+1;i++) dp[0][i] = 1;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		dp[i][m+1] = dp[i-1][m+1] * 2 % M;
		for(int j = 1; j <= m; j++) {
			if(s[i] == t[j]) dp[i][j] += dp[i-1][j+1];
			if(i+j-1>m || s[i] == t[i+j-1]) dp[i][j] += dp[i-1][j];
			dp[i][j] %= M;
		}
		if(i >= m) ans += dp[i][1];
	}
	ans %= M;
	cout << ans << endl;

}