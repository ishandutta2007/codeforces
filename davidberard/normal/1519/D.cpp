#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 5050;

ll a[N];
ll b[N];
ll pre[N];
//ll conv[N*2][N]; // a is still; b rev and shifted [boffset+N][a idx]
ll co[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  for (int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  for (int i=1; i<=n; ++i) {
    cin >> b[i];
    pre[i] = pre[i-1] + a[i]*b[i];
  }
  /*
  for (int i=-n; i<=n; ++i) {
    for (int j=1; j<=n; ++j) {
      int bidx = n-(j-i)+1;
      ll bv = 0;
      if (bidx >= 1 && bidx <= n) {
        bv = b[bidx];
      }
      conv[i+N][j] = conv[i+N][j-1] + a[j]*bv;
    }
  }
  */

  ll ans = -1e18;
  for (int boff=-n+1; boff <=n-1; ++boff) {
    co[0] = 0;
    for (int i=1; i<=n; ++i) {
      ll bv = 0;
      int bidx = n-(i-boff)+1;
      if (bidx >= 1 && bidx <= n) {
        bv = b[bidx];
      }
      co[i] = co[i-1] + a[i]*bv;
    }
    for (int i=0; i<=n; ++i) {
      int j = boff - i + 1 + n;
      if (j < 1 || j > n+1 || j <= i) {
        continue;
      }
      ll cur = 0;
      int offidx = i-(n-(j-1));
      cur += pre[i];
      cur += pre[n]-pre[j-1];
      cur += co[j-1] - co[i];
      //cerr << " pre " << pre[i] << " suf " << pre[n]-pre[j-1] << " mid " << co[j-1] - co[i] << endl;
      ans = max(ans, cur);
    }
  }
  cout << ans << "\n";
  return 0;
}