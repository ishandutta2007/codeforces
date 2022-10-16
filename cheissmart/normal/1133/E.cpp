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

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 5005;

int a[N], dp[N][N];

signed main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a, a+n);
	V<pi> v(1);
	for(int i=0;i<n;) {
		int j = i;
		while(i < n && a[i] == a[j]) i++;
		v.EB(a[j], i - j);
	}
	for(int i=0;i<=n;i++)
		for(int j=0;j<=k;j++)
			dp[i][j] = -INF;
	dp[0][0] = 0;
	for(int i=1;i<v.size();i++) {
		for(int j=0;j<=k;j++) {
			dp[i][j] = dp[i-1][j];
			int cnt = 0;
			for(int l=i;l>=1&&v[i].F - v[l].F <= 5;l--) {
				cnt += v[l].S;
				if(j) dp[i][j] = max(dp[i][j], dp[l-1][j-1] + cnt);
			}
		}		
	}
	int mx = 0;
	for(int i=1;i<=k;i++)
		mx = max(mx, dp[v.size()-1][i]);
	cout << mx << endl;
	
}