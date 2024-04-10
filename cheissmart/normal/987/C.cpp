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

const int INF = 0x3f3f3f3f3f3f3f3f;

int dp[3003][3], a[3003], b[3003];

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++) cin >> b[i];
	memset(dp, 0x3f, sizeof dp);
	int ans = INF;
	for(int i=0;i<n;i++) {
		dp[i][0] = b[i];
		for(int j=1;j<3;j++) {
			for(int k=0;k<i;k++) {
				if(a[k] < a[i]) {
					dp[i][j] = min(dp[i][j], dp[k][j-1] + b[i]);
				}
			}
		}
		ans = min(ans, dp[i][2]);
	}
	if(ans == INF) ans = -1;
	cout << ans << endl;

}