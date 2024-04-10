#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, l;
    cin >> n;
    l = 2 * n + 100;
    vector<int> f(l, 0);
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      f[x]++;
    }
    int ret = 0;
    for (int i = 1; i <= 2 * n + 7; i++) {
      if (f[i]) {
        ret++;
        if (f[i] >= 2) {
          f[i + 1]++;
        }
      }
    }
    cout << ret << "\n";
  }
}