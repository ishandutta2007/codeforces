#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


  int t;
  cin >> t;
  while (t--) {
    int n, p = -1, w = (int) 1e9 + 7;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x < w) {
        w = x;
        p = i;
      }
    }
    if (n % 2 == 1 || p % 2 == 1) {
      cout << "Mike\n";
    } else {
      cout << "Joe\n";
    }
  }
}