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

int dp[100005][2][2];

int f(int n, int m) {
	if(n > m) swap(n, m);
	if(n == 1) {
		int ret = 0;
		for(int i=0;i<2;i++) for(int j=0;j<2;j++)
			ret += dp[m][i][j];
		return ret%M;
	}
	int ret = f(n-1, m-1);
	if(n == 2) ret++;
	else {
		for(int i=0;i<2;i++) for(int j=0;j<2;j++) ret += dp[n-2][i][j];
	}
	if(m == 2) ret++;
	else {
		for(int i=0;i<2;i++) for(int j=0;j<2;j++) ret += dp[m-2][i][j];
	}
	return ret % M;
}

int32_t main()
{
	IO_OP;
	
	dp[1][0][0] = 1;
	for(int i=2;i<100005;i++) {
		for(int j=0;j<2;j++) {
			dp[i][j][0] = (dp[i-1][j^1][0] + dp[i-1][j^1][1]) % M;
			dp[i][j][1] = dp[i-1][j][0];
		}
	}

	int n, m;
	cin >> n >> m;
	cout << (f(n, m)*2)%M << endl;
}