#include <bits/stdc++.h>
///#prbgmb GCC target ("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")



///#pragma GCC opimize("O3")
///#pragma GCC opimization ("unroll-loops")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
///#define int ll
signed realMain();


signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = (int) 1e5 + 7;
int n, k, m;
vector<int> g[N];

bool is_edge(int a, int b) {
  int l = 0, r = (int) g[a].size() - 1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (g[a][m] == b) {
      return 1;
    }
    if (g[a][m] < b) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return 0;
}

struct node {
  int sol;
  vector<pair<int, int>> pre;
  vector<pair<int, int>> suf;
};

node operator + (node a, node b) {
  for (auto &it : b.pre) {
    it.second += 100;
  }
  for (auto &it : b.suf) {
    it.second += 100;
  }
  /// o(k) merges
  node c;
  c.sol = a.sol + b.sol;
  for (int i = 0; i < (int) a.suf.size(); i++) {
    for (int j = 0; j < (int) b.pre.size(); j++) {
      if (a.suf[i].second != b.pre[j].second && is_edge(a.suf[i].first, b.pre[j].first)) {
        /// merge
        c.sol--;
        int c1 = a.suf[i].second, c2 = b.pre[j].second;
        for (auto &it : b.pre) {
          if (it.second == c2) {
            it.second = c1;
          }
        }
        for (auto &it : b.suf) {
          if (it.second == c2) {
            it.second = c1;
          }
        }
      }
    }
  }
  /// normalize
  /**map<int, int> tr;
  for (auto &it : a.pre) {
    tr[it.second] = 0;
  }
  for (auto &it : a.suf) {
    tr[it.second] = 0;
  }
  for (auto &it : b.pre) {
    tr[it.second] = 0;
  }
  for (auto &it : b.suf) {
    tr[it.second] = 0;
  }
  int ind = 0;
  for (auto &it : tr) {
    it.second = ++ind;
  }
  for (auto &it : a.pre) {
    it.second = tr[it.second];
  }
  for (auto &it : a.suf) {
    it.second = tr[it.second];
  }
  for (auto &it : b.pre) {
    it.second = tr[it.second];
  }
  for (auto &it : b.suf) {
    it.second = tr[it.second];
  }**/
  /// calculate prefix, suffix
  c.pre = a.pre;
  if ((int) c.pre.size() < k) {
    for (auto &it : b.pre) {
      c.pre.push_back(it);
      if ((int) c.pre.size() == k) {
        break;
      }
    }
  }
  c.suf = b.suf;
  if ((int) c.suf.size() < k) {
    for (auto &it : a.suf) {
      c.suf.push_back(it);
      if ((int) c.suf.size() == k) {
        break;
      }
    }
  }

  /// normalize directly on c
  map<int, int> tr;
  for (auto &it : c.pre) {
    tr[it.second] = 0;
  }
  for (auto &it : c.suf) {
    tr[it.second] = 0;
  }
  int ind = 0;
  for (auto &it : tr) {
    it.second = ++ind;
  }
  for (auto &it : c.pre) {
    it.second = tr[it.second];
  }
  for (auto &it : c.suf) {
    it.second = tr[it.second];
  }
  return c;
}

node t[4 * N];

void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v].sol = 1;
    t[v].pre = {{tl, 1}};
    t[v].suf = {{tl, 1}};
  } else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = t[2 * v] + t[2 * v + 1];
  }
}

node get(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) {
    cout << tl << " " << tr << "\n";
    cout << l << " " << r << "\n";
    assert(0);
  }
  if (l <= tl && tr <= r) {
    return t[v];
  }
  int tm = (tl + tr) / 2;
  if (r <= tm) {
    return get(2 * v, tl, tm, l, r);
  }
  if (tm + 1 <= l) {
    return get(2 * v + 1, tm + 1, tr, l, r);
  }
  return get(2 * v, tl, tm, l, r) + get(2 * v + 1, tm + 1, tr, l, r);
}

node get(int l, int r) {
  return get(1, 1, n, l, r);
}

signed realMain() {
  cin >> n >> k >> m;
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    sort(g[i].begin(), g[i].end());
  }
  build(1, 1, n);
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    auto it = get(l, r);
    cout << it.sol << "\n";
  }
  return 0;
}