#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const LL INF = 0x3f3f3f3f3f3f3f3f;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

priority_queue<pair<LL, PII>, vector<pair<LL, PII> >, greater<pair<LL, PII> > > que;
int n, m, mat[505][505];
LL dp[505][505];
bool vis[505][505];
void solve()
{
	scanf("%d", &n);
	m = 2 * n;
	rep(i, m) rep(j, m) scanf("%d", &mat[i][j]);
	
	LL sum = 0;
	int ans = INF;
	rep(i, n) rep(j, n) {
		sum += mat[i + n][j + n]; mat[i + n][j + n] = 0;
	}
	ans = min(ans, mat[0][n]);
	ans = min(ans, mat[0][m - 1]);
	ans = min(ans, mat[n - 1][n]);
	ans = min(ans, mat[n - 1][m - 1]);
	ans = min(ans, mat[n][0]);
	ans = min(ans, mat[n][n - 1]);
	ans = min(ans, mat[m - 1][0]);
	ans = min(ans, mat[m - 1][n - 1]);
	printf("%lld\n", sum + ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0; 
}