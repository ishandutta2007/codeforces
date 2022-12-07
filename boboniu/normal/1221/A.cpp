#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      v.push_back(x);
    }
    int ans = 2048;
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < n; i++) {
      if (ans >= v[i]) ans -= v[i];
    }

    if (ans) {
      cout << "No" << "\n";
    } else {
      cout << "Yes" << "\n";
    }
  }
  return 0;
}