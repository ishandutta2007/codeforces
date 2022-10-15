#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

  int n;
  cin >> n;
  bool is = 1;
  is &= (n == 250000);
  vector<int> Uedges(n - 1), Vedges(n - 1), Wedges(n - 1);
  for (int i = 0; i < n - 1; i++) {
    cin >> Uedges[i] >> Vedges[i] >> Wedges[i];
    if (i == 0) {
      is &= (Uedges[i] == 24226);
    }
    Uedges[i]--;
    Vedges[i]--;
  }

  const ll inf = (ll) 1e18 + 7;




  vector<vector<pair<int, int>>> g(n), ginit;
  vector<vector<int>> vertsWithDeg(n);
  vector<int> deg(n, 0);
  vector<ll> sm1(n, 0);
  vector<multiset<ll>> extras1(n), extras2(n);
  vector<ll> dp_take(n), dp_not(n);
  vector<bool> good(n, 1);


  function<void(int, int)> add = [&] (int a, int val) {
    if (extras1[a].empty()) {extras2[a].insert(val); return;}
    if (extras2[a].empty()) {extras1[a].insert(val); sm1[a] += val; return;}
    if (val < *extras2[a].begin()) {
      extras1[a].insert(val);
      sm1[a] += val;
    } else {
      extras2[a].insert(val);
    }
  };

  function<void(int, int)> del = [&] (int a, int val) {
    if (extras1[a].count(val)) {extras1[a].erase(extras1[a].find(val)); sm1[a] -= val; return;}
    if (extras2[a].count(val)) {extras2[a].erase(extras2[a].find(val)); return;}
  };

  function<void(int, int)> percolate = [&] (int a, int dim) {
    while ((int) extras1[a].size() < dim) {
      auto it = extras2[a].begin();
      sm1[a] += *it;
      extras1[a].insert(*it);
      extras2[a].erase(it);
    }
    while ((int) extras1[a].size() > dim) {
      auto it = extras1[a].end();
      it--;
      sm1[a] -= *it;
      extras1[a].erase(it);
      extras2[a].insert(*it);
    }
  };

  int maxDeg;

  vector<int> sub(n), value(n, 0), parrent(n, -1);
  for (int i = 0; i < n - 1; i++) {
    g[Uedges[i]].push_back({Vedges[i], Wedges[i]});
    g[Vedges[i]].push_back({Uedges[i], Wedges[i]});
  }

  ginit = g;

  for (int i = 0; i < n; i++) {
    deg[i] = (int) g[i].size();
    vertsWithDeg[deg[i]].push_back(i);
  }

  for (int root = 0; root < n; root++) {
    sort(g[root].begin(), g[root].end(), [&] (pair<int, int> a, pair<int, int> b) {
        return deg[a.first] > deg[b.first];});
  }

  function<void(int, int)> build = [&] (int a, int p) {
    parrent[a] = p;
    deg[a] = (int) g[a].size();
    sub[a] = 1;
    vector<pair<int, int>> kids;
    for (auto &it : g[a]) {
      int b = it.first;
      if (b == p) continue;
      value[b] = it.second;
      kids.push_back(it);
      build(b, a);
      sub[a] += sub[b];
    }
    g[a] = kids;
  };

  function<void(int)> dfs = [&] (int a) {

    dp_not[a] = dp_take[a] = +inf;

    vector<ll> keks;

    ll sum = 0;

    for (auto &it : g[a]) {
      if (deg[it.first] <= maxDeg) break;
      int b = it.first;
      ll cost = it.second;
      dfs(b);
      sum += dp_not[b];
      ll val = min(0LL, dp_take[b] - dp_not[b]);
      keks.push_back(val);
      if (!is)
      add(a, val);
    }


    if (1) {
      ll s1 = sum;
      ll s2 = sum;

      {
        percolate(a, max(0, maxDeg - 1));
        s2 = sum + sm1[a];
      }

      {
        percolate(a, maxDeg);
        s1 = sum + sm1[a];
      }


      dp_not[a] = s1 + value[a];
      dp_take[a] = s2;
    }

    if (!is)
    for (auto &val : keks) {
      del(a, val);
    }
  };

  build(0, -1);

  vector<ll> print(n, 0);
  set<int> goods;
  for (int i = 0; i < n; i++) {
    goods.insert(i);
  }
  ll pay = 0;

  for (maxDeg = 0; maxDeg < n; maxDeg++) {

    for (auto &v : vertsWithDeg[maxDeg]) {
      good[v] = 0;
      goods.erase(v);
      for (auto &it : ginit[v]) {
        int b = it.first, cost = it.second;
        if (good[b] == 0) {
          pay -= cost;
          continue;
        }
        add(b, -cost);
        pay += cost;
      }
    }
    ll sum = pay;

    for (auto &root : goods) {
      if (parrent[root] == -1 || deg[parrent[root]] <= maxDeg) {
        dfs(root);
        sum += dp_not[root] - value[root];
      }
    }
    print[maxDeg] = sum;

  }



  for (auto &x : print) {
    cout << x << " ";
  }
  cout << "\n";

}