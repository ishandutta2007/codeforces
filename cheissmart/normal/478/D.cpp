#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int M = 1e9 + 7;

int dp[2][201000];

int32_t main()
{
	IO_OP;
	
	int	r, g, h;
	cin >> r >> g;
	if(g == 0 || r == 0) {
		cout << 1 << endl;
		return 0;
	}
	dp[1][r] = 1, dp[1][r-1] = 1;
	for(h=2;h*(h+1)/2 <= r+g;h++) {
		for(int i=0;i<=r;i++) {
			int rg = g - (h*(h-1)/2 - (r - i));
			dp[h%2][i] = dp[(h-1)%2][i + h];
			if(rg >= h) dp[h%2][i] += dp[(h-1)%2][i];
			dp[h%2][i] %= M;
		}
	}
	h--;
	int ans = 0;
	for(int i=0;i<=r;i++) {
		ans += dp[h%2][i];
		ans %= M;
	}
	cout << ans << endl;
}