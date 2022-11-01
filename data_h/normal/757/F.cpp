#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

const int N = 2e5 + 7;
const long long INF = 1LL << 60;

int n, m, s;
vector<pair<int, int> > adj[N];
long long dist[N];

/*  edge  , n  ,r  ,  1-based
 realdom[u]  dominator tree  u  father ,  realdom  -1
*/
int r;
int parent[N],label[N],cnt,real[N];
vector<int> edge[N],succ[N],pred[N];
int semi[N],idom[N],ancestor[N],best[N];
vector<int> bucket[N];
int realdom[N];
void dfs(int u) {
	label[u]=++cnt; real[cnt]=u;
	for(vector<int>::iterator it=edge[u].begin();it!=edge[u].end();++it) {
		int v=*it;if(v==parent[u] || label[v]!=-1) continue;
		parent[v]=u; dfs(v);
	}
}
void link(int v,int w) { ancestor[w]=v; }
void compress(int v) {
	int a=ancestor[v];
	if(ancestor[a]==0) return;
	compress(a);
	if(semi[best[v]]>semi[best[a]]) best[v]=best[a];
	ancestor[v]=ancestor[a];
}

int eval(int v) {
	if(ancestor[v]==0) return v;
	compress(v); return best[v];
}

void dominator() { // clear succ & pred & parent[r],let cnt=0 first
	cnt=0;
	for(int i=1;i<=n;++i){ succ[i].clear(), pred[i].clear(); }
	for(int i=1;i<=n;++i) label[i]=-1;
	parent[r]=-1; dfs(r);// r is root
	for(int u=1;u<=n;++u) {
		for(vector<int>::iterator it=edge[u].begin();it!=edge[u].end();++it) {
			int v=*it;
			if(label[u]!=-1&&label[v]!=-1) {
				succ[label[u]].push_back(label[v]);
				pred[label[v]].push_back(label[u]);
			}
		}
	}
	for(int i=1;i<=n;++i)
		semi[i]=best[i]=i, idom[i]=ancestor[i]=0, bucket[i].clear();
	for(int w=cnt;w >= 2;--w) {
		int p=label[parent[real[w]]];
		for(vector<int>::iterator it=pred[w].begin();it!=pred[w].end();++it) {
			int v=*it, u=eval(v);
			if(semi[w]>semi[u]) semi[w]=semi[u];
		}
		bucket[semi[w]].push_back(w); link(p,w);
		for(int i=0;i<bucket[p].size();++i) {
			int v=bucket[p][i], u=eval(v);
			idom[v]=(semi[u]<p?u:p);
		}
		bucket[p].clear();
	}
	for(int w=2;w<=cnt;++w) {
		if(idom[w]!=semi[w]) idom[w]=idom[idom[w]];
	}
	idom[1]=0;
	for(int i=1;i<=n;++i) realdom[i]=-1;
	for(int i=2;i<=cnt;++i) {
		int u=real[idom[i]],v=real[i];
		// u is immediate dominator of v(i==1?)
		realdom[v]=u;
	}
}

void spfa() {
	priority_queue<pair<long long, int> > q;
	static int visit[N];
	for (int i = 0; i < n; i++) {
		visit[i] = false;
		dist[i] = INF;
	}
	q.push({dist[s] = 0, s});
	while (!q.empty()) {
		auto w = q.top();
		q.pop();
		int u = w.second;
		if (visit[u]) continue;
		visit[u] = true;
		for (auto e : adj[u]) {
			int v = e.first, cost = e.second;
			if (dist[u] + cost < dist[v]) {
				dist[v] = dist[u] + cost;
				q.push({-dist[v], v});
			}
		}
	}
}

vector<int> sons[N];
int size[N];

void go(int u) {
	size[u] = 1;
	for (auto v : sons[u]) {
		go(v);
		size[u] += size[v];
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &s);
	--s;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		--u, --v;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	spfa();
	r = s + 1;
	for (int u = 0; u < n; u++) {
		for (auto e : adj[u]) {
			int v = e.first, cost = e.second;
			if (dist[u] + cost == dist[v]) {
				edge[u + 1].push_back(v + 1);
				//printf("%d %d\n", u + 1, v + 1);
			}
		}
	}
	dominator();
	for (int i = 1; i <= n; i++) {
		if (realdom[i] != -1) {
			sons[realdom[i]].push_back(i);
		}
	}
	go(r);
	int ans = 0;
	for (auto v : sons[r]) {
		ans = max(ans, size[v]);
	}
	printf("%d\n", ans);
}