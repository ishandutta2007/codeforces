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

int c[105], dp[101][101][101];

int32_t main()
{
	IO_OP;
	
	int n;
	string s;
	cin >> n >> s;
	for(int i=1;i<=n;i++)
		cin >> c[i];
	
	for(int len=1;len<=n;len++) {
		for(int i=0;i+len-1<n;i++) {
			int j = i + len - 1;
			for(int k=1;k<=n;k++) {
				dp[i][j][k] = dp[i+1][j][1] + c[k];
				for(int l=i+1;l<=j;l++) {
					if(s[l] == s[i])
						dp[i][j][k] = max(dp[i][j][k], dp[i+1][l-1][1]+dp[l][j][k+1]);
				}
			}
		}
	}
	cout << dp[0][n-1][1] << endl;
}