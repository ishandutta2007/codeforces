/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2015.03.21
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

typedef pair <int, int> pii;

int main() {
  int n, k, q;
  cin >> n >> k;
  int a[n];
  forn(i, n)
    cin >> a[i];
  cin >> q;

  vector<pii> p;
  forn(i, n)
    forn(j, k + 1)
      p.push_back(pii(a[i] * j, j));
  sort(all(p));
  forn(i, q) {
    int x, ans = k + 1;
    cin >> x;
    forn(i, n)
      forn(j, k + 1) 
        if (x >= a[i] * j) {
          int rest = x - a[i] * j;
          auto it = lower_bound(all(p), pii(rest, 0));
          if (it != p.end() && it->first == rest)
            ans = min(ans, j + it->second);
        }
    printf("%d\n", ans > k ? -1 : ans);
  }
  return 0;
}