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

#define maxa ((llong)1e18)

vector<llong> fib;
void calfib() {
  fib.push_back(1);
  fib.push_back(2);
  while (fib.back() <= maxa) fib.push_back(fib.back() + fib[len(fib) - 2]);
}

llong dp[90][2];
vector<llong> s;

llong cal(int i, bool keep) {
  if (i == len(s) - 1) return keep;
  if (dp[i][keep] != -1) return dp[i][keep];
  if (keep) dp[i][keep] = cal(i + 1, 0) + cal(i + 1, 1);
  else dp[i][keep] = cal(i + 1, 1) * ((s[i] - s[i + 1] - 1) / 2) + cal(i + 1, 0) * ((s[i] - s[i + 1]) / 2);
  return dp[i][keep];
}

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  calfib();
  int n; cin >> n;
  while (n--) {
    llong a; cin >> a;
    s.clear();
    for (int i = len(fib); i--; ) {
      if (a >= fib[i]) {
        s.push_back(i);
        a -= fib[i];
      }
    }
    memset(dp, -1, sizeof(dp));
    s.push_back(-1);
    //clog << s << endl;
    cout << cal(0, 0) + cal(0, 1) << '\n';
    //rep(i, len(s)) clog << i << ' ' << tovec(dp[i], dp[i] + 2) << endl;
  }


  return 0;
}