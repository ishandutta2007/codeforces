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

const int M = 1e9 + 7;

int dp[200005][3];

signed main()
{
	IO_OP;
	
	int n, l, r;
	cin >> n >> l >> r;
	int a[3];
	a[0] = r / 3 - (l - 1) / 3;
	a[1] = (r - 1) / 3 - (l - 2) / 3 + (l <= 1 && 1 <= r);
	a[2] = (r - 2) / 3 - (l - 3) / 3 + (l <= 2 && 2 <= r);
	dp[0][0] = a[0], dp[0][1] = a[1], dp[0][2] = a[2];
	for(int i=1;i<n;i++) {
		for(int j=0;j<3;j++) {
			for(int k=0;k<3;k++) {
				dp[i][j] = (dp[i][j] + a[k] * dp[i-1][(j-k+3)%3] % M) % M;
			}
		}
	}
	cout << dp[n-1][0] << endl;
}