#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  /// o(n ^ 2)
  int t;
  cin >> t;
  while (t--) {
    int n, e = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      e += (a[i] != i);
    }
    function<int()> get = [&] () {
      vector<bool> f(n + 1, 0);
      for (auto &x : a) {
        f[x] = 1;
      }
      int x = 0;
      while (f[x]) {
        x++;
      }
      return x;
    };
    int pos = n - 1;
    vector<int> sol;
    while (e > 0) {
      int x = get();
      if (x == n) {
        while (a[pos] == pos) {
          pos--;
        }
        sol.push_back(pos);
        a[pos] = x;
        continue;
      }
      a[x] = x;
      sol.push_back(x);
      e--;
    }
    cout << (int) sol.size() << "\n";
    for (auto &i : sol) {
      cout << i + 1 << " ";
    }
    cout << "\n";
  }
}