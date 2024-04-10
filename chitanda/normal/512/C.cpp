#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()

bool isp[20010];
void init(){
	for(int i = 2; i <= 20000; ++i){
		int li = sqrt(i) + 0.1;
		isp[i] = 1;
		for(int j = 2; j <= li && isp[i]; ++j)
			if(i % j == 0) isp[i] = 0;
	}
}

const int maxn = 210, maxe = maxn * maxn * 3, oo = 1e9;
int e = 1, inx, vis[maxn], ln[maxn], ht[maxn], l, r, S, T;
int to[maxe], ne[maxe], he[maxn], cap[maxe];

int n, m;
int a[210];
int edge[210][210];
vector<int> ans[210];
vector<int> g[210];

void link(int x, int y, int v){
	to[++e] = y, ne[e] = he[x], he[x] = e, cap[e] = 0;
	to[++e] = x, ne[e] = he[y], he[y] = e, cap[e] = v;
}

bool bfs(){
	for(ln[l = r = 1] = S, vis[S] = ++inx, ht[S] = 1; l <= r; l++)
		for(int j = he[ln[l]]; j; j = ne[j])
			if(vis[to[j]] < inx && cap[j ^ 1]){
				vis[to[j]] = inx, ht[to[j]] = ht[ln[l]] + 1, ln[++r] = to[j];
				if(to[j] == T) return 1;
			}
	return 0;
}

int dfs(int f, int d){
	if(!f || d == S) return f;
	int flow = 0, k;
	for(int j = he[d]; j; j = ne[j])
		if(vis[to[j]] == inx && ht[to[j]] == ht[d] - 1 && (k = dfs(min(f, cap[j]), to[j]))){
			f -= k, flow += k;
			cap[j] -= k, cap[j ^ 1] += k;
			if(!f) return flow;
		}
	ht[d] = maxn + 1;
	return flow;
}

int dinic(){
	int maxflow = 0;
	while(bfs()) maxflow += dfs(oo, T);
	return maxflow;
}

void dfs(int t){
	//printf(":%d", t);
	vis[t] = 1;
	ans[m].pb(t);
	for(int v : g[t])
		if(!vis[v])
			dfs(v);
}

int main(){
	init();
	scanf("%d", &n);
	S = n + 1, T = S + 1;
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		if(a[i] & 1) link(S, i, 2);
		else link(i, T, 2);
	}
	
	for(int i = 1; i <= n; ++i)
		if(a[i] & 1)
			for(int j = 1; j <= n; ++j)
				if(~a[j] & 1)
					if(isp[a[i] + a[j]]){
						link(i, j, 1);
						edge[i][j] = e - 1;
					}
	
	int flow = dinic();
	if(flow == n){
			for(int i = 1; i <= n; ++i)
				if(a[i] & 1)
					for(int j = 1; j <= n; ++j)
						if(~a[j] & 1)
							if(isp[a[i] + a[j]]){				 
								if(cap[edge[i][j]])
									g[i].pb(j), g[j].pb(i);
							}
			m = 0;
			memset(vis, 0, sizeof(vis));
			for(int i = 1; i <= n; ++i)
				if(!vis[i]){
					ans[m].clear();
					dfs(i);
					++m;	
				}
			printf("%d\n", m);
			for(int i = 0; i < m; ++i){
				printf("%d", (int)ans[i].size());
				for(int v : ans[i]) printf(" %d", v);
				printf("\n");
			}
	}else printf("Impossible\n");
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}