#include <bits/stdc++.h>

using namespace std;


signed main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &x : v) {
    cin >> x;
  }
  sort(v.begin(), v.end());
  for (auto &x : v) {
    cout << x << " ";
  }
  cout << "\n";
  return 0;
}