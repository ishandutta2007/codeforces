/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2015.03.21
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

int main() {
  int n;
  cin >> n;
  int h[n], w[n];
  forn(i, n)
    cin >> w[i] >> h[i];

  int M = max(*max_element(w, w + n), *max_element(h, h + n));
  assert(M <= 1000 && n <= 1000);
  int ans = M * M * n;
  vector<int> diff;
  for (int H = 1; H <= M; H++) {
    diff.clear();
    int cnt = 0, bad = 0, sumW = 0;
    forn(i, n)
      if (h[i] > H && w[i] > H)
        bad = 1;
      else if (h[i] >= w[i])
        if (h[i] > H)
          sumW += h[i], cnt++;
        else
          sumW += w[i];
      else {
        sumW += w[i];
        if (w[i] <= H)
          diff.pb(h[i] - w[i]);
      }
    sort(all(diff));
    if (cnt <= n / 2 && !bad) 
      ans = min(ans, H * (sumW + accumulate(diff.begin(), diff.begin() + min(sz(diff), n / 2 - cnt), 0)));
  }
  cout << ans << endl;
  return 0;
}