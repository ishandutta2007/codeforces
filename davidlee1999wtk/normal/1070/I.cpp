#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1255, MAXM = 2505, INF = 0x3f3f3f3f;

struct Dinic{
	struct edge{
		int n, p, r;
		void var(int n_, int p_, int r_){
			n = n_, p = p_, r = r_;
		}
	}edges[MAXM << 1];
	int g[MAXN], edgeSize, s, t, d[MAXN], cur[MAXN];
	queue <int> q;
	
	void init(int s_, int t_){
		memset(g, 0, sizeof(g));
		edgeSize = 1; s = s_, t = t_;
	}
	int addEdge(int u, int v, int r){
		edges[++ edgeSize].var(v, g[u], r);
		g[u] = edgeSize;
		edges[++ edgeSize].var(u, g[v], 0);
		g[v] = edgeSize;
		return edgeSize - 1;
	}
	bool bfs(){
		int now, p;
		memset(d, 0, sizeof(d));
		d[s] = 1; q.push(s);
		while(!q.empty()){
			now = q.front(); q.pop(); cur[now] = g[now];
			for(p = g[now]; p; p = edges[p].p)
				if(edges[p].r && !d[edges[p].n]){
					d[edges[p].n] = d[now] + 1;
					q.push(edges[p].n);
				}
		}
		return d[t];
	}
	int dfs(int x, int a){
		if(x == t || !a) return a;
		int f, flow = 0;
		for(int &p = cur[x]; p; p = edges[p].p)
			if(d[edges[p].n] == d[x] + 1 && (f = dfs(edges[p].n, min(a, edges[p].r)))){
				flow += f; edges[p ^ 1].r += f;
				edges[p].r -= f; if(!(a -= f)) break;
			}
		return flow;
	}
	int solve(){
		int ret = 0;
		while(bfs()) ret += dfs(s, INF);
		return ret;
	}
}maxFlow;
int n, m, k, deg[MAXN], a[MAXM], b[MAXM], col[MAXN], ccnt;
pair <int, int> eid[MAXM];

int getCol(int p){
	if(!col[p]) return col[p] = ++ ccnt;
	int ret = col[p]; col[p] = 0;
	return ret;
}
int main(){
	int i, testcase, sum;
	scanf("%d", &testcase);
	while(testcase --){
		scanf("%d%d%d", &n, &m, &k);
		memset(deg, 0, sizeof(deg));
		maxFlow.init(0, n + m + 1);
		for(i = 1; i <= m; ++ i){
			scanf("%d%d", &a[i], &b[i]);
			++ deg[a[i]], ++ deg[b[i]];
			eid[i] = make_pair(maxFlow.addEdge(a[i], n + i, 1), maxFlow.addEdge(b[i], n + i, 1));
			maxFlow.addEdge(n + i, n + m + 1, 1);
		}
		for(i = 1, sum = 0; i <= n; ++ i)
			if(deg[i] > k)
				maxFlow.addEdge(0, i, (deg[i] - k) * 2), sum += (deg[i] - k) * 2;
		memset(col, 0, sizeof(col));
		ccnt = 0;
		if(maxFlow.solve() == sum){
			for(i = 1; i <= m; ++ i)
				if(!maxFlow.edges[eid[i].first].r)
					printf("%d ", getCol(a[i]));
				else if(!maxFlow.edges[eid[i].second].r)
					printf("%d ", getCol(b[i]));
				else printf("%d ", ++ ccnt);
		}else for(i = 1; i <= m; ++ i) printf("0 ");
		printf("\n");
	}
	return 0;
}