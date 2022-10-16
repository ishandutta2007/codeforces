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

int dp[205][205][405];
struct P{
	int i, j, k;
	char c;
	P() {}
	P(int _i, int _j, int _k, char _c) {
		i = _i, j = _j, k = _k;
		c = _c;
	}
} pre[205][205][405];

signed main()
{
	IO_OP;
	
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	s = ' ' + s, t = ' ' + t;
	memset(dp, 0x3f, sizeof dp);
	for(int i=0;i<=n+m;i++)
		dp[0][0][i] = i;
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=m;j++) {
			if(i == 0 && j == 0) continue;
			bool rev = false;
			if(i == 0) {
				if(t[j] == '(') rev=  true;
			} else if(j == 0) {
				if(s[i] == '(') rev = true;
			} else {
				if(s[i] == '(' && t[j] == '(') rev = true;
			}
			if(rev) {
				for(int k=n+m;k>=0;k--) {
					// (
					if(k) {
						int ii = i, jj = j;
						if(i && s[i] == '(') ii--;
						if(j && t[j] == '(') jj--;
						// dp[i][j][k] = min(dp[i][j][k], dp[ii][jj][k-1] + 1);
						if(dp[ii][jj][k-1] + 1 < dp[i][j][k]) {
							dp[i][j][k] = dp[ii][jj][k-1] + 1;
							pre[i][j][k] = P(ii, jj, k-1, '(');
						}
					}
					// )
					if(k < n+m) {
						int ii = i, jj = j;
						if(i && s[i] == ')') ii--;
						if(j && t[j] == ')') jj--;
						// dp[i][j][k] = min(dp[i][j][k], dp[ii][jj][k+1] + 1);
						if(dp[ii][jj][k+1] + 1 < dp[i][j][k]) {
							dp[i][j][k] = dp[ii][jj][k+1] + 1;
							pre[i][j][k] = P(ii, jj, k+1, ')');
						}
					}
				}
			}
			else {
				for(int k=0;k<=n+m;k++) {
					// (
					if(k) {
						int ii = i, jj = j;
						if(i && s[i] == '(') ii--;
						if(j && t[j] == '(') jj--;
						// dp[i][j][k] = min(dp[i][j][k], dp[ii][jj][k-1] + 1);
						if(dp[ii][jj][k-1] + 1 < dp[i][j][k]) {
							dp[i][j][k] = dp[ii][jj][k-1] + 1;
							pre[i][j][k] = P(ii, jj, k-1, '(');
						}
					}
					// )
					if(k < n+m) {
						int ii = i, jj = j;
						if(i && s[i] == ')') ii--;
						if(j && t[j] == ')') jj--;
						// dp[i][j][k] = min(dp[i][j][k], dp[ii][jj][k+1] + 1);
						if(dp[ii][jj][k+1] + 1 < dp[i][j][k]) {
							dp[i][j][k] = dp[ii][jj][k+1] + 1;
							pre[i][j][k] = P(ii, jj, k+1, ')');
						}
					}
				}
			}
		}
	}
	int i = n, j = m, k = 0;
	string ans;
	while(i || j) {
		ans += pre[i][j][k].c;
		P tmp = pre[i][j][k];
		i = tmp.i;
		j = tmp.j;
		k = tmp.k;
	}
	for(int ii=0;ii<dp[i][j][k];ii++) ans += '(';
	reverse(ALL(ans));
	cout << ans << endl;
}