#include <bits/stdc++.h>
 
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define cin_desync()                      \
	do {                                  \
		ios_base::sync_with_stdio(false); \
		cin.tie(0);                       \
	} while (0)                           \

#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1 << " | ";
	__f(comma + 1, args...);
}

#else
#define trace(...)
#endif // ifndef ONLINE_JUDGE

// Adjacency list implementation of Dinic's blocking flow algorithm.
// This is very fast in practice, and only loses to push-relabel flow.
//
// Running time:
//     O(|V|^2 |E|)
//
// INPUT:
//     - graph, constructed using AddEdge()
//     - source and sink
//
// OUTPUT:
//     - maximum flow value
//     - To obtain actual flow values, look at edges with capacity > 0
//       (zero capacity edges are residual edges).

typedef long long LL;

struct Edge {
  int u, v;
  LL cap, flow;
  int id;
  Edge() {}
  Edge(int u, int v, LL cap, int id): u(u), v(v), cap(cap), id(id), flow(0) {}
};

struct Dinic {
  int N;
  vector<Edge> E;
  vector<vector<int>> g;
  vector<int> d, pt;
  
  Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}

  void AddEdge(int u, int v, LL cap, int id = -1) {
    if (u != v) {
	  trace(u, v, cap);
      E.emplace_back(Edge(u, v, cap, id));
      g[u].emplace_back(E.size() - 1);
      E.emplace_back(Edge(v, u, 0, -1));
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

  LL DFS(int u, int T, LL flow = -1) {
    if (u == T || flow == 0) return flow;
    for (int &i = pt[u]; i < g[u].size(); ++i) {
      Edge &e = E[g[u][i]];
      Edge &oe = E[g[u][i]^1];
      if (d[e.v] == d[e.u] + 1) {
        LL amt = e.cap - e.flow;
        if (flow != -1 && amt > flow) amt = flow;
        if (LL pushed = DFS(e.v, T, amt)) {
          e.flow += pushed;
          oe.flow -= pushed;
          return pushed;
        }
      }
    }
    return 0;
  }

  LL MaxFlow(int S, int T) {
    LL total = 0;
    while (BFS(S, T)) {
      fill(pt.begin(), pt.end(), 0);
      while (LL flow = DFS(S, T))
        total += flow;
    }
    return total;
  }
};

const int max_N = 610;

int main() {
	int T;
	cin >> T;

	while(T--) {
		cerr << "==================================================" << endl;
		int N, M, K;
		cin >> N >> M >> K;

		vector<int> E[max_N];
		vector<pii> all;

		Dinic dinic(1 + M + N + 1);

		for (int i = 1; i <= M; ++i) {
			int a, b;
			cin >> a >> b;
			E[a].push_back(b);
			E[b].push_back(a);

			dinic.AddEdge(0, i, 1, i);
			dinic.AddEdge(i, M + a, 1);
			dinic.AddEdge(i, M + b, 1);
		}

		bool fail = false;

		for (int i = 1; i <= N; ++i) {
			if (E[i].size() > 2 * K) {
				for (int i = 1; i <= M; ++i) {
					cout << 0 << ' ';
				}
				cout << endl;
				fail = true;
				break;
			} else {
				int d = E[i].size();
				int c;
				for (c = 0; c <= d; ++c) {
					if ((d - c) / 2 + (d - c) % 2 + c > K) {
						break;
					}
				}
				--c;

				dinic.AddEdge(M + i, M + N + 1, c);
				trace(i, c);
			}
		}


		if (fail) {
			continue;
		}

		int mf = dinic.MaxFlow(0, M + N + 1);

		int sat = 0;
		for (auto &e : dinic.E) {
			if (e.id > 0 && e.flow == 1) {
				++sat;
			}
		}

		trace(sat, M);

		if (sat < M) {
			for (int i = 1; i <= M; ++i) {
				cout << 0 << ' ';
			}
			cout << endl;
			continue;
		}

		vector<int> my2[max_N];
		for (int i = 1; i <= M; ++i) {
			for (int eidx : dinic.g[i]) {
				auto &e = dinic.E[eidx];
				if (e.v == 0 || e.flow == 1) {
					continue;
				}
				my2[e.v - M].push_back(i);
			}
		}

		int col = 1;
		int ans[max_N] = {0};

		for (int i = 1; i <= N; ++i) {
			const auto &v = my2[i];
			int d = v.size();
			for (int j = 0; j < d; j += 2) {
				ans[v[j]] = col;
				if (j + 1 < d) {
					ans[v[j + 1]] = col;
				}
				++col;
			}
		}

		for (int i = 1; i <= M; ++i) {
			cout << ans[i] << ' ';
		}
		cout << endl;

	}
}