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

const int INF = 1e18 + 7, N = 1e5 + 7;

int a[N], dp[N][5];

signed main()
{
	IO_OP;
	
	memset(dp, 0x3f, sizeof dp);
	int n;
	string s;
	cin >> n >> s;
	for(int i=0;i<n;i++)
		cin >> a[i];
	if(s[0] == 'h') {
		dp[0][0] = a[0];
		dp[0][1] = 0;
	} else{
		dp[0][0] = 0;
	}
	for(int i=1;i<n;i++) {
		for(int j=0;j<4;j++) {
			if(j == 0) {
				dp[i][j] = dp[i-1][j] + (s[i] == 'h' ? a[i] : 0);
			} else if(j == 1) {
				if(s[i] == 'h') {
					dp[i][j] = min(dp[i][j], dp[i-1][j]);
					dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
				} else if(s[i] == 'a') {
					dp[i][j] = min(dp[i][j], dp[i-1][j] + a[i]);
				} else {
					dp[i][j] = min(dp[i][j], dp[i-1][j]);
				}
			} else if(j == 2) {
				if(s[i] == 'a') {
					dp[i][j] = min(dp[i][j], dp[i-1][j]);
					dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
				} else if(s[i] == 'r') {
					dp[i][j] = min(dp[i][j], dp[i-1][j] + a[i]);
				} else {
					dp[i][j] = min(dp[i][j], dp[i-1][j]);
				}
			} else if(j == 3) {
				if(s[i] == 'r') {
					dp[i][j] = min(dp[i][j], dp[i-1][j]);
					dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
				} else if(s[i] == 'd') {
					dp[i][j] = min(dp[i][j], dp[i-1][j] + a[i]);
				} else {
					dp[i][j] = min(dp[i][j], dp[i-1][j]);
				}
			}
		}
	}
	int mn = INF;
	for(int i=0;i<4;i++)
		mn = min(dp[n-1][i], mn);
	cout << mn << endl;

	
}