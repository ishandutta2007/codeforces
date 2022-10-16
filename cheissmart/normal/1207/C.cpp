#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e17 + 7;

int dp[200005][2];

int32_t main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n, a, b;
		string s;
		cin >> n >> a >> b >> s;
		dp[0][0] = a + 2 * b;
		dp[0][1] = 2 * a + 3 * b;
		for(int i=1;i<n;i++) {
			if(s[i] == '1'){
				dp[i][0] = INF;
				dp[i][1] = dp[i-1][1] + a + 2*b;
			}
			else {
				dp[i][0] = min(dp[i-1][0] + a + b, dp[i-1][1] + 2 * a + b);
				dp[i][1] = min(dp[i-1][1] + a + 2*b, dp[i-1][0] + 2*a + 2*b);
			}
		}
		cout << dp[n-1][0] << endl;
	}
	
}