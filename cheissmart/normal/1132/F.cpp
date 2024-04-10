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
	string s;
	cin >> n >> s;
	for(int i=0;i<n;i++)
		dp[i][i] = 1;
	for(int len = 2; len <= n;len++) {
		for(int l=0;l<=n-len;l++) {
			int r = l + len - 1;
			dp[l][r] = dp[l+1][r] + 1;
			for(int i=l+1;i<=r;i++) {
				if(s[i] == s[l]) {
					dp[l][r] = min(dp[l][r], dp[l+1][i-1]+dp[i][r]);
				}
			}
		}
	}
	cout << dp[0][n-1] << endl;
	
	
}