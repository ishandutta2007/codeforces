#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 100100;
const int RT = 320;

struct MEX {
  int amt[N*2];
  int of[N*2];
  MEX() {
    of[0] = N*2;
  }
  void insert(int x) {
    //cerr << " +" << x << endl;
    --of[amt[x]];
    ++amt[x];
    ++of[amt[x]];
  }
  void remove(int x) {
    //cerr << " -" << x << endl;
    --of[amt[x]];
    --amt[x];
    ++of[amt[x]];
  }
  int query() {
    for (int i=0; i<RT*2; ++i) {
      if (!of[i]) {
        return i;
      }
    }
    assert(false);
  }
};

MEX mex;
int a[N];
tuple<int, int, int> q2[N];

const int P = 2156;

struct Query {
  int t, l, r, id;
  int tg, lg;
  int sgn=1;
  Query(int a=0, int b=0, int c=0, int d=0) : t(a), l(b), r(c), id(d), tg(t/P), lg(l/P) {}
  bool operator< (const Query& o) const {
    if (tg == o.tg) {
      return (lg == o.lg ? sgn*r < o.sgn*o.r : lg < o.lg);
    }
    return tg < o.tg;
  }
};
map<pair<int, int>, int> st;
int ans[N];
Query queries[N];
int n, q;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tt = 0;
  cin >> n >> q;
  unordered_map<int, int> mp;
  for (int i=1; i<=n; ++i) {
    cin >> a[i];
    mp[a[i]] = -1;
  }
  int m = 0;
  for (int i=1; i<=q; ++i) {
    int type;
    cin >> type;
    if (type == 1) {
      int l, r;
      cin >> l >> r;
      queries[m] = Query(tt, l, r, m);
      st[{queries[m].tg, queries[m].lg}] = -1;
      ++m;
    } else {
      ++tt;
      int p, x;
      cin >> p >> x;
      mp[x] = -1;
      q2[tt] = {p, x, a[p]};
      a[p] = x;
      //cerr << " :: " << tt << endl;
    }
  }
  int qq = 0;
  for (auto& p : st) {
    p.second = qq;
  }
  for (int i=0; i<m; ++i) {
    if (st[{queries[m].tg, queries[m].lg}]%2) {
      queries[m].sgn = -1;
    }
  }
  for (int i=tt; i>=1; --i) {
    auto [p, x, ax] = q2[i];
    a[p] = ax;
  }
  sort(queries, queries+m);

  int zz=0;
  for (auto& p : mp) {
    p.second = ++zz;
  }
  for (int i=1; i<=n; ++i) {
    a[i] = mp[a[i]];
  }
  for (int i=1; i<=tt; ++i) {
    auto [p, x, ax] = q2[i];
    q2[i] = {p, mp[x], mp[ax]};
    //cerr << " :: " << x << " " << ax << endl;
  }

  int curt = 0, curl = 1, curr = 1;
  mex.insert(a[1]);
  for (int i=0; i<m; ++i) {
    auto [t, l, r, id, lb, rb, _sgn] = queries[i];
    while (curt < t) {
      ++curt;
      auto [p, x, ax] = q2[curt];
      a[p] = x;
      if (curl <= p && p <= curr) {
        mex.remove(ax);
        mex.insert(x);
      }
    }
    while (curt > t) {
      auto [p, x, ax] = q2[curt];
      a[p] = ax;
      if (curl <= p && p <= curr) {
        mex.insert(ax);
        mex.remove(x);
      }
      --curt;
    }
    while (curl > l) {
      --curl;
      mex.insert(a[curl]);
    }
    while (curr < r) {
      ++curr;
      mex.insert(a[curr]);
    }
    while (curl < l) {
      mex.remove(a[curl]);
      ++curl;
    }
    while (curr > r) {
      mex.remove(a[curr]);
      --curr;
    }
    ans[id] = mex.query();
  }

  for (int i=0; i<m; ++i) {
    cout << ans[i] << "\n";
  }
  return 0;
}