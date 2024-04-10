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

const int INF = 1e9 + 7, N = 2e5 + 7;

int a[N];
pi dp[N][2];

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) {
			dp[i][0] = dp[i-1][0];
			dp[i][1] = dp[i-1][1];
			if(a[i] < 0) {
				dp[i][0] = max(dp[i][0], {dp[i-1][1].F + 1, dp[i-1][1].S + a[i]});
			} else {
				dp[i][1] = max(dp[i][1], {dp[i-1][0].F + 1, dp[i-1][0].S + a[i]});
			}
		}

		cout << max(dp[n][0], dp[n][1]).S << endl;
		for(int i = 0; i <= n; i++) dp[i][0] = dp[i][1] = {0, 0};
	}

}