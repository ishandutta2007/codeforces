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

const int INF = 1e9 + 7, N = 13;

int a[N][2048], dp[N][1<<N], pre[N][1<<N];

void solve() {
	memset(dp, 0, sizeof dp);
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=1;j<=m;j++)
			cin >> a[i][j];
	V<pi> v;
	for(int j=1;j<=m;j++) {
		int mx = 0;
		for(int i=0;i<n;i++)
			mx = max(mx, a[i][j]);
		v.EB(mx, j);
	}
	sort(ALL(v)); reverse(ALL(v));
	for(int i=1;i<=min(n, m);i++) {
		for(int k=0;k<(1<<n);k++) {
			int mx = 0;
			for(int s=0;s<n;s++) {
				int sm = 0;
				for(int l=0;l<n;l++) {
					if(k>>l&1)
						sm += a[(l+s)%n][v[i-1].S];
				}
				mx = max(mx, sm);
			}
			pre[i][k] = mx;
		}
	}
	for(int i=1;i<=min(n, m);i++) {
		for(int j=0;j<(1<<n);j++) {
			for(int k=j;;k=(k-1)&j) {
				dp[i][j] = max(dp[i][j], pre[i][k] + dp[i-1][j^k]);
				if(k == 0) break;
			}
		}
	}
	cout << dp[min(n, m)][(1<<n)-1] << endl;
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