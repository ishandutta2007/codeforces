#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;

const int N = 2000 + 7;
const int INF = (int) 1e18;
int n, a[N], mx[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  /// freopen ("input", "r", stdin);

  for (int i = 0; i < N; i++) {
    mx[i] = -INF;
  }
  mx[0] = 0;

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = n; j >= 1; j--) {
      if (mx[j - 1] + a[i] >= 0)
      mx[j] = max(mx[j], mx[j - 1] + a[i]);
    }
  }
  int sol = 0;
  for (int i = 1; i <= n; i++) {
    if (mx[i] >= 0) {
      sol = i;
    }
  }
  cout << sol << "\n";
  return 0;
}