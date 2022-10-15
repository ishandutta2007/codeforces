#include <bits/stdc++.h>

using namespace std;

int get(int x) {
  int foo = 0;
  x /= 5;
  while (x) {
    foo += x;
    x /= 5;
  }
  return foo;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int l = 0, r = (int) 1e9, ans;
  while (l <= r) {
    int m = (l + r) / 2;
    if (get(m) <= n) {
      ans = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  vector<int> res;
  while (get(ans) == n) {
    res.push_back(ans);
    ans--;
  }
  reverse(res.begin(), res.end());
  cout << (int) res.size() << "\n";
  for (auto &x : res) {
    cout << x << " ";
  }
  cout << "\n";
  return 0;
}