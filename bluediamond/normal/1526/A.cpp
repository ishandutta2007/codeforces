#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;

const int N = 100 + 7;
int n, a[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  /// freopen ("input", "r", stdin);


  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    n *= 2;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 1, r = n;
    for (int i = 1; i <= n; i++) {
      if (i & 1) cout << a[l++] << " ";
      else cout << a[r--] << " ";
    }
    cout << "\n";
  }

  return 0;
}