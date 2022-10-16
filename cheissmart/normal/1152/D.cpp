#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int dp[2048][1024], full[2048][1024];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=2*n;i++) {
		for(int j=0;j<=n;j++) {
			int children_num = 0, full_num = 0;
			if (j-1>=0)
				dp[i][j] += dp[i-1][j-1], children_num += 1, full_num += full[i-1][j-1];
			if (j+1<=i-1)
				dp[i][j] += dp[i-1][j+1], children_num += 1, full_num += full[i-1][j+1];
			if (full_num < children_num)
				dp[i][j] += (full[i][j] = 1);
			dp[i][j] %= 1000000007;
		}
	}
	cout << dp[2*n][0] << endl;
	
}