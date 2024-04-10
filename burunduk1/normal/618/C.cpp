/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef pair <int, int> pii;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  pair<pii, int> p[n];
  forn(i, n) {
    cin >> p[i].first.first, cin >> p[i].first.second;
    p[i].second = i + 1;
  }
  sort(p, p + n);
  forn(i, n - 2) {
    ll x1 = p[i + 0].first.first, y1 = p[i + 0].first.second;
    ll x2 = p[i + 1].first.first, y2 = p[i + 1].first.second;
    ll x3 = p[i + 2].first.first, y3 = p[i + 2].first.second;
    if ((x3 - x1) * (y2 - y1) - (x2 - x1) * (y3 - y1) != 0) {
      printf("%d %d %d\n", p[i].second, p[i + 1].second, p[i + 2].second);
      return 0;
    }
  }
  return 0;
}