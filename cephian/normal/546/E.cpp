#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

struct Edge {
  int u, v;
  ll cap, flow;
  Edge() {}
  Edge(int u, int v, ll cap): u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic {
  int N;
  vector<Edge> E;
  vector<vector<int>> g;
  vector<int> d, pt;

  Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}

  void AddEdge(int u, int v, ll cap) {
    if (u != v) {
      E.emplace_back(Edge(u, v, cap));
      g[u].emplace_back(E.size() - 1);
      E.emplace_back(Edge(v, u, 0));
      g[v].emplace_back(E.size() - 1);
    }
  }

  bool BFS(int S, int T) {
    queue<int> q({S});
    fill(d.begin(), d.end(), N + 1);
    d[S] = 0;
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if (u == T) break;
      for (int k: g[u]) {
        Edge &e = E[k];
        if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
          d[e.v] = d[e.u] + 1;
          q.emplace(e.v);
        }
      }
    }
    return d[T] != N + 1;
  }

  ll DFS(int u, int T, ll flow = -1) {
    if (u == T || flow == 0) return flow;
    for (int &i = pt[u]; i < g[u].size(); ++i) {
      Edge &e = E[g[u][i]];
      Edge &oe = E[g[u][i]^1];
      if (d[e.v] == d[e.u] + 1) {
        ll amt = e.cap - e.flow;
        if (flow != -1 && amt > flow) amt = flow;
        if (ll pushed = DFS(e.v, T, amt)) {
          e.flow += pushed;
          oe.flow -= pushed;
          return pushed;
        }
      }
    }
    return 0;
  }

  ll MaxFlow(int S, int T) {
    ll total = 0;
    while (BFS(S, T)) {
      fill(pt.begin(), pt.end(), 0);
      while (ll flow = DFS(S, T))
        total += flow;
    }
    return total;
  }
};

int bs=0,as=0,a,b;

int g[105][105]={};

int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	Dinic D(2*n+2);
	for(int i = 1; i <= n; ++i) {
		scanf("%d",&a);
		D.AddEdge(0,i,a);
		D.AddEdge(i,i+n,1e6);
		as+=a;
	}
	for(int i = n+1; i <= 2*n; ++i) {
		scanf("%d",&b);
		D.AddEdge(i,2*n+1,b);
		bs += b;
	}
	for(int i = 0; i < m; ++i) {
		int u,v;
		scanf("%d%d",&u,&v);
		D.AddEdge(u,v+n,1e6);
		D.AddEdge(v,u+n,1e6);
	}
	if (D.MaxFlow(0,2*n+1) != bs || bs != as) {
		printf("NO\n");
	} else {
		printf("YES\n");
		for(int i = 0; i < D.E.size(); i+=2) {
			if(1 <= D.E[i].u && D.E[i].u <= n) {
				g[D.E[i].u][D.E[i].v-n] = D.E[i].flow;
			}
		}
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				printf("%d ",g[i][j]);
			}
			printf("\n");
		}

	}


	return 0;
}