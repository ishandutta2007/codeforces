#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct MinCostMaxFlow {
    struct Edge{
        int to, cap;
        int flow;
        int cost;
    };

    static const int MAX_V = 2060;
    static const int MAX_E = 100000;
    static const int INF = 1e9 + 7;

    int sz = 0;
    Edge e[MAX_E];
    vector<int> g[MAX_V];
    int fb[MAX_V];
    int was[MAX_V];
    pair<int, int> prev[MAX_V];

    void addEdge(int v, int to, int cap, int cost){
        g[v].push_back(sz);
        e[sz++] = { to, cap, 0, cost };
        g[to].push_back(sz);
        e[sz++] = { v, 0, 0, -cost };
    }

    vector<vector<int> > restore() {

      vector<vector<int> > ans;
      vector<int> path;
      int start = 0;

      while (true) {
        
        int ed = -1;
        for (auto p : g[start]) {
          if (e[p].flow > 0) {
            ed = p;
          }
        }

        if (ed == -1) {
          if (start == 0) break;
          path.pop_back();
          ans.pb(path);

          path.clear();
          start = 0;
          continue;
        }

        e[ed].flow--;
        start = e[ed].to;
        path.pb(start);
      }

      return ans;

    }

    ll find(int start, int finish) {
        ll ans = 0;

        while (true) {
            for (int i = 0; i < MAX_V; i++) fb[i] = INF, prev[i] = { -1, -1 }, was[i] = 0;
            fb[start] = 0;
            vector<int> st;
            int uk = 0;
            st.push_back(start);
            while (uk < st.size()) {
                int v = st[uk++];
    was[v] = 0;
                for (int to : g[v]) {
                    auto ed = e[to];
                    if (ed.flow < ed.cap && fb[ed.to] > fb[v] + ed.cost) {
                        prev[ed.to] = { v, to };
                        fb[ed.to] = fb[v] + ed.cost;
                        if (!was[ed.to]) {
              st.push_back(ed.to);
          was[ed.to] = 1;
      }
                    }
                }
            }

            if (fb[finish] == INF) {
                return ans;
            }

            int max_flow = INF;
            int v = finish;
            while (1) {
                auto now = prev[v];
                if (now.x == -1) break;
                max_flow = min(max_flow, e[now.y].cap - e[now.y].flow);
                v = now.x;
            }

            if (fb[finish] * (ll)max_flow > 0) {
              return ans;
            }

            ans += fb[finish] * (ll)max_flow;

            v = finish;
            while (1) {
                auto now = prev[v];
                if (now.x == -1) break;
                e[now.y].flow     += max_flow;
                e[now.y ^ 1].flow -= max_flow;
                v = now.x;
            }
            //required_flow -= max_flow;
        }

        return ans;
    }
};

MinCostMaxFlow t;


int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  int d, n;
  cin >> d >> n;

  vector<int> mask;
  for (int i = 0; i < n; ++i) {
    int t = 0;

    string X;
    cin >> X;
    reverse(all(X));

    for (int j = 0; j < d; ++j) {
      char ch = X[j];
      t *= 2;
      t += (ch - '0');
    }
    //t = (1<<d) - 1 - t;
    mask.pb(t);
  }

  int source = 0;
  int sink = source + 2*(1<<d) + 1;

  for (int i = 0; i < (1<<d); ++i) {
    t.addEdge(2*i + 1, 2 * i + 2, 1e9, 0);

    for (int j = 0; j < d; ++j) {
      if ((1<<j)&i) continue;
      int to = i ^ (1<<j);
      t.addEdge(2 * i + 2, 2 * to + 1, 1e9, 0);
    }
  }

  for (auto x : mask) {
    t.addEdge(source, 2*x+2, 1, -__builtin_popcount(x) - 1);
    t.addEdge(2*x+1, sink, 1, 0);
  }

  int Z = t.find(0, sink);

  vector<vector<int> > ans = t.restore();

  for (auto &x : ans) {
    for (auto &y : x) {
      y = (y - 1) / 2;
    }
  }

  vector<int> res;
  set<int> used;

  map<int, int> nxt;

  for (auto x : ans) {
    nxt[x[0]] = x.back();
  }

  sort(all(mask));  

  for (auto M : mask) {
    if (!used.count(M)) {
      vector<int> p;
      p.pb(0);

      int T = M;
      while (true) {
        p.pb(T);
        used.insert(T);
        if (!nxt.count(T)) break;
        T = nxt[T];
      }

      for (int i = 1; i < p.size(); ++i) {
        int W = p[i]^p[i-1];
        for (int j = 0; j < d; ++j) {
          if ((1<<j)&W) {
            res.pb(j);
          }
        }
      }
      res.pb(-1);
    }
  }

  res.pop_back();
  cout << res.size() << '\n';
  for (auto x : res) {
    if (x==-1) cout << "R ";
    else cout << x << " ";
  }


}