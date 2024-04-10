#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

struct Query {
  int t, x, y;
};
const int maxn = 101010;
int n, q;
int a[maxn];
vector<int> gr[maxn];
Query qr[maxn];

int par[maxn], cnt[maxn];
void dfs1(int u) {
  if (u != par[u]) {
    gr[u].erase(find(gr[u].begin(), gr[u].end(), par[u]));
  }
  cnt[u] = 1;
  for (auto& v: gr[u]) {
    par[v] = u;
    dfs1(v);
    cnt[u] += cnt[v];
    if (cnt[gr[u][0]] < cnt[v]) swap(gr[u][0], v);
  }
}

int hld_pos[maxn], head[maxn], timer;
void dfs2(int u) {
  hld_pos[u] = timer++;
  if (head[u] == 0) head[u] = u;
  if (gr[u].size()) head[gr[u][0]] = head[u];
  for (auto v: gr[u]) {
    dfs2(v);
  }
}

struct BIT {
  vector<ll> data;
  BIT(int len): data(len + 10) {}
  ll get(int i) const {
    ll ans = 0;
    for (++i; i > 0; i -= i & -i) ans += data[i];
    return ans;
  }
  void upd(int i, ll d) {
    for (++i; i < (int)data.size(); i += i & -i) {
      data[i] += d;
    }
  }
  ll get(int from, int to) const {  // [from, to]
    return get(to) - get(from - 1);
  }
  void reset() {
    fill_n(data.begin(), data.size(), 0);
  }
} bit(maxn);

ll dist(int x, int y) {
  return max(abs(x + y), abs(x - y));
}

void upd(int u, int new_val) {
  if (u != head[u]) {
    bit.upd(hld_pos[u], dist(new_val, a[par[u]]) - dist(a[u], a[par[u]]));
  }
  if (gr[u].size()) {
    int v = gr[u][0];
    bit.upd(hld_pos[v], dist(new_val, a[v]) - dist(a[u], a[v]));
  }
  a[u] = new_val;
}

ll get_dist(int u, int v) {
  ll ans = 0;
  while (head[u] != head[v]) {
    if (cnt[head[u]] > cnt[head[v]]) swap(u, v);
    int p = head[u];
    ans += bit.get(hld_pos[p] + 1, hld_pos[u]) + dist(a[p], a[par[p]]);
    u = par[p];
  }
  if (cnt[u] > cnt[v]) swap(u, v);
  if (u != v) {
    ans += bit.get(hld_pos[gr[v][0]], hld_pos[u]);
  }
  return ans;
}

vector<ll> solve() {
  par[1] = 1;
  dfs1(1);
  timer = 0;
  fill_n(head, n + 1, 0);
  dfs2(1);
  bit.reset();
  for (int i = 2; i <= n; ++i) {
    bit.upd(hld_pos[i], dist(a[i], a[par[i]]));
  }

  vector<ll> ans;
  for (int i = 0; i < q; ++i) {
    auto [t, x, y] = qr[i];
    if (t == 1) {
      upd(x, y);
    } else {
      ll cur_ans = get_dist(x, y);
      ans.push_back(cur_ans);
    }
  }
  return ans;
}

vector<ll> brute() {
  vector<int> na(a, a + n + 1);
  vector<ll> ans;
  for (int i = 0; i < q; ++i) {
    auto [t, x, y] = qr[i];
    if (t == 1) {
      na[x] = y;
    } else {
      vector<ll> d(n + 1, -1);
      d[x] = 0;
      queue<int> qu;
      for (qu.push(x); qu.size(); qu.pop()) {
        int u = qu.front();
        for (auto v: gr[u]) {
          if (d[v] != -1) continue;
          d[v] = d[u] + dist(na[u], na[v]);
          qu.push(v);
        }
      }
      ans.push_back(d[y]);
    }
  }
  return ans;
}

mt19937 rng;
#define rand() ((int)(rng() >> 1))
void check() {
  stringstream inp;
  n = rand() % 100'000 + 1;
  q = rand() % 100'000 + 1;
  inp << n << ' ' << q << endl;
  for (int i = 1; i <= n; ++i) {
    a[i] = rand() % 20000 - 10000;
    inp << a[i] << ' ';
  }
  inp << endl;
  vector<int> nodes;
  for (int i = 0; i <= n; ++i) gr[i].clear();
  for (int i = 0; i < n; ++i) nodes.push_back(i + 1);
  shuffle(nodes.begin(), nodes.end(), rng);
  for (int i = 1; i < n; ++i) {
    int u = nodes[i];
    int v = nodes[rand() % i];
    inp << u << ' ' << v << endl;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }

  for (int i = 0; i < q; ++i) {
    qr[i].t = rand() % 2 + 1;
    if (qr[i].t == 1) {
      qr[i].x = rand() % n + 1;
      qr[i].y = rand() % 20000 - 10000;
    } else {
      qr[i].x = rand() % n + 1;
      qr[i].y = rand() % n + 1;
    }
    inp << qr[i].t << ' ' << qr[i].x << ' ' << qr[i].y << endl;
  }
  auto exp = brute();
  auto ans = solve();
  exit(0);
  if (exp == ans) {
    cout << "OK" << endl;
    return ;
  }
  cout << inp.str() << endl;
  for (auto i: exp) cout << i << ' ';
  cout << endl;
  for (auto i: ans) cout << i << ' ';
  cout << endl;
  exit(0);
}

int main() {
//  while(1) check();
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }

  for (int i = 0; i < q; ++i) {
    cin >> qr[i].t >> qr[i].x >> qr[i].y;
  }

//#ifdef LOCAL
//  for (auto i: brute()) {
//    cout << i << ' ';
//  }
//  cout << endl;
//#endif
  for (auto i: solve()) {
    cout << i << '\n';
  }

  return 0;
}