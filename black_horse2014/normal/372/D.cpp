#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>

#define MX 100005
#define rep(i, n) for (int i = 0; i < n; i ++)

using namespace std;

typedef set<int> SI;
SI S;
SI :: iterator it;

int N, K, M, tot, n, rlt;
int dp[MX], par[MX][20], num[MX], pos[MX];
int next[MX*2], head[MX], E[MX*2];

int add_edge(int u, int v, int id) {
	next[id] = head[u]; head[u] = id; E[id] = v;	
}

int Dfs(int id, int d) {
	num[id] = tot; pos[tot ++] = id;
	dp[id] = d;
	int u;
	for (int i = head[id]; i; i = next[i]) {
		u = E[i];
		if (par[id][0] == u) continue;
		par[u][0] = id;
		Dfs(u, d + 1);
	}
}

int get_lca(int x, int y) {
	if (dp[x] < dp[y]) swap(x, y);
	int i;
	for (i = n; i >= 0; i --) if (dp[par[x][i]] >= dp[y]) x = par[x][i];
	if (x == y) return x;
	for (i = n; i >= 0; i --) if (par[x][i] != par[y][i]) x = par[x][i], y = par[y][i];
	return par[x][0];
}

int insert(int id) {
	if (S.empty()) return 1;
	it = S.lower_bound(id);
	int x, y;
	if (it == S.begin() || it == S.end()) x = *S.begin(), y = *--S.end();
	else {
		x = *it --;
		y = *it;
	}
	id = pos[id], x = pos[x], y = pos[y];
	return dp[id] + dp[get_lca(x, y)] - dp[get_lca(id, x)] - dp[get_lca(id, y)];
}

int main() {
	
	cin >> N >> K;
	n = log2(N) + 1;
	
	int x, y, k, cnt, cur;
	
	rep(i, N - 1) {
		cin >> x >> y;
		x --, y --;
		add_edge(x, y, ++ M);
		add_edge(y, x, ++ M);
	} 
		
	Dfs(0, 1);
	par[0][0] = N;
	
	for (k = 1; k <= n; k ++) 
		rep(i, N) par[i][k] = par[par[i][k - 1]][k - 1];
	
	k = cnt = 0;
	rep(i, N) {
		while (k < N) {
			cur = insert(num[k]);
				if (cnt + cur <= K) {
				S.insert(num[k]);
				cnt += cur;
				rlt = max(rlt, k - i + 1);
				k ++;
			}
			else break;
		} 	
		S.erase(num[i]);
		cur = insert(num[i]);
		cnt -= cur;
	}
	
	cout << rlt << endl;
	return 0;
}