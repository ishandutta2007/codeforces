#include <bits/stdc++.h>
///#pragma GCC target("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")


/**
#pragma GCC opimize("O3")
#pragma GCC opimization ("unroll-loops")

**/
using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
#define int ll
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

const int N = (int) 3e5 + 7;
int n, m, x, v[N], xor_edge[N], par[N], t[N], sum[N];
bool vis[N];
vector<int> g[N], rg[N];

int root(int a) {
  return t[a];
}

bool unite(int a, int b) {
  a = root(a);
  b = root(b);
  assert(a != b);
  if (sum[a] + sum[b] < x) {
    return 0;
  }
  t[a] = b;
  sum[b] += sum[a];
  sum[b] -= x;
  return 1;
}

void build(int a) {
  vis[a] = 1;
  for (auto &i : g[a]) {
    int b = xor_edge[i] ^ a;
    if (!vis[b]) {
      build(b);
      par[b] = i;
      rg[a].push_back(i);
    }
  }
}

vector<int> fi, sc;

void dfs(int a) {
  for (auto &i : g[a]) {
    int b = xor_edge[i] ^ a;
    dfs(b);
  }
  if (par[a]) {
    int i = par[a];
    int b = xor_edge[i] ^ a;
    if (unite(a, b)) {
      fi.push_back(i);
    } else {
      sc.push_back(i);
    }
  }
}

signed realMain() {
  cin >> n >> m >> x;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    t[i] = i;
    sum[i] = v[i];
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    xor_edge[i] = x ^ y;
    g[x].push_back(i);
    g[y].push_back(i);
  }
  ll s = 0;
  for (int i = 1; i <= n; i++) {
    s += v[i];
  }
  if (s < (ll) (n - 1) * x) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  build(1);
  for (int i = 1; i <= n; i++) {
    assert(vis[i] == 1);
    swap(g[i], rg[i]);
  }
  dfs(1);
  reverse(sc.begin(), sc.end());
  for (auto &i : fi) {
    cout << i << "\n";
  }
  for (auto &i : sc) {
    cout << i << "\n";
  }
  return 0;
}