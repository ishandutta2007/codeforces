#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 100100;
int a[N];

struct Op {
  int x, v, dir;
  bool operator < (const Op& o) const {
    return x < o.x;
  }
};

struct Query {
  int l, r, v;
};

struct Segtree {
  vector<int> t;
  int n, h;
  Segtree() {}
  Segtree(int sz) {
    h = 32 - __builtin_clz(sz);
    n = 1<<h;
    t = vector<int>(n<<1);
  }
  void assign(int x, int v) {
    x+=n;
    t[x] = v;
    for (x/=2; x; x/=2) {
      t[x] = t[x<<1]&t[x<<1|1];
    }
  }
  int query(int l, int r) {
    int ans = (1<<30)|((1<<30)-1);
    for (l+=n, r+=n; l<r; l/=2, r/=2) {
      if (l%2) {
        ans &= t[l++];
      }
      if (r%2) {
        ans &= t[--r];
      }
    }
    return ans;
  }
};

Query queries[N];

int cnt[32];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  vector<Op> ops;
  int n, m;
  cin >> n >> m;
  Segtree st(n+5);
  for (int i=1; i<=m; ++i) {
    cin >> queries[i].l >> queries[i].r >> queries[i].v;
    ops.push_back({queries[i].l, queries[i].v, 1});
    ops.push_back({queries[i].r+1, queries[i].v, -1});
  }
  sort(ops.begin(), ops.end());
  {
    int j = 0;
    for (int i=1; i<=n; ++i) {
      while (j < ops.size() && ops[j].x <= i) {
        for (int k=0; k<31; ++k) {
          if (ops[j].v&(1<<k)) {
            cnt[k] += ops[j].dir;
          }
        }
        ++j;
      }
      for (int k=0; k<31; ++k) {
        //cerr << " " << cnt[k];
        if (cnt[k]) {
          a[i] |= (1<<k);
        }
      }
      //cerr << endl;
    }
  }
  for (int i=1; i<=n; ++i) {
    st.assign(i, a[i]);
  }
  for (int i=1; i<=m; ++i) {
    if (st.query(queries[i].l, queries[i].r+1) != queries[i].v) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  for (int i=1; i<=n; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}