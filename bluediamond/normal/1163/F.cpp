#include <bits/stdc++.h>

using namespace std;

bool home = 1;
#define int long long
signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = (int) 4e5 + 7;
const int INF = (int) 1e18;

int lazy[4 * N], t[4 * N], sz;

void push(int v, int tl, int tr) {
  if (lazy[v] != INF) {
    t[v] = min(t[v], lazy[v]);
    if (tl < tr) {
      lazy[2 * v] = min(lazy[2 * v], lazy[v]);
      lazy[2 * v + 1] = min(lazy[2 * v + 1], lazy[v]);
    }
    lazy[v] = INF;
  }
}

void upd(int v, int tl, int tr, int l, int r, int val) {
  push(v, tl, tr);
  if (tr < l || r < tl) return;
  if (l <= tl && tr <= r) {
    lazy[v] = min(lazy[v], val);
    push(v, tl, tr);
    return;
  }
  int tm = (tl + tr) / 2;
  upd(2 * v, tl, tm, l, r, val);
  upd(2 * v + 1, tm + 1, tr, l, r, val);
  t[v] = min(t[2 * v], t[2 * v + 1]);
}

int get(int v, int tl, int tr, int l, int r) {
  push(v, tl, tr);
  if (tr < l || r < tl) return INF;
  if (l <= tl && tr <= r) return t[v];
  int tm = (tl + tr) / 2;
  return min(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

void upd(int l, int r, int val) {
  upd(1, 1, sz, l, r, val);
}

int get(int l, int r) {
  return get(1, 1, sz, l, r);
}

int n, m, q, x[N], y[N], w[N], d1[N], dn[N], p1[N], pn[N], o1[N], on[N], num[N];
bool bad[N];
bool is_spec[N];
vector<int> g[N];

vector<int> nodes;

signed realMain() {
  for (int i = 0; i < 4 * N; i++) lazy[i] = t[i] = INF;

  cin >> n >> m >> q;
  for (int i = 1; i <= m; i++) {
    cin >> x[i] >> y[i] >> w[i];
    g[x[i]].push_back(i);
    g[y[i]].push_back(i);
    p1[i] = -1;
    pn[i] = -1;
  }
  {
    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= n; i++) d1[i] = INF;
    d1[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
      auto it = pq.top();
      pq.pop();
      int a = it.second, val = -it.first;
      if (d1[a] != val) continue;
      for (auto &i : g[a]) {
        int b = x[i] + y[i] - a;
        if (d1[a] + w[i] < d1[b]) {
          d1[b] = d1[a] + w[i];
          p1[b] = a;
          pq.push({-d1[b], b});
        }
      }
    }
  }
  {
    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= n; i++) dn[i] = INF;
    dn[n] = 0;
    pq.push({0, n});
    while (!pq.empty()) {
      auto it = pq.top();
      pq.pop();
      int a = it.second, val = -it.first;
      if (dn[a] != val) continue;
      for (auto &i : g[a]) {
        int b = x[i] + y[i] - a;
        if (dn[a] + w[i] < dn[b]) {
          dn[b] = dn[a] + w[i];
          pn[b] = a;
          pq.push({-dn[b], b});
        }
      }
    }
  }

  {
    int nod = 1;
    while (nod != n) {
      nodes.push_back(nod);
      nod = pn[nod];
    }
    nodes.push_back(n);
    int y = 0;
    for (auto &x : nodes) {
      is_spec[x] = 1;
      num[x] = ++y;
    }
  }
  sz = (int) nodes.size() - 1;

  for (int i = 1; i <= n; i++) {
    if (d1[i] == INF || dn[i] == INF) {
      bad[i] = 1;
    }
  }

  {
    vector<pair<int, int>> kek;
    for (int i = 1; i <= n; i++) {
      if (bad[i]) continue;
      kek.push_back({d1[i], i});
    }
    sort(kek.begin(), kek.end());
    assert(kek[0].second == 1);
    for (int j = 1; j < (int) kek.size(); j++) {
      int i = kek[j].second;
      assert(p1[i] != -1);
      if (is_spec[i]) {
        o1[i] = o1[p1[i]] + 1;
      } else {
        o1[i] = o1[p1[i]];
      }
    }
  }

  {
    vector<pair<int, int>> kek;
    for (int i = 1; i <= n; i++) {
      if (bad[i]) continue;
      kek.push_back({dn[i], i});
    }
    sort(kek.begin(), kek.end());
    assert(kek[0].second == n);
    for (int j = 1; j < (int) kek.size(); j++) {
      int i = kek[j].second;
      assert(pn[i] != -1);
      if (is_spec[i]) {
        on[i] = on[pn[i]] + 1;
      } else {
        on[i] = on[pn[i]];
      }
    }
  }

  for (int step = 1; step <= 2; step++) {
    for (int i = 1; i <= m; i++) {
      if (bad[x[i]] || bad[y[i]]) continue;
      if (is_spec[x[i]] && is_spec[y[i]] && (d1[x[i]] + dn[y[i]] + w[i] == d1[n] || d1[y[i]] + dn[x[i]] + w[i] == d1[n])) continue;
      int l = o1[x[i]] + 1, r = sz - on[y[i]];
      if (l > r) continue;
      assert(1 <= l && r <= sz);
      upd(l, r, d1[x[i]] + dn[y[i]] + w[i]);
    }
    for (int i = 1; i <= m; i++) {
      swap(x[i], y[i]);
    }
  }

  for (int it = 1; it <= q; it++) {
    int i, nw;
    cin >> i >> nw;
    if (is_spec[x[i]] && is_spec[y[i]] && (d1[x[i]] + dn[y[i]] + w[i] == d1[n] || d1[y[i]] + dn[x[i]] + w[i] == d1[n])) {
      int ret = d1[n] - (w[i] - nw);
      int jj = min(num[x[i]], num[y[i]]);
      ret = min(ret, get(jj, jj));
      cout << ret << "\n";
    } else {
      int ret = min(d1[n], min(d1[x[i]] + dn[y[i]], d1[y[i]] + dn[x[i]]) + nw);
      cout << ret << "\n";
    }


  }
  return 0;
}