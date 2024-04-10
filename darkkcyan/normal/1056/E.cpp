#include <bits/stdc++.h>
using namespace std;

#define llong long long /*{{{*/
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
}/*}}}*/

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

string s, t;

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> s >> t;
  hs ht(t);
  int c0 = 0, c1 = 0;
  int f0 = len(s), f1 = len(s);
  rep(i, len(s)) {
    if (s[i] == '0') {
      c0++;
      f0 = min(f0, i);
    } else {
      c1++;
      f1 = min(f1, i);
    }
  }
  int ans = 0;
  rep1(i, len(t) - 1) {
    if (i * c0 > len(t)) break;
    int f = len(t) - i * c0;
    if (f == 0) break;
    if (f % c1) continue;
    f /= c1;
    int p0 = f0 * f, p1 = f1 * i;
    ull h0 = ht.get(p0, p0 + i - 1);
    ull h1 = ht.get(p1, p1 + f - 1);
    if (h0 == h1) continue;
    ull nhs = {0, 0};
    for (auto c: s) {
      if (c == '0') nhs = nhs * p29(i) + h0;
      else nhs = nhs * p29(f) + h1;
    }
    if (nhs == ht.dat.back()) ++ans;
  }
  cout << ans;


  return 0;
}