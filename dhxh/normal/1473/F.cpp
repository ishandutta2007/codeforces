#include <bits/stdc++.h>

using namespace std;

const int maxn = 3000 + 5;
const int INF = 0x3f3f3f3f;
const int N = 100;

int n, m, t;

int a[maxn];
int b[maxn];
bool vis[maxn];

struct edge
{
	int from, to, cap, flow;
	edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};
struct Dinic {
	int n, m, s, t;
	vector<edge> edges;
	vector<int> G[maxn];
	bool vis[maxn];
	int d[maxn];
	int cur[maxn];
	void init(int n)
	{
		this->n = n;
		for (int i = 0; i < n; i++)
			G[i].clear();
		edges.clear();
	}
	void clear()
	{
		for (int i = 0; i < edges.size(); i++)
			edges[i].flow = 0;
	}
	void reduce() 
	{
		for (int i = 0; i < edges.size(); i++)
			edges[i].cap -= edges[i].flow;
	}
	void addedge(int from, int to, int cap)
	{
		edges.push_back(edge(from, to, cap, 0));
		edges.push_back(edge(to, from, 0, 0));
		m = edges.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}
	bool BFS()
	{
		memset(vis, 0, sizeof(vis));
		queue<int> Q;
		Q.push(s);
		vis[s] = 1;
		d[s] = 0;
		while (!Q.empty())
		{
			int x = Q.front(); Q.pop();
			for (int i = 0; i < G[x].size(); i++)
			{
				edge& e = edges[G[x][i]];
				if (!vis[e.to] && e.cap > e.flow)
				{
					vis[e.to] = 1;
					d[e.to] = d[x] + 1;
					Q.push(e.to);
				}
			}
		}
		return vis[t];
	}
	int DFS(int x, int a)
	{
		if (x == t || a == 0) return a;
		int flow = 0, f;
		for (int& i = cur[x]; i < G[x].size(); i++)
		{
			edge& e = edges[G[x][i]];
			if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0)
			{
				e.flow += f;
				edges[G[x][i] ^ 1].flow -= f;
				flow += f;
				a -= f;
				if (a == 0) break;
			}
		}
		return flow;
	}
	int Maxflow(int s, int t)
	{
		this->s = s; this->t = t;
		int flow = 0;
		while (BFS())
		{
			memset(cur, 0, sizeof(cur));
			flow += DFS(s, INF);
		}
		return flow;
	}
	vector<int> Mincut()
	{
		vector<int> ans;
		for (int i = 0; i < edges.size(); i++)
		{
			edge& e = edges[i];
			if (vis[e.from] && !vis[e.to] && e.cap > 0)
				ans.push_back(i);
		}
		return ans;
	}
} dinic;

int main(){
	int i, j;
	int ans = 0;
	
	scanf("%d", &n);
	
	for(i=1;i<=n;i++) scanf("%d", &a[i]);
	for(i=1;i<=n;i++) scanf("%d", &b[i]);
	
	dinic.init(n + 2);
	
	for(i=1;i<=n;i++){
		if(b[i] > 0){
			dinic.addedge(0, i, b[i]);
			ans += b[i];
		}else{
			dinic.addedge(i, n + 1, -b[i]);
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=N;j++) vis[j] = 0;
		for(j=i-1;j>0;j--){
			if(a[i] % a[j] == 0 and !vis[a[j]]){
				dinic.addedge(i, j, INF);
				vis[a[j]] = true;
			}
		}
	}
	
	ans -= dinic.Maxflow(0, n + 1);
	
	printf("%d\n", ans);
	
	return 0;
}