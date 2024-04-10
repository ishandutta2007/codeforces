#include <bits/stdc++.h>
using namespace std;

#define maxn 601010
int n;
int x[maxn];
int v[maxn];

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = n; i--; ) cin >> x[i];
  for (int i = n; i--; ) cin >> v[i];

  long double l = 0, r = 3e9;
  for (int cnt = 100;cnt --; ) {
    long double mid = (l + r) / 2;
    long double rl = x[n - 1] - v[n - 1] * mid, rr = x[n - 1] + v[n - 1] * mid;
    bool ok = 1;
    for (int i = n - 1; i--; ) {
      long double tl = x[i] - v[i] * mid;
      long double tr = x[i] + v[i] * mid;
      if (tl > rr or rl > tr) {
        ok = 0;
        break;
      }
      rl = max(rl, tl);
      rr = min(rr, tr);
    }
    if (ok) r = mid;
    else l = mid;
  }
  cout << fixed << setprecision(10) << l;
  return 0;
}