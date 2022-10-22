#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e3 + 10;
const int MAXE = MAXN * MAXN/2;

int n, m, from[MAXE], to[MAXE];
vector<int>	adj[MAXN];
bool vis[MAXN], del[MAXE];
int depth[MAXN], sz, comp[MAXN], cnt[MAXN], d[MAXN], sec[MAXN], sub[MAXN];

int dfs(int v, int p = -1, int de = 0){
	depth[v] = de;
	vis[v] = 1;
	int ret = de;
	for (int e:adj[v])
		if (e^p){
			int u = from[e]^to[e]^v;
			if (vis[u])
				ret = min(ret, depth[u]);
			else{
				int temp = dfs(u, e, de + 1);
				if (temp > de)
					del[e] = 1;
				ret = min(ret, temp);
			}
		}
	return ret;
}

void explore(int v){
	if (vis[v])	return;
	vis[v] = 1;
	cnt[sz]++;
	comp[v] = sz;
	for (int e:adj[v])
		if (!del[e])
			explore(from[e] ^ to[e] ^ v);
}

void plant(int v, int p = -1){
	sub[v] = cnt[v];
	for (int u:adj[v])
		if (u^p){
			plant(u, v), sub[v] += sub[u];
			d[v] += d[u] + sub[u] * cnt[v];
		}
}

int mx = 0;

void go(int v, int p = -1){
	memset(sec, 0, sizeof(sec));
	sec[0] = 1;
	for (int u:adj[v])
		for (int i = MAXN - 1; i >= sub[u]; i--)
			sec[i] |= sec[i - sub[u]];
		
	for (int i = 0; i < MAXN; i++)
		if (sec[i])
			mx = max(mx, d[v] + i * (n - cnt[v] - i));

	for (int u:adj[v])
		if (u^p){
			d[v] -= d[u] + sub[u] * cnt[v];
			sub[v] -= sub[u];
			sub[u] += sub[v];
			d[u] += d[v] + sub[v] * cnt[u];
			go(u, v);
			
			d[u] -= d[v] + sub[v] * cnt[u];
			sub[u] -= sub[v];
			sub[v] += sub[u];
			d[v] += d[u] + sub[u] * cnt[v];
		}
}

int main(){
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d %d", &from[i], &to[i]), from[i]--, to[i]--, adj[from[i]].push_back(i), adj[to[i]].push_back(i);
	dfs(0);
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++)
		if (!vis[i]){
			explore(i);
			sz++;
		}

	for (int i = 0; i < n; i++)	adj[i].clear();
	for (int e = 0; e < m; e++)	
		if (del[e]){
			adj[comp[from[e]]].push_back(comp[to[e]]);
			adj[comp[to[e]]].push_back(comp[from[e]]);
		}

	int sum = 0;
	for (int i = 0; i < sz; i++)	sum += cnt[i] * cnt[i];
	plant(0);
	go(0);
	printf("%d\n", mx + sum);
	return 0;
}