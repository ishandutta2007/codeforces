/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forab(i, a, b) for (int i = (a); i <= (b); i++)

typedef long long ll;

set<int> s;

void fact( int x ) {
  for (int i = 2; i * i <= x; i++) 
    if (x % i == 0) {
      s.insert(i);
      while (x % i == 0)
        x /= i;
    }
  if (x > 1)
    s.insert(x);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  int x[n], c[n];
  forn(i, n)
    cin >> x[i];
  ll res = (ll)(n - 1) * a;
  forab(t, -1, 1) 
    fact(x[0] + t), fact(x[n - 1] + t);
  for (int g : s) {
    int l = n, r = 0;
    forn(i, n) {
      int rest = x[i] % g;
      c[i] = (rest != 0);
      if (rest != 0 && rest != 1 && rest != g - 1) {
        l = min(l, i);
        r = max(r, i);
      }
    }
    int cnt = 0;
    forn(i, n)
      cnt += c[i] && !(l <= i && i <= r);
    ll sum = (ll)cnt * b;
    if (r >= l)
      sum += (ll)(r - l + 1) * a;
    if (a < b) {
      #define X(i) (a - (c[i] ? b : 0))
      if (l <= r) {
        ll add = 0, min_add = 0;
        for (int i = l - 1; i >= 0; i--) {
          add += X(i);
          min_add = min(min_add, add);
        }
        sum += min_add, add = 0, min_add = 0;
        for (int i = r + 1; i < n; i++) {
          add += X(i);
          min_add = min(min_add, add);
        }
        sum += min_add;
      } else {
        ll pref = 0, max_pref = 0, min_sum = 0;
        forn(i, n) {
          pref += X(i);
          min_sum = min(min_sum, pref - max_pref);
          max_pref = max(max_pref, pref);
        }          
        sum += min_sum;
      }
    }
    //printf("g = %d, [%d..%d] -> %lld\n", g, l, r, sum);
    res = min(res, sum);
  }
  cout << res << endl;
  return 0;
}