#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e5 + 7;
const ll INF = (ll) 1e18;
int n, m, q, x[N], y[N];
vector<pair<int, int>> g[N];
ll sum;
ll addup[N];
multiset<ll> s;

ll eval() {
  return *s.begin();
}

ll t[4 * N], lazy[4 * N];

void push(int v, int tl, int tr) {
  if (!lazy[v]) return;
  t[v] += lazy[v];
  int tm = (tl + tr) / 2;
  if (tl < tr) {
    lazy[2 * v] += lazy[v];
    lazy[2 * v + 1] += lazy[v];
  }
  lazy[v] = 0;
}

void add(int v, int tl, int tr, int l, int r, ll x) {
  push(v, tl, tr);
  if (tr < l || r < tl) return;
  if (l <= tl && tr <= r) {
    lazy[v] += x;
    push(v, tl, tr);
    return;
  }
  int tm = (tl + tr) / 2;
  add(2 * v, tl, tm, l, r, x);
  add(2 * v + 1, tm + 1, tr, l, r, x);
  t[v] = min(t[2 * v], t[2 * v + 1]);
}

ll get(int v, int tl, int tr, int l, int r) {
  push(v, tl, tr);
  if (tr < l || r < tl) return INF;
  if (l <= tl && tr <= r) {
    return t[v];
  }
  int tm = (tl + tr) / 2;
  return min(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

void add(int l, int r, ll x) {
  add(1, 0, n, l, r, x);
}

ll get(int l, int r) {
  return get(1, 0, n, l, r);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> m >> q;
  for (int i = 1; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    sum += c;
    g[a].push_back({b, c});
  }
  for (int b = 0; b < n; b++) {
    add(b, b, y[b]);
  }
  for (int a = 1; a <= n; a++) {
    ll sol = INF;
    for (auto &it : g[a]) {
      add(0, it.first - 1, it.second);
    }
    addup[a] = get(0, n - 1);
    s.insert(addup[a] + x[a]);
  }
  cout << eval() << "\n";
  while (q--) {
    int i, nw;
    cin >> i >> nw;
    s.erase(s.find(addup[i] + x[i]));
    x[i] = nw;
    s.insert(addup[i] + x[i]);
    cout << eval() << "\n";
  }
  return 0;
}