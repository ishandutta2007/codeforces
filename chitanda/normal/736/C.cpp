//int!
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)
#define all(a) a.begin(), a.end()
inline int ckmax(int &a, int b) { return a < b ? a = b, 1 : 0; }
inline int ckmin(int &a, int b) { return a > b ? a = b, 1 : 0; }
#define clean(a) memset(a, 0, sizeof(a))
typedef long long ll;
#define M 1000000007

const int maxn = 110, maxk = 25;
int n, k;
int f[maxn][maxk][maxk], dp[maxk][maxk];
vector<int> g[maxn];

void dfs(int t, int fa){
	f[t][k + 1][1] = 1;
	f[t][0][0] = 1;

	for(auto v : g[t]){
		if(v == fa) continue;
		dfs(v, t);
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i <= k + 1; ++i)
			for(int j = 0; j <= k + 1; ++j)
				if(f[t][i][j])
					for(int ii = 0; ii <= k + 1; ++ii)
						for(int jj = 0; jj <= k; ++jj)
							(dp[min(i, ii + 1)][max(j, jj + 1)] += (ll)f[t][i][j] * f[v][ii][jj] % M) %= M;
		memcpy(f[t], dp, sizeof(dp));
	}

	memset(dp, 0, sizeof(dp));
	for(int i = 0; i <= k + 1; ++i)
		for(int j = 0; j <= k + 1; ++j)
			if(i + j <= k + 1) (dp[i][0] += f[t][i][j]) %= M;
			else (dp[i][j] += f[t][i][j]) %= M;
	memcpy(f[t], dp, sizeof(dp));
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	int u, v;
	for(int i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1, 0);

	int res = 0;
	for(int i = 0; i <= k + 1; ++i)
		(res += f[1][i][0]) %= M;

	printf("%d\n", res);
  return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                BUG
*/