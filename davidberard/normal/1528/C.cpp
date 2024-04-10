#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

struct Segtree {
  vector<ll> t;
  int n, h;
  Segtree(int sz) {
     h = 32 - __builtin_clz(sz);
     n = 1<<h;
     t = vector<ll>(n<<1, 0);
  }
  void add(int x, ll v) {
    for (x+=n; x; x/=2) {
      t[x] += v;
    }
  }
  ll query(int l, int r) {
    ll ans = 0;
    for (l+=n, r+=n; l<r; l/=2, r/=2) {
      if (l%2) {
        ans += t[l++];
      }
      if (r%2) {
        ans += t[--r];
      }
    }
    return ans;
  }
};

const int N = 300300;
vector<int> chA[N], chB[N];
int parA[N], parB[N];

int in[N], out[N];
int zz;
Segtree stu(1), sti(1);

void dfsB(int u, int p) {
  in[u] = ++zz;
  for (auto& v : chB[u]) {
    dfsB(v, u);
  }
  out[u] = ++zz;
}

int clq_size = 0;
void add_vtx(int u) {
  ++clq_size;
  sti.add(in[u], u);
  stu.add(in[u], u);
  stu.add(out[u], -u);
}
void remove_vtx(int u) {
  --clq_size;
  sti.add(in[u], -u);
  stu.add(in[u], -u);
  stu.add(out[u], u);
}
void apply_vtx(int u, int dir) {
  if (dir == 1) {
    add_vtx(u);
  } else if (dir == -1) {
    remove_vtx(u);
  }
}

vector<pair<int, int>> ops;
int ans = 0;
void dfsA(int u) {
  int within = sti.query(in[u], out[u]);
  int added = 0;
  if (!within) {
    int above = stu.query(0, in[u]);
    if (above) {
      remove_vtx(above);
      ops.push_back({above, -1});
      ++added;
    }
    add_vtx(u);
    ops.push_back({u, 1});
    ++added;
  }

  ans = max(ans, clq_size);

  for (auto& v : chA[u]) {
    dfsA(v);
  }

  while (added--) {
    auto [x, dir] = ops.back(); ops.pop_back();
    apply_vtx(x, -dir);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int n;
    zz = 0;
    ans = 0;
    cin >> n;
    for (int i=1; i<=n; ++i) {
      chA[i].clear();
      chB[i].clear();
    }
    for (int i=2; i<=n; ++i) {
      cin >> parA[i];
      chA[parA[i]].push_back(i);
    }
    for (int i=2; i<=n; ++i) {
      cin >> parB[i];
      chB[parB[i]].push_back(i);
    }
    stu = Segtree(n*2+10);
    sti = Segtree(n*2+10);
    dfsB(1, 0);
    dfsA(1);
    cout << ans << "\n";
  }
  return 0;
}