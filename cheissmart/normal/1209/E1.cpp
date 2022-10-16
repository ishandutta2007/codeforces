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
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int a[5][105], dp[105][1<<5];

void solve() {
	memset(dp, 0, sizeof dp);
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=1;j<=m;j++)
			cin >> a[i][j];
	for(int i=1;i<=m;i++) {
		for(int j=0;j<(1<<n);j++) {
			for(int k=j;;k=(k-1)&j) {
				for(int s=0;s<n;s++) {
					int sm = 0;
					for(int l=0;l<n;l++) {
						if(k>>l&1)
							sm += a[(l+s)%n][i];
					}
					dp[i][j] = max(dp[i][j], sm + dp[i-1][j^k]);
				}
				if(k == 0) break;
			}
		}
	}
	cout << dp[m][(1<<n)-1] << endl;
}

int32_t main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		solve();
	} 

}