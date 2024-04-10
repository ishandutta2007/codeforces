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

#ifndef llong/*{{{*/
#define llong long long 
#endif
#define rem ((llong)1e9+7)
#define ull pair<unsigned llong, llong>
ull operator + (ull a, const ull& b) {
  a.xx += b.xx;
  (a.yy += b.yy) %= rem;
  return a;
}
ull operator + (ull a, const llong x) {
  a.xx += x;
  (a.yy += x) %= rem;
  return a;
}
ull operator - (ull a, const ull& b) {
  a.xx -= b.xx;
  (a.yy -= b.yy) %= rem;
  if (a.yy < 0) a.yy += rem;
  return a;
}
ull operator* (ull a, const ull& b) {
  a.xx *= b.xx;
  (a.yy *= b.yy) %= rem;
  return a;
}
ull operator * (ull a, const llong x) {
  a.xx *= x;
  (a.yy *= x) %= rem;
  return a;
}
vector<ull> p29d(1, {1, 1});
ull p29(int i) {
  while ((int)p29d.size() <= i)
    p29d.push_back(p29d.back() * 29);
  return p29d[i];
}
struct hs {
  vector<ull> dat;
  hs(const string& s) : dat(1, {0, 0}) {
    for (auto ch: s) {
      dat.push_back(dat.back() * 29 + (llong)(ch - 'a' + 1));
    }
  }
  ull get(int l, int r) {
    return dat[r + 1] - dat[l] * p29(r - l + 1);
  }
};/*}}}*/

string s;

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> s;
  int n = len(s);
  bool ok = 0;
  rep(i, n - 1) if (s[i] != s[i + 1]) {
    ok = 1;
    break;
  }
  if (!ok) {
    cout << "Impossible";
    return 0;
  }
  hs h(s + s);

  rep1(i, n - 1) {
    if (h.get(i, i + n - 1) == h.get(2 * n - n - i, 2 * n - i - 1) and h.get(i, i + n - 1) != h.get(0, n - 1)) {
      cout << 1;
      //clog << i << endl;
      return 0;
    }
  }

  rep(i, n / 2) {
    if (h.get(0, i) != h.get(n - i - 1, n - 1)) {
      cout << 2;
      return 0;
    }
  }
  cout << "Impossible";

  return 0;
}