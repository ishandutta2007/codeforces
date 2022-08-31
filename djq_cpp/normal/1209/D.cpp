#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

vector<int> G[100005];

bool vis[100005];
void dfs(int v)
{
	vis[v] = true;
	rep(i, G[v].size()) {
		int u = G[v][i];
		if(!vis[u]) dfs(u);
	}
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	rep(i, k) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int tot = n;
	rep1(i, n) if(!vis[i]) {
		dfs(i);
		tot --;
	}
	printf("%d\n", k - tot);
	return 0;
}