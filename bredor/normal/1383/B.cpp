#include <bits/stdc++.h>
using namespace std;
int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int x = 0;

    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      x ^= a[i];
    }

    if (x == 0) {
      cout << "DRAW\n";
      continue;
    }

    for (int i = 30; i >= 0; --i) {
      int cnt = 0;
      for (int y : a) if ((y >> i) & 1) ++cnt;
      if (cnt % 2 != 0) {
        int x = cnt;
        int y = n - cnt;
        //cerr << x << " " << y << endl;
        bool win = true;
        if (x % 4 == 1) win = true;
        else win = y % 2 == 1;
        if (win) cout << "WIN\n";
        else cout << "LOSE\n";
        break;
      }
    }
    //int cnt = 0;
    //for (int y : a) {
    //  if ((y ^ x) < y)
    //    ++cnt;
    //}
    //if (cnt == 1) {
    //  cout << "WIN\n";
    //} else if (cnt == 3) {
    //  cout << ((n - cnt) % 2 == 1 ? "WIN\n" : "LOSE\n");
    //} else {
    //  cout << ((n - cnt) % 2 == 0 ? "WIN\n" : "LOSE\n");
    //}
  }

}