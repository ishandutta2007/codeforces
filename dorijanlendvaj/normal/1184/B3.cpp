#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=100, mxA=1e5;

namespace maxflow {
	const int maxnodes=mxA+5;
	int nodes = maxnodes, src, dest;
	int dist[maxnodes], q[maxnodes], work[maxnodes];
	struct Edge {
		int to, rev;
		ll f, cap;
	};
	vector<Edge> g[maxnodes];
	void addEdge(int s, int t, ll cap){
		Edge a = {t, g[t].size(), 0, cap};
		Edge b = {s, g[s].size(), cap, cap};
		g[s].push_back(a);
		g[t].push_back(b);
	}
	bool dinic_bfs() {
		fill(dist, dist + nodes, -1);
		dist[src] = 0;
		int qt = 0;
		q[qt++] = src;
		for (int qh = 0; qh < qt; qh++) {
			int u = q[qh];
			for (int j = 0; j < (int) g[u].size(); j++) {
				Edge &e = g[u][j];
				int v = e.to;
				if (dist[v] < 0 && e.f < e.cap) {
					dist[v] = dist[u] + 1;
					q[qt++] = v;
				}
			}
		}
		return dist[dest] >= 0;
	}
	ll dinic_dfs(int u, ll f) {
		if (u == dest)
			return f;
		for (int &i = work[u]; i < (int) g[u].size(); i++) {
			Edge &e = g[u][i];
			if (e.cap <= e.f) continue;
			int v = e.to;
			if (dist[v] == dist[u] + 1) {
				ll df = dinic_dfs(v, min(f, e.cap - e.f));
				if (df > 0) {
					e.f += df;
					g[v][e.rev].f -= df;
					return df;
				}
			}
		}
		return 0;
	}
	ll maxFlow(int _src, int _dest) {
		src = _src;
		dest = _dest;
		ll result = 0;
		while (dinic_bfs()) {
			fill(work, work + nodes, 0);
			while (ll delta = dinic_dfs(src, 1e18))
				result += delta;
		}
		return result;
	}
}

namespace closure {
	int c[mxA];
	ll a[mxA];
	vector<int> adj[mxA], adj2[mxA], st;
	bool vis[mxA];
	void dfs1(int u) {
		vis[u]=1;
		for(int v : adj[u])
			if(!vis[v])
				dfs1(v);
		st.push_back(u);
	}
	void dfs2(int u, int cu) {
		vis[u]=0;
		c[u]=cu;
		for(int v : adj2[u])
			if(vis[v])
				dfs2(v, cu);
	}
	ll solve(int s) {
		for(int i=0; i<s; ++i)
			if(!vis[i])
				dfs1(i);
		for(int i=0; i<s; ++i)
			for(int j : adj[i])
				adj2[j].push_back(i);
		for(int i=s-1; ~i; --i)
			if(vis[st[i]])
				dfs2(st[i], st[i]);
		ll a1=0;
		for(int i=0; i<s; ++i) {
			if(i^c[i])
				a[c[i]]+=a[i];
		}
		for(int i=0; i<s; ++i)
			if(i==c[i])
				a1+=max(a[i], 0ll);
		int source=s, sink=s+1;
		maxflow::nodes=s+2;
		for(int i=0; i<s; ++i) {
			if(i==c[i]) {
				if(a[i]>0)
					maxflow::addEdge(source, i, a[i]);
				else
					maxflow::addEdge(i, sink, -a[i]);
			}
		}
		for(int i=0; i<s; ++i)
			for(int j : adj[i])
				if(c[i]^c[j])
					maxflow::addEdge(c[i], c[j], 1e18);
		return a1-maxflow::maxFlow(source, sink);
	}
}

int n, m, d[mxN], s, b, k, ax[mxA], aa[mxA], af[mxA], bx[mxA], bd[mxA], bg[mxA], mg[mxN], pb[mxA];
ll ap[mxA];
vector<int> adj[mxN], va[mxN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int u, v; m--; ) {
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cin >> s >> b >> k;
	for(int i=0; i<s; ++i) {
		cin >> ax[i] >> aa[i] >> af[i] >> ap[i], --ax[i];
		ap[i]=-ap[i];
		va[ax[i]].push_back(i);
	}
	for(int i=0; i<b; ++i) {
		cin >> bx[i] >> bd[i] >> bg[i], --bx[i];
	}
	iota(pb, pb+b, 0);
	sort(pb, pb+b, [](const int &i, const int &j) {
		return bd[i]<bd[j];
	});
	for(int s=0; s<n; ++s) {
		d[s]=0;
		queue<int> qu;
		qu.push(s);
		while(qu.size()) {
			int u=qu.front();
			qu.pop();
			for(int v : adj[u]) {
				if(d[v]>d[u]+1) {
					d[v]=d[u]+1;
					qu.push(v);
				}
			}
		}
		memset(mg, -1, sizeof(mg));
		sort(va[s].begin(), va[s].end(), [](const int &i, const int &j) {
			return aa[i]<aa[j];
		});
		for(int i1=0, i2=0; i1<va[s].size()||i2<b; ) {
			if(i1<va[s].size()&&(i2>=b||aa[va[s][i1]]<bd[pb[i2]])) {
				int ca=-1;
				for(int j=0; j<=min(n-1, af[va[s][i1]]); ++j)
					ca=max(ca, mg[j]);
				if(ca>=0)
					ap[va[s][i1]]+=ca;
				else
					ap[va[s][i1]]=-1e14;
				++i1;
			} else {
				if(d[pb[i2]]<n)
					mg[d[bx[pb[i2]]]]=max(mg[d[bx[pb[i2]]]], bg[pb[i2]]);
				++i2;
			}
		}
	}
	for(int i=0; i<k; ++i) {
		int s1, s2;
		cin >> s1 >> s2, --s1, --s2;
		closure::adj[s1].push_back(s2);
	}
	for(int i=0; i<s; ++i) {
		closure::a[i]=ap[i];
	}
	cout << closure::solve(s);
}