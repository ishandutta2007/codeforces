#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 10;

int n, k, sz[MAXN];
bool mark[MAXN];
vector<int>	adj[MAXN];

void dfs(int v, int p = -1){
	sz[v] = mark[v];
	for (int u:adj[v])
		if (u^p)	dfs(u, v), sz[v] += sz[u];
}

ll ans = 0;
void go(int v, int p = -1, int de = 0){
	if (mark[v])	ans += de;
	for (int u:adj[v])
		if (u^p)
			go(u, v, de + 1);
}

int main(){
	scanf("%d %d", &n, &k);
	for (int i = 0; i < 2 * k; i++){
		int a;	scanf("%d", &a);	a--;
		mark[a] = 1;
	}
	k *= 2;

	for (int i = 0; i < n - 1; i++){
		int a, b;	scanf("%d %d", &a, &b), a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0);
	int v = 0, p = -1;
	bool fl = 1;
	while (fl){
		fl = 0;
		for (int u:adj[v])
			if (u^p && sz[u] * 2 >= k){
				p = v;
				v = u;
				fl = 1;
				break;
			}
	}
	go(v);
	printf("%lld\n", ans);
	return 0;
}