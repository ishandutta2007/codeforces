#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;

const int N = (int) 5e5 + 7;
int n, a[N], pre_ones[N];
string s;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
      char ch = s[i - 1];
      if (ch == 'D') a[i] = 1;
      else a[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      pre_ones[i] = pre_ones[i - 1] + (a[i] == 1);
    }
    map<pair<int, int>, int> f;
    for (int i = 1; i <= n; i++) {
      int x = pre_ones[i], y = i - x;
      int g = __gcd(x, y);
      assert(g > 0);
      x /= g;
      y /= g;
      cout << ++f[{x, y}] << " ";
    }
    cout << "\n";
  }

  return 0;
}