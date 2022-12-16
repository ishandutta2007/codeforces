#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll INFLL =0x3f3f3f3f3f3f3f3f;

struct Segtree {
  vector<ll> d;
  vector<ll> t;
  int n, h;
  Segtree (int sz) {
    h = 32 - __builtin_clz(sz);
    n = 1<<h;
    t = vector<ll>(n<<1, INFLL);
    d = vector<ll>(n<<1);
  }
  void clear() {
    for (auto& x : t) {
      x = INFLL;
    }
    for (auto& x : d) {
      x = 0;
    }
  }
  void apply(int x, ll v) {
    t[x] += v;
    d[x] += v;
  }
  void push(int x) {
    if (d[x]) {
      apply(x<<1, d[x]);
      apply(x<<1|1, d[x]);
      d[x] = 0;
    }
  }
  void pull(int x) {
    t[x] = min(t[x<<1], t[x<<1|1]) + d[x];
  }
  void pull_all() {
    for (int i=n-1; i; --i) {
      pull(i);
    }
  }
  ll query(int l, int r, int x, int lv, int rv) {
    if (r <= lv || rv <= l) {
      return INFLL;
    }
    if (l <= lv && rv <= r) {
      return t[x];
    }
    push(x);
    int mv = (lv+rv)/2;
    ll a = query(l, r, x*2, lv, mv);
    ll b = query(l, r, x*2+1, mv, rv);
    return min(a, b);
  }
  ll query(int l, int r) {
    return query(l, r, 1, 0, n);
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
  void assign(int x, ll v) {
    x += n;
    for (int i=h; i; --i) {
      push(x>>i);
    }
    t[x] = v;
    d[x] = 0;
    for (int i=1; i<=h; ++i) {
      pull(x>>i);
    }
  }
};

const int N = 35035;
const int K = 110;
int la[N];
int a[N];
ll dp[K][N];
int n, k;
Segtree st(1);

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  memset(dp, INFLL, sizeof dp);
  cin >> n >> k;
  for (int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  st = Segtree(n+10);
  dp[0][0] = 0;
  for (int j=1; j<=k; ++j) {
    memset(la, 0, sizeof la);
    st.clear();
    for (int i=0; i<=n; ++i) {
      st.t[i+st.n] = dp[j-1][i];
    }

    st.pull_all();
    for (int i=j; i<=n; ++i) {
      if (la[a[i]]) {
        st.add(0, la[a[i]], i-la[a[i]]);
      }
      la[a[i]] = i;
      dp[j][i] = st.query(j-1, i);
      //cerr << "  DP " << j << " " << i << " :: " << dp[j][i] << endl;
    }
  }
  cout << dp[k][n] << "\n";

  return 0;
}