#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int dp[505][505];

int main()
{
	IO_OP;
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dp[i][j] = INF;
	for(int i=1;i<n;i++)
		dp[i][i+1] = 0;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			for(int k=j+1;k<j+i && k <= n;k++) {
				dp[j][j+i] = min(dp[j][j+i], dp[j][k] + dp[k][j+i] + j * (j + i) * k);
			}
		}
	}
	cout << dp[1][n] << endl;
	
}