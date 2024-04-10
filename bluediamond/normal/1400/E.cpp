#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> v, int lim) {
  if (v.empty()) {
    return 0;
  }
  int n = (int) v.size(), mn = *min_element(v.begin(), v.end());
  if (mn > lim) {
    return min(n, lim);
  }
  vector<int> a, b;
  bool found = 0;
  for (auto &x : v) {
    if (found == 0 && mn == x) {
      found = 1;
      continue;
    }
    if (found == 0) {
      a.push_back(x - mn);
    } else {
      b.push_back(x - mn);
    }
  }
  mn += solve(a, n - mn);
  mn += solve(b, n - mn);
  return min(n, mn);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << solve(a, n) << "\n";
  return 0;
}