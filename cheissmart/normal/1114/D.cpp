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

const int INF = 1e9 + 7, N = 5003;

int l[N], r[N], bl[N], a[N], dp[N][N];

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	int b = 0;
	for(int i=1;i<=n;) {
		int j = i;
		b++;
		while(a[i] == a[j]){
			bl[i] = b;
			i++;
		}
		l[b] = j, r[b] = i - 1;
	}
	memset(dp, 0x3f, sizeof dp);
	dp[1][n] = 0;
	for(int len = n-1;len >= 0;len--) {
		for(int i=1;i+len-1<=n;i++) {
			int j = i + len - 1;
			if(i == 1) {
				dp[i][j] = 1 + dp[i][r[bl[j+1]]];
			} else if( j == n) {
				dp[i][j] = 1 + dp[l[bl[i-1]]][j];
			} else {
				if(a[i-1] == a[j+1]) {
					dp[i][j] = dp[l[bl[i-1]]][r[bl[j+1]]] + 1;
				} else {
					dp[i][j] = min(dp[i][r[bl[j+1]]], dp[l[bl[i-1]]][j]) + 1;
				}
			}
		}
	}
	int ans = INF;
	for(int i=1;i<=b;i++)
		ans = min(ans, dp[l[i]][r[i]]);
	cout << ans << endl;
}