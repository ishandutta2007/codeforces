#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

// 7:57;

struct Segtree {
  vector<ll> d, t;
  int n, h;
  Segtree(int sz) {
    h = 32 - __builtin_clz(sz);
    n = 1<<h;
    t = vector<ll>(n<<1);
    d = vector<ll>(n<<1);
  }
  ll seg_size(int x) {
    return 1LL<<(h-31 + __builtin_clz(x));
  }
  void apply(int x, ll v) {
    d[x] += v;
    t[x] += seg_size(x)*v;
  }
  void push(int x) {
    if (d[x]) {
      apply(x<<1, d[x]);
      apply(x<<1|1, d[x]);
      d[x] = 0;
    }
  }
  void pull(int x) {
    t[x] = t[x<<1] + t[x<<1|1];
    t[x] += seg_size(x)*d[x];
  }
  void add(int l, int r, ll v, int x, int lv, int rv) {
    if (r <= lv || rv <= l) {
      return;
    }
    if (l <= lv && rv <= r) {
      apply(x, v);
      return;
    }
    push(x);
    int mv = (lv+rv)/2;
    add(l, r, v, x*2, lv, mv);
    add(l, r, v, x*2+1, mv, rv);
    pull(x);
  }
  void add(int l, int r, ll v) {
    add(l, r, v, 1, 0, n);
  }
  ll query(int l, int r, int x, int lv, int rv) {
    if (r <= lv || rv <= l) {
      return 0;
    }
    if (l <= lv && rv <= r) {
      return t[x];
    }
    push(x);
    int mv = (lv+rv)/2;
    ll ans = 0;
    ans += query(l, r, x*2, lv, mv);
    ans += query(l, r, x*2+1, mv, rv);
    return ans;
  }
  ll query(int l, int r) {
    return query(l, r, 1, 0, n);
  }
};

const int N = 100100;
const int LG = 18;
int par[N][LG];
int dep[N];
int r = 1;
int in[N], out[N];
vector<int> adj[N];
int n;

void build() {
  for (int l=0; l+1<LG; ++l) {
    for (int i=1; i<=n; ++i) {
      par[i][l+1] = par[par[i][l]][l];
    }
  }
}

int swim(int u, int x) {
  for (int i=0; x; x/=2, ++i) {
    if (x&1) {
      u = par[u][i];
    }
  }
  return u;
}

int lca(int u, int v) {
  if (dep[u] > dep[v]) {
    swap(u, v);
  }
  v = swim(v, dep[v]-dep[u]);
  for (int l=LG-1; l>=0; --l) {
    if (par[u][l] != par[v][l]) {
      u = par[u][l];
      v = par[v][l];
    }
  }
  if (u != v) {
    u = par[u][0];
    v = par[v][0];
  }
  assert(u == v);
  return u;
}

int zz = 0;
void dfs(int u, int p, int d) {
  in[u] = ++zz;
  dep[u] = d;
  par[u][0] = p;
  for (auto& v : adj[u]) {
    if (v == p) {
      continue;
    }
    dfs(v, u, d+1);
  }
  out[u] = zz+1;
}

int ai[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int qq;
  cin >> n >> qq;
  for (int i=1; i<=n; ++i) {
    cin >> ai[i];
  }
  for (int i=0; i<n-1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0, 1);
  build();
  Segtree st(n+10);
  for (int i=1; i<=n; ++i) {
    st.add(in[i], in[i]+1, ai[i]);
  }
  int anscnt = 0;
  int qqi = qq;
  while (qq--) {
    int type;
    cin >> type;
    if (type == 1) {
      int v;
      cin >> v;
      r = v;
    } else if (type == 2) {
      ++anscnt;
      int u, v, x;
      cin >> u >> v >> x;
      if (anscnt == 3 && n == 50 && qqi == 50) {
      }
      int w = lca(u, v);
      if (dep[lca(w, r)] < dep[w]) { // root is ancestor
        st.add(in[w], out[w], x);
      } else if ((dep[u] >= dep[r] && swim(u, dep[u]-dep[r]) == r) || (dep[v] >= dep[r] && swim(v, dep[v]-dep[r]) == r)) {
        st.add(in[1], out[1], x);
      } else {
        int y = lca(r, u);
        int y2 = lca(r, v);
        if (dep[y2] > dep[y]) {
          swap(y2, y);
        }
        assert(dep[r] > dep[y]);
        assert(dep[r] >= dep[w]);
        int z = swim(r, dep[r]-dep[y]-1);
        st.add(in[1], out[1], x);
        st.add(in[z], out[z], -x);
      }
    } else if (type == 3) {
      int v;
      cin >> v;
      if (dep[r] >= dep[v] && swim(r, dep[r]-dep[v]) == v) { // root is a descendant of v
        ll ans = st.query(in[1], out[1]);
        if (r != v) {
          int w = swim(r, dep[r]-dep[v]-1);
          ans -= st.query(in[w], out[w]);
        }
        cout << ans << "\n";
      } else {
        ll ans = st.query(in[v], out[v]);
        cout << ans << '\n';
      }
    }
  }
  return 0;
}