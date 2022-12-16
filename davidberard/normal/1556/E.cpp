#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll INFLL = 0x3f3f3f3f3f3f3f3f;

struct Segtree {
  vector<ll> mn, mx;
  int n, h;
  Segtree(int sz) {
    h = 32 - __builtin_clz(sz);
    n = 1<<h;
    mn = vector<ll>(2*n, INFLL);
    mx = vector<ll>(2*n, -INFLL);
  }
  void assign(int x, ll v) {
    x += n;
    mx[x] = mn[x] = v;
    for (x/=2; x; x/=2) {
      mn[x] = min(mn[x*2], mn[x*2+1]);
      mx[x] = max(mx[x*2], mx[x*2+1]);
    }
  }
  pair<ll, ll> query(int l, int r) {
    ll ans_mx = -INFLL, ans_mn = INFLL;
    for (l+=n, r+=n; l<r; l/=2, r/=2) {
      if (l%2) {
        ans_mx = max(ans_mx, mx[l]);
        ans_mn = min(ans_mn, mn[l]);
        ++l;
      }
      if (r%2) {
        --r;
        ans_mx = max(ans_mx, mx[r]);
        ans_mn = min(ans_mn, mn[r]);
      }
    }
    return {ans_mn, ans_mx};
  }
};

const int N = 100100;
ll av[N], bv[N], v[N], pfx[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, q;
  cin >> n >> q;
  Segtree st(n+10);
  st.assign(0, 0);
  for (int i=1; i<=n; ++i) {
    cin >> av[i];
  }
  for (int i=1; i<=n; ++i) {
    cin >> bv[i];
    v[i] = av[i]-bv[i];
    pfx[i] = pfx[i-1] + v[i];
    st.assign(i, pfx[i]);
  }

  for (int i=0; i<q; ++i) {
    int l, r;
    cin >> l >> r;
    auto [mn, mx] = st.query(l, r+1);
    if (mx > pfx[l-1] || pfx[l-1] != pfx[r]) {
      cout << -1 << "\n";
    } else {
      cout << pfx[l-1] - mn << "\n";
    }
  }

  return 0;
}