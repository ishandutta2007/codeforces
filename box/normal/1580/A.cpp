#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using ll = long long;
using pii = pair<int, int>;
//#define int ll
const int MOD = 1000000007;

int psum[405][405];
string r[405];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        psum[i][j] = 0;
    for (int i = 0; i < n; i++)
      cin >> r[i];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        psum[i][j] = (r[i][j] == '1');
        if (j)
          psum[i][j] += psum[i][j - 1];
      }
    int ans = 16;
    for (int i = 0; i < m; i++)
      for (int j = i + 3; j < m; j++)
        for (int k = 0; k < n; k++) {
          int cur = (j - 1 - i) - (psum[k][j - 1] - psum[k][i]);
          for (int l = k + 1; l < n; l++) {
            if (cur >= ans)
              break;
            if (l >= k + 4)
              ans = min(ans, cur + (j - 1 - i) - (psum[l][j - 1] - psum[l][i]));
            cur += (r[l][i] == '0') + (r[l][j] == '0') +
                   (psum[l][j - 1] - psum[l][i]);
          }
        }
    cout << ans << endl;
  }
}