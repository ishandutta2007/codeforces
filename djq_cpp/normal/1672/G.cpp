//CMO 2018 T5 

#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, m;
vector<int> G[4005];
char S[2005][2005];
int xv[4005];

bool vis[4005];
int ans[2];
int c0, c1, ce, cx;
void dfs(int v)
{
	vis[v] = true;
	c0 += xv[v] == -1;
	c1 += xv[v] != -1;
	ce += G[v].size();
	cx ^= xv[v] != -1 ? xv[v] : 0;
	rep(i, G[v].size()) if(!vis[G[v][i]]) dfs(G[v][i]);
}

int main()
{
	scanf("%d%d", &n, &m);
	rep(i, n) scanf("%s", S[i]);
	
	rep(i, n) xv[i] = m & 1 ? 0 : -1;
	rep(i, m) xv[i + n] = n & 1 ? 0 : -1;
	
	rep(i, n) rep(j, m) if(S[i][j] == '?') {
		G[i].push_back(j + n); G[j + n].push_back(i);
	} else {
		int v = S[i][j] - '0';
		xv[i] ^= v; xv[j + n] ^= v;
	}
	rep(i, n + m) if(xv[i] == -2) xv[i] = -1;
	
	ans[0] = ans[1] = 1;
	rep(i, n + m) if(!vis[i]) {
		c0 = c1 = ce = cx = 0;
		dfs(i); ce /= 2;
		
		int cur[2] = {0, 0};
		if(c0 == 0) {
			if(cx) ans[0] = 0;
			else cur[0] ++;
			if((cx ^ c1) & 1) ans[1] = 0;
			else cur[1] ++;
		}
		cur[0] += ce - c1;
		cur[1] += ce - c1;
		rep(j, cur[0]) ans[0] = 2 * ans[0] % MOD;
		rep(j, cur[1]) ans[1] = 2 * ans[1] % MOD;
	}
	printf("%d\n", (ans[0] + (!(n & 1) && !(m & 1) ? 0 : ans[1])) % MOD);
	return 0;
}