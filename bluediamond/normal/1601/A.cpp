#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
///#define int ll

const int N = (int) 2e5 + 7;
int n, a[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);


  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<int> f;
    for (int bit = 0; bit <= 30; bit++) {
      int cnt = 0;
      for (int i = 1; i <= n; i++) {
        if (a[i] & (1 << bit)) cnt++;
      }
      if (cnt == 0) continue;
      f.push_back(cnt);
    }

    vector<int> sol;
    for (int k = 1; k <= n; k++) {
      bool good = 1;
      for (auto &i : f) {
        if (i % k) good = 0;
      }
      if (good) sol.push_back(k);
    }
    for (auto &x : sol) {
      cout << x << " ";
    }
    cout << "\n";

  }

  return 0;
}
/**



**/