#include <bits/stdc++.h>

using namespace std;

#define int long long

struct Flow {
  const int INF = (int)1e9 + 7;
  int n;

  struct Edge {
    int to, cap;
  };

  vector<Edge> edges;
  vector<vector<int>> g;
  vector<int> level, pt;

  Flow(int n) :
    n(n),
    g(n),
    level(n),
    pt(n) {
  }

  void addEdge(int a, int b, int c) {
  	a--, b--;
    assert(0 <= a && a < n);
    assert(0 <= b && b < n);
    g[a].push_back((int)edges.size());
    g[b].push_back((int)edges.size() + 1);
    edges.push_back({ b, c });
    edges.push_back({ a, 0 });
  }

  int dfs(int a, int cur) {
    if (a == n - 1 || cur == 0) return cur;

    while (pt[a] < (int)g[a].size()) {
      int i = g[a][pt[a]++];
      int b = edges[i].to, cap = edges[i].cap;
      if (level[b] == 1 + level[a] && cap) {
        int x = dfs(b, min(cur, cap));
        if (x) {
          pt[a]--;

          edges[i].cap -= x;
          edges[i ^ 1].cap += x;

          return x;
        }
      }
    }

    return 0;
  }

  int get() {
    int sol = 0;
    while (1) {
      for (int i = 0; i < n; i++) level[i] = -1, pt[i] = 0;
      level[0] = 0;
      queue<int> q;
      q.push(0);
      while (!q.empty()) {
        int a = q.front();
        q.pop();
        for (auto& i : g[a]) {
          if (edges[i].cap&&level[edges[i].to]==-1) {
            level[edges[i].to] = 1 + level[a];
            q.push(edges[i].to);
          }
        }
      }
      if (level[n - 1] == -1) break;
      while (1) {
        int x = dfs(0, INF);
        if (!x) break;
        sol += x;
      }
    }
    return sol;
  }

  vector<bool> get_min_cut_side() {
    vector<bool> marked(n, 0);
    queue<int> q;
    q.push(0);
    marked[0] = 1;
    while (!q.empty()) {
      int a = q.front();
      q.pop();
      for (auto &i : g[a]) {
        if (edges[i].cap && !marked[edges[i].to]) {
          marked[edges[i].to] = 1;
          q.push(edges[i].to);
        }
      }
    }
    return marked;
  }
};

signed main() {
#ifndef ONPC
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif
	vector<pair<int, int>> ce;

	int tests;
	cin >> tests;
	for (int tc = 1; tc <= tests; tc++) {
		int n;
		cin >> n;
		vector<vector<int>> d(2, vector<int> (n));
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> d[i][j];
			}	
		}
		set<int> difs;
		for (auto &sx : {-1, +1}) {
			for (auto &sy : {-1, +1}) {
				for (int id = 0; id < n; id++) {	
					int p0 = sx * d[0][0];
					int p1 = sy * d[1][id];
					difs.insert(p1 - p0);
				}
			}
		}
		map<int, int> want_id;
		for (int i = 0; i < n; i++) {
			want_id[d[1][i]] = 0;
		}
		int cntwant = 0;
		for (auto &it : want_id) {
			it.second = cntwant++;
		}
		assert(cntwant >= 1);
		vector<int> have(cntwant, 0);
		for (int i = 0; i < n; i++) {
			have[want_id[d[1][i]]]++;
		}
		bool Good = 0;

		for (auto &p1 : difs) {
			ce.clear();
			for (int i = 0; i < n; i++) {
				ce.push_back({abs(-d[0][i] - p1), abs(+d[0][i] - p1)});
			}
			bool good = 1;
			for (int i = 0; i < n; i++) {
				if (!want_id.count(ce[i].first) && !want_id.count(ce[i].second)) {
					good = 0;
				}
			}
			if (good == 0) {
				continue;
			}
			
			Flow flow(1 + n + cntwant + 1);
			
			for (int i = 1; i <= cntwant; i++) {
				flow.addEdge(1 + n + i, 1 + n + cntwant + 1, have[i - 1]);
			}
			for (int i = 1; i <= n; i++) {
				int a = ce[i - 1].first, b = ce[i - 1].second;
				flow.addEdge(1, 1 + i, 1);
				if (want_id.count(a)) assert(0 <= want_id[a] && want_id[a] < cntwant);
				if (want_id.count(b)) assert(0 <= want_id[b] && want_id[b] < cntwant);
				
				if (want_id.count(a)) flow.addEdge(1 + i, 1 + n + (1 + want_id[a]), 1);
				if (want_id.count(b)) flow.addEdge(1 + i, 1 + n + (1 + want_id[b]), 1);
				
			}
			if (flow.get() != n) {
				continue;
			}
			Good = 1;
			cout << "YES\n";
			vector<int> type(n, -1);
			for (int i = 1; i <= n; i++) {
				for (auto &id : flow.g[i]) {
					if (flow.edges[id].to == 0) {
						continue;
					}
					if (flow.edges[id].cap == 1) {
						continue;
					}
					///cout << " ==== " << flow.edges[id].to << "\n";
					int where = 1 + flow.edges[id].to - 1 - n;
					assert(1 <= where && where <= cntwant);
					
					int a = ce[i - 1].first, b = ce[i - 1].second;
					assert(type[i - 1] == -1);
					
					
					if (want_id.count(a) && want_id[a] + 1 == where) {
						type[i - 1] = 0;
					} else
					
					
					if (want_id.count(b) && want_id[b] + 1 == where) {
						assert(type[i - 1] == -1);
			
						type[i - 1] = 1;
					}
					assert(type[i - 1] != -1);
					
					//continue;
				}
			}
			for (int i = 0; i < n; i++) {
				assert(type[i] == 0 || type[i] == 1);
			}
			vector<int> sol(n);
			for (int i = 0; i < n; i++) {
				if (type[i] == 0) {
					sol[i] = -d[0][i];
				} else {
					assert(type[i] == 1);
					sol[i] = +d[0][i];
				}
			}
			int mn = min(0LL, p1);
			for (int i = 0; i < n; i++) {
				mn = min(mn, sol[i]);
			}
			for (int i = 0; i < n; i++) {
				cout << sol[i] - mn << " ";
			}
			cout << "\n";
			cout << 0 - mn << " " << p1 - mn << "\n";
			break;
			if (p1 == 36) {
				cout << "d1 = ";
				for (int i = 0; i < n; i++) {
					cout << d[1][i] << " ";
				}
				cout << "\n";
				for (auto &it : ce) {
					cout << it.first << " sau " << it.second << "\n";
				}
				cout << "aici\n";
			}
		}
		if (!Good) {
			cout << "NO\n";
			continue;
		}
		continue;
		cout << " ###################### \n";
		for (auto &dif : difs) {
			cout << "dif = " << dif << "\n";
		}
		cout << " ###################### \n";
	}
	return 0;
}