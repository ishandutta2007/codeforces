#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool home = 1;
#define int ll


const int N = (int) 1e5 + 7;
const int K = 500;
const int INF = (int) 1e18;
int n, a[N], mxsum[N][K], pre[N], sol;

int sum(int l, int r) {
  return pre[r] - pre[l - 1];
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("input", "r", stdin);
  }

  for (int i = 0; i < N; i++) for (int j = 0; j < K; j++) mxsum[i][j] = -INF;


  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    reverse(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    sol = 0;

    for (int i = 1; i <= n; i++) {
      mxsum[i][1] = sum(i, i);

      for (int k = 2; k < K; k++) {
        if (i < k) continue;
        /// i >= k
        int cur = sum(i - k + 1, i);
        if (cur < mxsum[i - k][k - 1]) {
          mxsum[i][k] = max(mxsum[i][k], cur);
        }
      }
      for (int j = 1; j < K; j++) {
        mxsum[i][j] = max(mxsum[i][j], mxsum[i - 1][j]);
        if (mxsum[i][j] > 0) sol = j;
      }
    }
    cout << sol << "\n";
    for (int i = 1; i <= n; i++) for (int j = 0; j < K; j++) mxsum[i][j] = -INF;
  }
  return 0;
}
/**



**/