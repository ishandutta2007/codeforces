#include <bits/stdc++.h>
#define int long long 

using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n; cin >> n;
  vector<int> v(n), coef(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    coef[i] = (i % 2 == 0 ? +1 : -1);
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int sum = 0, minsum = 0;
    for (int j = i + 1; j < n; ++j) {
      if (coef[i] == 1 && coef[j] == -1) {
        int cnt;
        if (sum < 0) {
          // iau cu sum mai mult in i decat in j
          int reqi = -sum + 1, reqj = 1;
          if (reqi < -minsum) {
            int delta = -minsum - reqi;
            assert(delta > 0);
            reqi += delta;
            reqj += delta;
            assert(reqi == -minsum);
          }
          cnt = min(v[i] - reqi + 1, v[j] - reqj + 1);
        } else {
          // iau cu -sum mai mult in j decat in i
          int reqi = 1;
          int reqj = 1 + sum;
          if (reqi < -minsum) {
            int delta = -minsum - reqi;
            assert(delta > 0);
            reqi += delta;
            reqj += delta;
            assert(reqi == -minsum);
          }
          cnt = min(v[i] - reqi + 1, v[j] - reqj + 1);
        }
        // cerr << "i=" << i << " j=" << j << " cnt=" << cnt << " sum=" << sum << " minsum=" << minsum << endl;
        if (cnt > 0) 
          ans += cnt;
      }
      sum += v[j] * coef[j];
      minsum = min(minsum, sum);
    }
  }
  cout << ans << '\n';

  return 0;
}