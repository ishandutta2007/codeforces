#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef long long ll;
const int INF = (int) 1e18 + 7;

struct line {
  ll a, b;
  int i;
  line() {
    i = -1;
  }
  ll eval(ll x) {
    if (i == -1) return INF;
    return a * x + b;
  }
};



struct chao {

  /// min Chao

  const int X = (int) 1e5 + 7;
  vector<line> t;

  chao() : t(4 * (X + 7)) {
  }

  void add(int v, int tl, int tr, line l2) {
    line l1 = t[v];
    if (l1.i == -1) {
      t[v] = l2;
      return;
    }
    if (l2.eval(tl) > l1.eval(tl) && l2.eval(tr) > l1.eval(tr)) {
      return;
    }
    int tm = (tl + tr) / 2;
    if (tl == tr) {
      return;
    }
    if (l1.eval(tl) > l2.eval(tl)) {
      line l3 = l1;
      l1 = l2;
      l2 = l3;
    }
    if (l1.eval(tm) < l2.eval(tm)) { /// l1 is better than l2 at point mid
      t[v] = l1;
      add(2 * v + 1, tm + 1, tr, l2);
    } else { /// l2 is better than l1 at point mid
      t[v] = l2;
      add(2 * v, tl, tm, l1);
    }
  }


  void add(line l) {
    add(1, 0, X, l);
  }

  line best(line a, line b, ll x) {
    if (a.i == -1) return b;
    if (b.i == -1) return a;
    if (a.eval(x) < b.eval(x)) return a;
    else return b;
  }

  line get(int v, int tl, int tr, int x) { /// x should be ll, some small inconsistency...
    if (tl == tr) return t[v];
    line ret = t[v];
    int tm = (tl + tr) / 2;
    if (x <= tm) {
      return best(ret, get(2 * v, tl, tm, x), x);
    } else {
      return best(ret, get(2 * v + 1, tm + 1, tr, x), x);
    }
  }

  line get(int x) { /// again, a small inconsistency when coming to the data type of x
    return get(1, 0, +X, x);
  }
};

signed main() {

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<int, int>>> g(n);
  vector<int> best(n, INF);

  for (int it = 0; it < m; it++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }

  best[0] = 0;

  function<void()> graph_upd = [&]() {
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++) {
      pq.push({-best[i], i});
    }
    while (!pq.empty()) {
      int a;
      {
        auto it = pq.top();
        pq.pop();
        if (best[it.second] != -it.first) {
          continue;
        }
        a = it.second;
      }
      for (auto &it : g[a]) {
        int b = it.first;
        int nw = best[a] + it.second;
        if (nw < best[b]) {
          best[b] = nw;
          pq.push({-best[b], b});
        }
      }
    }
  };


  function<void()> cht_upd = [&]() {
    chao li;
    for (int i = 0; i < n; i++) {
      line ln;
      ln.a = -2 * i;
      ln.b = best[i] + i * i;
      ln.i = i + 1;
      li.add(ln);
    }
    for (int i = 0; i < n; i++) {
      best[i] = min(best[i], li.get(i).eval(i) + i * i);
    }
  };

  graph_upd();
  for (int it = 1; it <= k; it++) {
    cht_upd();
    graph_upd();
  }
  for (int i = 0; i < n; i++) {
    cout << best[i] << " ";
  }
  cout << "\n";


  return 0;
}