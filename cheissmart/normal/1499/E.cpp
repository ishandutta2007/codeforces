#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1001, M = 998244353;

int dp[N][N][2];

void add(int& a, int b) {
	a += b;
	if(a >= M) a -= M;
}

signed main()
{
	IO_OP;
	
	string x, y;
	cin >> x >> y;
	int ans = 0;
	for(int i = int(x.size()); i >= 0; i--) {
		for(int j = int(y.size()); j >= 0; j--) {
			if(i == int(x.size()) && j == int(y.size())) continue;
			if(i == int(x.size())) {
				dp[i][j][1] = 1;
				if(j + 1 < int(y.size()) && y[j] != y[j + 1])
					dp[i][j][1] += dp[i][j + 1][1];
				continue;
			}
			if(j == int(y.size())) {
				dp[i][j][0] = 1;
				if(i + 1 < int(x.size()) && x[i] != x[i + 1])
					dp[i][j][0] += dp[i + 1][j][0];
				continue;
			}
			// 0
			if(i + 1 < int(x.size()) && x[i + 1] != x[i])
				add(dp[i][j][0], dp[i + 1][j][0]);
			if(y[j] != x[i]) {
				if(i + 1 < int(x.size())) add(dp[i][j][0], dp[i + 1][j][1]);
				add(dp[i][j][0], dp[int(x.size())][j][1]);
			}
			// 1
			if(j + 1 < int(y.size()) && y[j + 1] != y[j])
				add(dp[i][j][1], dp[i][j + 1][1]);
			if(y[j] != x[i]) {
				if(j + 1 < int(y.size())) add(dp[i][j][1], dp[i][j + 1][0]);
				add(dp[i][j][1], dp[i][int(y.size())][0]);
			}
			// cerr << "dp[" << i << "][" << j << "][0] = " << dp[i][j][0] << '\n';
			// cerr << "dp[" << i << "][" << j << "][1] = " << dp[i][j][1] << '\n';
			add(ans, dp[i][j][0]);
			add(ans, dp[i][j][1]);
		}
	}
	cout << ans << '\n';

}