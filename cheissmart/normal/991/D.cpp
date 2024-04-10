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

string a[2];
int dp[102][2][2];

signed main()
{
	IO_OP;
	for(int i=0;i<102;i++)
		dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = -INF;
	cin >> a[0] >> a[1];
	dp[0][a[0][0] == 'X'][a[1][0] == 'X'] = 0;
	int n = a[0].size();
	for(int i=0;i<n-1;i++) {
		for(int j=0;j<2;j++) {
			for(int k=0;k<2;k++) {
				if(dp[i][j][k] < 0) continue;
				int x = a[0][i+1] == 'X', y = a[1][i+1] == 'X';
				dp[i+1][x][y] = max(dp[i+1][x][y], dp[i][j][k]);
				if(j == 0 && a[0][i+1] == '0' && a[1][i+1] == '0')
					dp[i+1][1][1] = max(dp[i+1][1][1], dp[i][j][k] + 1);
				if(k == 0 && a[0][i+1] == '0' && a[1][i+1] == '0')
					dp[i+1][1][1] = max(dp[i+1][1][1], dp[i][j][k] + 1);
				if(j == 0 && k == 0 && a[0][i+1] == '0'){
					x = 1, y = a[1][i+1] == 'X';
					dp[i+1][x][y] = max(dp[i+1][x][y], dp[i][j][k] + 1);
				}
				if(j == 0 && k == 0 && a[1][i+1] == '0'){
					x = a[0][i+1] == 'X', y = 1;
					dp[i+1][x][y] = max(dp[i+1][x][y], dp[i][j][k] + 1);
				}
			}
		}
	}
	cout << max({dp[n-1][0][0], dp[n-1][1][0], dp[n-1][0][1], dp[n-1][1][1]}) << endl;
}