#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, a[200005], b[200005];
vector<int> G[200005];
int vis[200005];
bool dfs(int v)
{
	vis[v] = 1;
	rep(i, G[v].size()) {
		int u = G[v][i];
		if(!vis[u] && !dfs(u)) return false;
		else if(vis[u] == 1) return false;
	}
	vis[v] = -1;
	return true;
}
void solve()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n) scanf("%d", &b[i]);
	
	rep1(i, n) G[i].clear();
	rep(i, n) G[a[i]].push_back(b[i]);
	
	PII mx = MP(0, 0);
	rep1(i, n) mx = max(mx, MP((int)G[i].size(), i));
	rep1(i, n) vis[i] = 0;
	vis[mx.second] = -1;
	rep1(i, n) if(!vis[i] && !dfs(i)) {
		printf("WA\n"); return;
	}
	printf("AC\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}