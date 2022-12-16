#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 200200;
int a[N];
int in[N], out[N];
vector<int> adj[N];
int zz;
int f[N], dep[N];

void dfs(int u, int p, int d) {
  in[u] = ++zz;
  dep[u] = d;
  f[zz] = (d%2 ? a[u] : -a[u]);
  for (auto& v : adj[u]) {
    if (v == p) continue;
    dfs(v, u, d+1);
  }
  out[u] = zz+1;
}

struct Segtree {
  vector<int> d;
  int n, h;
  Segtree() {}
  Segtree(int sz, bool take=false) {
    h = 32 - __builtin_clz(sz);
    n = 1<<h;
    d = vector<int>(n<<1);
    if (take) {
      for (int i=0; i<sz; ++i) {
        d[i+n] = f[i];
      }
    }
  }
  void add(int l, int r, int v) {
    for (l+=n, r+=n; l<r; l/=2, r/=2) {
      if (l%2) {
        d[l++] += v;
      }
      if (r%2) {
        d[--r] += v;
      }
    }
  }
  int query(int x) {
    int ans = 0;
    for (x+=n; x; x/=2) {
      ans += d[x];
    }
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  for (int i=1; i<n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, -1, 1);
  Segtree st(n+5, true);
  for (int qq=1; qq<=m; ++qq) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, v;
      cin >> x >> v;
      st.add(in[x], out[x], v*(dep[x]%2 ? 1 : -1));
    } else if (type == 2) {
      int x;
      cin >> x;
      cout << st.query(in[x])*(dep[x]%2 ? 1 : -1) << "\n";
    }
  }
  return 0;
}