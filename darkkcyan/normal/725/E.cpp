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

#define maxn 201010
int n, c;
int a[maxn], maxcoin[maxn], cnt[maxn];

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> c >> n;
  rep(i, n) {
    cin >> a[i];
    maxcoin[a[i]] = a[i];
    ++cnt[a[i]];
  }
  rep(i, maxn - 1) maxcoin[i + 1] = max(maxcoin[i + 1], maxcoin[i]);
  for (int ans = 1; ans < c; ++ans) {
    int s = c, lastmx = c;
    bool ansPicked = false;
    while (s) {
      int mx = min(maxcoin[s], maxcoin[lastmx]);
      if (mx == 0) break;
      //clog << s << endl;
      if (mx < ans and ans <= s and !ansPicked) {
        s -= ans;
        ansPicked =true;
        lastmx = ans - 1;
        //clog << ans << ' ' << "pick ans" << endl;
        continue;
      }

      int npickcoin = min(cnt[mx], s / mx);
      s -= npickcoin* mx;
      //clog << ans << ' ' << mx << ' ' << npickcoin << endl;
      lastmx = mx - 1;
    }
    if (s == 0) continue;
    cout << ans;
    return 0;
  }

  cout << "Greed is good";

  return 0;
}