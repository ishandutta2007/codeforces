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

const int INF = 1e9 + 7;

int w[20][20], dp[1<<20], pre[20][1<<20], n, m;

int32_t main()
{
	IO_OP;
	
	memset(dp, 0x3f, sizeof dp); dp[0] = 0;
	string s;
	cin >> n >> m >> s;	
	for(int i=0, x, y;i<n-1;i++) if((x = s[i] - 'a') != (y = s[i+1] - 'a')) w[x][y] = ++w[y][x];
	for(int i=0;i<m;i++) for(int j=1;j<(1<<m);j++) if(!(j>>i&1))
		pre[i][j] = w[i][31 - __builtin_clz(j & -j)] + pre[i][j ^ (j & -j)];
	for(int i=1;i<(1<<m);i++) for(int j=0;j<m;j++) if(i >> j & 1)
			dp[i] = min(dp[i], dp[i^(1<<j)]+(pre[j][i^(1<<j)]-pre[j][((1<<m)-1)^i])*__builtin_popcount(i));
	cout << dp[(1<<m)-1] << endl;
}