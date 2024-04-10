#include <stdio.h>
#include <vector>
#define MOD 1000000007

using namespace std;

vector<int> _adj[100005];
vector<int> adj[100005];
int N, M, k, x;
int dp[100005][15][3];
int tmpdp[100005][15][3];

int noRoot(int par, int from, int left, int state);
int DFS(int now, int left, int state);

void _dfs(int now, int par) {
	for(int i = 0; i < _adj[now].size(); i++) {
		if(par == _adj[now][i]) continue;
		adj[now].push_back(_adj[now][i]);
		_dfs(_adj[now][i], now);
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		_adj[a].push_back(b);
		_adj[b].push_back(a);
	}

	_dfs(1, -1);

	for(int i = 0; i < 100005; i++) {
		for(int j = 0; j < 15; j++) {
			dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -1;
			tmpdp[i][j][0] = tmpdp[i][j][1] = tmpdp[i][j][2] = -1;
		}
	}
	scanf("%d %d", &k, &x);

	int ans = 0;
	for(int i = 0; i <= x; i++) {
		ans = (ans + (DFS(1, i, 0))) % MOD;
	}
	printf("%d", ans);

	return 0;
}

int noRoot(int par, int from, int left, int state) {
	//printf("%d %d %d %d\n", par, from, left, state);
	if(dp[adj[par][from]][left][state] != -1) return dp[adj[par][from]][left][state];
	int ret = 0;

	if(from >= (int)adj[par].size() - 1) {
		return dp[adj[par][from]][left][state] = DFS(adj[par][from], left, state);
	}

	for(int i = 0; i <= left; i++) {
		ret = (ret + ((long long)DFS(adj[par][from], i, state) * noRoot(par, from + 1, left - i, state))) % MOD;
	}
	return dp[adj[par][from]][left][state] = ret;
}

int DFS(int now, int left, int state) { // 0 : less k, 1 : k, 2 : over k
	//printf("%d %d %d\n", now, left, state);
	if(tmpdp[now][left][state] != -1) return tmpdp[now][left][state];
	int ret = 0;
	if(adj[now].size() == 0) {
		if(left >= 2) return 0;
		if(left == 1) {
			if(state != 0) return 0;
			return 1;
		}
		if(state == 1) return k - 1;
		return M - 1;
	}

	if(state == 0 && left > 0) {
		ret = (ret + noRoot(now, 0, left - 1, 1)) % MOD;
	}
	ret = (ret + (long long)(k - 1) * noRoot(now, 0, left, 0)) % MOD;
	if(state != 1) {
		ret = (ret + (long long)(M - k) * noRoot(now, 0, left, 2)) % MOD;
	}

	return tmpdp[now][left][state] = ret;
}