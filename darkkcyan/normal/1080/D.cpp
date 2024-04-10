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

#define maxn 32
unsigned llong n, k;
llong f[maxn];
int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int t; cin >> t;
  f[0] = 0;
  rep1(i, maxn - 1) f[i] = f[i - 1] * 4 + 1;
  while (t--) {
    cin >> n >> k;
    if (n >= maxn) {
      cout << "YES " << n - 1 << '\n';
      continue;
    }
    unsigned llong rq = 0, rem = 0;
    unsigned int lv;
    for (lv = 1; lv <= n; ++lv) {
      unsigned llong addi = (1ull << lv) - 1ull;
      rq += addi;
      rem += ((addi - 1) * 2 + 1) * f[n - lv];
      //clog << lv << ' ' << addi << ' ' << rq << ' ' << rem << endl;
      if (rq > k) break;
      if (rq + rem >= k) {
        break;
      }
    }
    if (rq > k || lv > n) {
      cout << "NO\n";
    } else cout << "YES " << n - lv << '\n';
  }


  return 0;
}