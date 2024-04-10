#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 100100;
int a[N];

struct Segtree {
  vector<int> t, d;
  int n, h;
  Segtree() {}
  Segtree(int ssz, int bt) {
    h = 32 - __builtin_clz(ssz);
    n = 1<<h;
    t = d = vector<int>(n<<1);
    for (int i=n; i<n+ssz; ++i) {
      t[i] = ((a[i-n]&(1<<bt)) != 0);
    }
    for (int i=n-1; i>0; --i) {
      t[i] = t[i<<1]+t[i<<1|1];
    }
  }
  void apply(int x, int sz) {
    d[x] ^= 1;
    t[x] = sz-t[x];
  }
  void push(int x, int sz) {
    if (d[x]) {
      apply(x*2, sz/2);
      apply(x*2+1, sz/2);
      d[x] = 0;
    }
  }
  void pull(int x, int sz) {
    t[x] = t[x<<1]+t[x<<1|1];
    if (d[x]) {
      t[x] = sz-t[x];
    }
  }
  void flip(int l, int r, int x, int lv, int rv) {
    if (r<=lv || rv<=l) {
      return;
    }
    if (l<=lv && rv<=r) {
      apply(x, rv-lv);
      return;
    }
    push(x, rv-lv);
    int mv = (lv+rv)/2;
    flip(l, r, x*2, lv, mv);
    flip(l, r, x*2+1, mv, rv);
    pull(x, rv-lv);
  }
  void flip(int l, int r) {
    flip(l, r, 1, 0, n);
  }
  int query(int l, int r, int x, int lv, int rv) {
    if (r<=lv || rv<=l) {
      return 0;
    }
    if (l<=lv && rv<=r) {
      return t[x];
    }
    push(x, rv-lv);
    int mv = (lv+rv)/2;
    return query(l, r, x*2, lv, mv)+query(l, r, x*2+1, mv, rv);
  }
  int query(int l, int r) {
    return query(l, r, 1, 0, n);
  }
};

Segtree st[20];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  for (int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  for (int i=0; i<20; ++i) {
    st[i] = Segtree(n+2, i);
  }
  int m;
  cin >> m;
  for (int i=1; i<=m; ++i) {
    int type, l, r;
    cin >> type >> l >> r;
    if (type == 1) {
      ll ans = 0;
      for (int j=0; j<20; ++j) {
        ans += (1LL<<j)*st[j].query(l, r+1);
      }
      cout << ans << "\n";
    } else if (type == 2) {
      int x;
      cin >> x;
      for (int j=0; j<20; ++j) {
        if (x&(1<<j)) {
          st[j].flip(l, r+1);
        }
      }
    }
  }
  return 0;
}