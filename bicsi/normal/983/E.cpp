
#include <bits/stdc++.h>

using namespace std;

template <class T>
struct RMQ {
  vector<vector<T>> rmq;
  T kInf = numeric_limits<T>::max();

  void Build(const vector<T>& V) {
    int n = V.size(), on = 1, depth = 1;
    while (on < n) on *= 2, ++depth;
    rmq.assign(depth, V);

    for (int i = 0; i < depth - 1; ++i)
      for (int j = 0; j < n; ++j) {
        rmq[i + 1][j] = min(rmq[i][j],
            rmq[i][min(n - 1, j + (1 << i))]);
      }
  }

  T Query(int a, int b) {
    if (b <= a) return kInf;
    int dep = 31 - __builtin_clz(b - a); // log(b - a)
    return min(rmq[dep][a], rmq[dep][b - (1 << dep)]);
  }
};

struct LCA {
  vector<int> enter, depth, exxit;
  vector<vector<int>> G;
  vector<pair<int, int>> linear;
  RMQ<pair<int, int>> rmq;
  int timer = 0;
    
  LCA() {} 
  LCA(int n) : enter(n, -1), exxit(n, -1), depth(n), G(n), linear(2 * n) {}
  
  void dfs(int node, int dep) {
    linear[timer] = {dep, node};
    enter[node] = timer++;
    depth[node] = dep;
    
    for (auto vec : G[node])
    if (enter[vec] == -1) {
      dfs(vec, dep + 1);
      linear[timer++] = {dep, node};
    }
    exxit[node] = timer;
  }
  
  void AddEdge(int a, int b) {
    G[a].push_back(b);
    G[b].push_back(a);
  }
  
  void Build(int root) {
    dfs(root, 0);
    rmq.Build(linear);
  }
  
  int Query(int a, int b) {
    a = enter[a], b = enter[b];
    return rmq.Query(min(a, b), max(a, b) + 1).second;
  }
  
  int Distance(int a, int b) {
    return depth[a] + depth[b] - 2 * depth[Query(a, b)];
  }
};

LCA lca;

struct Fenwick2D {
  vector<vector<int>> ys;
  vector<vector<int>> T;
  Fenwick2D(int n) : ys(n) {}
  
  void Mark(int x, int y) {
    for (; x < (int)ys.size(); x |= (x + 1))
      ys[x].push_back(y);
  }
  void Init() {
    for (auto& v : ys) {
      sort(v.begin(), v.end());
      v.erase(unique(v.begin(), v.end()), v.end());
      T.emplace_back(v.size() + 1);
    }
  }
  int ind(int x, int y) {
    auto it = lower_bound(ys[x].begin(), ys[x].end(), y);
    return distance(ys[x].begin(), it);
  }
  void Update(int x, int y, int val) {
    for (; x < (int)ys.size(); x |= (x + 1))
      for (int i = ind(x,y)+1; i < T[x].size(); i += (i & -i))
        T[x][i] = T[x][i] + val;
  }
  int Query(int x, int y) {
    int sum = 0;
    for (; x > 0; x &= (x - 1))
      for (int i = ind(x-1,y); i > 0; i -= (i & -i))
        sum = sum + T[x-1][i];
    return sum;
  }
  int QueryRect(int x1, int x2, int y1, int y2) {
    return Query(x2 + 1, y2 + 1) - Query(x1, y2 + 1)
        - Query(x2 + 1, y1) + Query(x1, y1);
  }
};

vector<int> dp;
vector<vector<int>> link;
vector<vector<int>> G;

void Propagate(int node, int par) {
    for (auto vec : G[node]) {
        if (vec == par) continue;
        
        Propagate(vec, node);
        if (lca.depth[dp[node]] > lca.depth[dp[vec]]) {
            dp[node] = dp[vec];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    lca = LCA(n);
    G.assign(n, vector<int>());
    Fenwick2D fw(2 * n + 5);

    for (int i = 1; i < n; ++i) {
        int p; cin >> p; --p;
        lca.AddEdge(p, i);
        G[p].push_back(i);
        G[i].push_back(p);
    }
    lca.Build(0);
    dp.assign(n, -1);
    iota(dp.begin(), dp.end(), 0);

    auto add_up = [&](int node, int anc) {
        if (lca.depth[dp[node]] > lca.depth[anc])
           dp[node] = anc; 
    };

    int m; cin >> m;
    vector<pair<int, int>> auxx;

    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        int lc = lca.Query(a, b);
        auxx.emplace_back(a, b);
        add_up(a, lc);
        add_up(b, lc);
        fw.Mark(lca.enter[b], lca.enter[a]);
        fw.Mark(lca.enter[a], lca.enter[b]);
    }
    fw.Init();
    for (auto p : auxx) {
        fw.Update(lca.enter[p.first], lca.enter[p.second], 1);
        fw.Update(lca.enter[p.second], lca.enter[p.first], 1);
    }

    Propagate(0, -1);
    link.resize(20, vector<int>(n));
    link[0] = dp;
    /*
    cerr << "DP:\n";
    for (int i = 0; i < n; ++i) {
        cerr << dp[i] + 1 << " ";
    }
    cerr << endl;
    */
    for (int i = 1; i < 20; ++i) {
        for (int j = 0; j < n; ++j) {
            link[i][j] = link[i - 1][link[i - 1][j]];
        }
    }

    auto jump_up = [&](int node, int to) {
        if (lca.depth[link[19][node]] > lca.depth[to])
            return make_pair(-1, -1);

        int ans = 0;
        for (int i = 19; i >= 0; --i) {
            if (lca.depth[link[i][node]] > lca.depth[to]) {
                ans += (1 << i);
                node = link[i][node];
            }
        }
        return make_pair(node, ans);
    };

    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        if (lca.depth[a] > lca.depth[b]) swap(a, b);

        int lc = lca.Query(a, b);
        
        if (lc == a) {
            int res; tie(b, res) = jump_up(b, lc);
            if (b == -1) {
                cout << -1 << '\n';
            } else {
                cout << res + 1 << '\n';
            }
        } else {


        int c, d;
        tie(a, c) = jump_up(a, lc);
        tie(b, d) = jump_up(b, lc);

        if (a == -1 or b == -1) {
            cout << -1 << '\n';
        } else {
            int now = c + d + 2;
            
            if (fw.QueryRect(lca.enter[a], lca.exxit[a], lca.enter[b], lca.exxit[b]))
            {
      //          cerr << "FOUND SUB" << endl;
                now -= 1;
            }

            cout << now << '\n';
        }
        }
    }

    return 0;
}