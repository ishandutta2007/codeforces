#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const int max_n = 1e5 + 20;

int n;
int col[max_n], sz[max_n];
vector<int>	adj[max_n];
ll ans[max_n], sum[max_n];
int cnt[max_n];
int mx;

int init(int v, int p = -1){
	sz[v] = 1;
	if (~p)
		adj[v].erase(find(adj[v].begin(), adj[v].end(), p));
	for (int u:adj[v])
		sz[v] += init(u, v);
	return	sz[v];
}

void add(int v) {
	sum[cnt[col[v]]] -= col[v];
	cnt[col[v]]++;
	sum[cnt[col[v]]] += col[v];
	mx = max(mx, cnt[col[v]]);
	for (int u:adj[v])
		add(u);
}

void remove(int v) {
	cnt[col[v]]--;
	for (int u:adj[v])
		remove(u);
}

void dfs(int v, bool type){
	if (sz[v] == 1){
		ans[v] = col[v];
		if (type){
			cnt[col[v]]++;
			sum[1] += col[v];
			mx = max(mx, 1);
		}
		return;
	}

	int maxi = -1, ind = -1;
	for (int u:adj[v])
		if (sz[u] > maxi){
			maxi = sz[u];
			ind = u;
		}

	for (int u:adj[v])
		if (u != ind)	dfs(u, 0);
	
	dfs(ind, 1);
	for (int u:adj[v])
		if (u != ind)	add(u);
	sum[cnt[col[v]]] -= col[v];
	cnt[col[v]]++;
	sum[cnt[col[v]]] += col[v];
	mx = max(mx, cnt[col[v]]);

	ans[v] = sum[mx];
	if (!type){
		for (int i = 0; i <= mx; i++)	sum[i] = 0;
		for (int u:adj[v])
			remove(u);
		mx = 0;
		cnt[col[v]]--;
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &col[i]);
	for (int i = 0; i < n - 1; i++){
		int a, b;	scanf("%d%d", &a, &b);	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	sz[0] = init(0);
	dfs(0, 0);
	for (int i = 0; i < n; i++)
		printf("%lld ", ans[i]);
	printf("\n");
	return 0;
}