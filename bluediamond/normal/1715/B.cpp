#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE


  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int n, k, b, s;
    cin >> n >> k >> b >> s;
    b *= k;
    if (b <= s && s <= b + n * (k - 1)) {
      vector<int> a(n, 0);
      s -= b;
      assert(s >= 0);
      a[0] = b;
      for (int i = 0; i < n; i++) {
        int grow = min(k - 1, s);
        a[i] += grow;
        s -= grow;
        cout << a[i] << " ";
      }
      assert(s == 0);
      cout << "\n";
      continue;
    }
    cout << "-1\n";
  }
  return 0;
}
/**
**/