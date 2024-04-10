#include <bits/stdc++.h>
using namespace std;

#define cli clog << "\"" << __PRETTY_FUNCTION__ << "\"@" << __LINE__ << ": "
#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
template<class x> vector<typename x::value_type> tovec(const x& a) { return vector<typename x::value_type>(a.begin(), a.end()); }
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> tovec(u a, u b) { return vector<ptrtype(u)>(a, b); }
template<typename x> ostream& operator<<(ostream& cout, const vector<x>& a) {
  cout << "[";
  if (len(a)) cout << a[0];
  rep1(i, len(a) - 1) cout << ", " << a[i];
  return cout << "]";
}
template<typename u, typename v> ostream& operator<<(ostream& cout, const pair<u, v>& a) {
  return cout << "(" << a.xx << ", " << a.yy << ")";
}

#define rem ((llong)1e9+7)
struct mat: public vector<vector<llong>> {
  int r() const { return (int)size(); }
  int c() const { return len(at(0)); }
  void make(int n, int m) {
    assign(n, vector<llong>(m));
  }

  void iden(int n) {
    make(n, n);
    rep(i, n) at(i)[i] = 1;
  }

  mat mul(const mat& o) {
    assert(c() == o.r());
    mat ans; ans.make(r(), o.c());
    rep(i, r()) rep(f, c()) rep(g, o.c())
      (ans[i][g] += at(i)[f] * o[f][g] % rem) %= rem;
    return ans;
  }
};

mat powMat(mat base, llong m) {
  assert(base.c() == base.r());
  mat ans; ans.iden(base.r());
  for (; m > 0; m >>= 1) {
    if (m & 1) ans = ans.mul(base);
    base = base.mul(base);
  }
  return ans;
}

ostream& operator<<(ostream& cout, const mat& a) {
  for (auto i: a) cout << i << endl;
  return cout;
}

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  llong n, m; cin >> n >> m;
  if (n < m) {
    cout << 1;
    return 0;
  }

  mat co; co.make((int)m, (int)m);
  co[0][0] = 1;
  co[0][m - 1] = 1;
  rep1(i, m - 1) co[i][i - 1] = 1;

  //clog << co << endl;
  
  mat nc = powMat(co, n - m + 1);
  //clog << nc << endl;
  mat a; a.make((int)m, 1);
  rep(i, m) a[i][0] = 1;
  mat ans = nc.mul(a);
  //clog << a << endl;
  //clog << ans << endl;
  cout << ans[0][0];

  return 0;
}