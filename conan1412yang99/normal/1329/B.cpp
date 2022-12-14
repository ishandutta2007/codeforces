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

const int INF = 1e9 + 7;

int dp[33];

void solve() {
	memset(dp, 0, sizeof dp);
	int d, m;
	cin >> d >> m;
	dp[0] = 1 % m;
	int ans = 0;
	int len = __lg(d)+1;
	for(int i=1;i<=len;i++) {
		if(i == len)  {
			for(int j=0;j<i;j++) {
				dp[i] = ((dp[i] + dp[j] * (d - (1LL << (len - 1)) + 1) % m) % m) % m;
			}
		}
		else {
			for(int j=0;j<i;j++) {
				dp[i] = (dp[i] + dp[j] * ((1LL << (i-1))) % m) % m;
			}
		}
		ans += dp[i];
	}
	ans %= m;
	cout << ans << endl;
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