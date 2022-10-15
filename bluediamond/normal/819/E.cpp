#include <bits/stdc++.h>

using namespace std;

const int N = 300 + 7;
int n;
vector<vector<int>> sol;

void solve(int n) {
  assert(n >= 3);
  if (n == 3) {
    sol.push_back({1, 2, 3});
    sol.push_back({1, 2, 3});
    return;
  }
  if (n == 4) {
    sol.push_back({1, 2, 3});
    sol.push_back({1, 2, 4});
    sol.push_back({2, 3, 4});
    sol.push_back({1, 3, 4});
    return;
  }
  assert(n >= 5);
  vector<vector<int>> c;
  for (int i = 1; i <= n - 2; i++) {
    c.push_back({n, i, n - 1});
  }
  c.push_back({n, n - 1});
  for (int j = 0; j < (int) c.size(); j++) {
    vector<int> a = c[j], b = c[(j + 1) % (int) c.size()];
    for (int k = (int) b.size() - 2; k > 0; k--) {
      a.push_back(b[k]);
    }
    sol.push_back(a);
  }
  solve(n - 2);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  solve(n);


  cout << (int) sol.size() << "\n";
  for (auto &v : sol) {
    cout << (int) v.size() << " ";
    for (auto &x : v) {
      cout << x << " ";
    }
    cout << "\n";
  }
  return 0;
}