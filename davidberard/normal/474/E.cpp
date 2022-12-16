#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

// 11:25

struct Segtree {
  vector<pii> t;
  int n, h;
  Segtree(int sz) {
    h = 32 - __builtin_clz(sz);
    n = 1<<h;
    t = vector<pii>(n<<1);
  }
  void assign(int x, int v, int ind) {
    x+=n;
    t[x].first = v;
    t[x].second = ind;
    for (x/=2; x; x/=2) {
      t[x] = max(t[x<<1], t[x<<1|1]);
    }
  }
  pii query(int l, int r) {
    pii mx = pii(0, 0);
    for (l+=n, r+=n; l<r; l/=2, r/=2) {
      if (l%2) {
        mx = max(mx, t[l++]);
      }
      if (r%2) {
        mx = max(mx, t[--r]);
      }
    }
    return mx;
  }
};

const int N = 100100;
ll n, d;
ll h[N];

int a[N], nxt[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> d;
  map<ll, int> mp;
  for (int i=1; i<=n; ++i) {
    cin >> h[i];
    mp[h[i]] = -1;
  }
  mp[(ll) 1e16] = -1;
  int zz = 0;
  for (auto& p : mp) {
    p.second = ++zz;
  }

  Segtree st(n+10);

  for (int i=n; i>=1; --i) {
    int lo = mp.upper_bound(h[i]-d)->second;
    int hi = mp.lower_bound(h[i]+d)->second;
    pii res = st.query(0, lo);
    res = max(res, st.query(hi, st.n));
    a[i] = res.first+1;
    nxt[i] = res.second;
    int k = mp[h[i]];
    st.assign(k, a[i], i);
  }

  pii best = st.query(0, st.n);
  cout << best.first << "\n";
  int x = best.second;
  while (x) {
    cout << x << " ";
    x = (a[x] > 1 ? nxt[x] : 0);
  }
  cout << "\n";

  return 0;
}