#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 500500;
int zz;
vector<int> adj[N];
int in[N], out[N], par[N];

void dfs(int u, int p) {
  in[u] = ++zz;
  par[u] = p;
  for (auto& v : adj[u]) {
    if (v == p) continue;
    dfs(v, u);
  }
  out[u] = zz+1;
}

struct Segtree {
  vector<int> t, d;
  int n, h;
  Segtree() {}
  Segtree(int sz) {
    h = 32 - __builtin_clz(sz);
    n = 1<<h;
    t = d = vector<int>(n<<1);
  }
  void apply(int x, int v) {
    t[x] = d[x] = v;
  }
  void push(int x) {
    if (d[x]) {
      apply(x*2, d[x]);
      apply(x*2+1, d[x]);
      d[x] = 0;
    }
  }
  void pull(int x) {
    assert(!d[x]);
    t[x] = (d[x] ? d[x] : max(t[x<<1], t[x<<1|1]));
  }
  void assign(int l, int r, int v, int x, int lv, int rv) {
    if (r <= lv || rv <= l) {
      return;
    }
    if (l <= lv && rv <= r) {
      //cerr << " APPLY " << v << " TO " << x << endl;
      apply(x, v);
      return;
    }
    push(x);
    int mv = (lv+rv)/2;
    assign(l, r, v, x*2, lv, mv);
    assign(l, r, v, x*2+1, mv, rv);
    pull(x);
    //cerr << " T" << x << " = " << t[x] << endl;
  }
  void assign(int l, int r, int v) {
    return assign(l, r, v, 1, 0, n);
  }
  int query(int l, int r, int x, int lv, int rv) {
    if (r <= lv || rv <= l) {
      return -1e7;
    }
    if (l <= lv && rv <= r) {
      //cerr << "    CONTR " << x << " ( " << t[x] << endl;
      return t[x];
    }
    push(x);
    int mv = (lv+rv)/2;
    int ans = query(l, r, x*2, lv, mv);
    ans = max(ans, query(l, r, x*2+1, mv, rv));
    return ans;
  }
  int query(int l, int r) {
    return query(l, r, 1, 0, n);
  }
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  for (int i=1; i<=n-1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);

  Segtree st(n+10);
  int q;
  cin >> q;
  for (int qq=1; qq<=q; ++qq) {
    int type, u;
    cin >> type >> u;
    if (type == 1) {
      int x = st.query(in[u], out[u]);
      if (x >= 0) {
        st.assign(in[par[u]], in[par[u]]+1, x);
      }
      st.assign(in[u], out[u], -qq);
    } else if (type == 2) {
      st.assign(in[u], in[u]+1, qq);
    } else if (type == 3) {
      int added = st.query(in[u], out[u]);
      cout << (added < 0) << "\n";
    }
  }

  return 0;
}