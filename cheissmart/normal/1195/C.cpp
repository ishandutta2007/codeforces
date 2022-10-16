#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[2][100005], dp[3][100005];

int32_t main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<2;i++)
		for(int j=0;j<n;j++)
			cin >> a[i][j];
	dp[0][0] = a[0][0];
	dp[1][0] = a[1][0];
	for(int i=1;i<n;i++) {
		dp[0][i] = a[0][i] + max(dp[1][i-1] , dp[2][i-1]);
		dp[1][i] = a[1][i] + max(dp[0][i-1] , dp[2][i-1]);
		dp[2][i] = max(dp[0][i-1] , dp[1][i-1]);
	}
	cout << max(max(dp[0][n-1], dp[1][n-1]), dp[2][n-1]) << endl;
}