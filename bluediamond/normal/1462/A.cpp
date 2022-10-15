#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, l, r;
    cin >> n;
    l = 0, r = n - 1;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
    }
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        cout << a[l++] << " ";
      } else {
        cout << a[r--] << " ";
      }
    }
    cout << "\n";
  }
}