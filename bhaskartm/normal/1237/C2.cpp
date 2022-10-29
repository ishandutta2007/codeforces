#include <bits/stdc++.h>

using namespace std;

const int D = 3;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> p(n, vector<int>(D));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < D; j++) {
      cin >> p[i][j];
    }
  }
  auto Solve = [&](auto& Self, vector<int> ids, int k) {
    if (k == D) {
      return ids[0];
    }
    map<int, vector<int>> mp;
    for (int x : ids) {
      mp[p[x][k]].push_back(x);
    }
    vector<int> a;
    for (auto& q : mp) {
      int cur = Self(Self, q.second, k + 1);
      if (cur != -1) {
        a.push_back(cur);
      }
    }
    for (int i = 0; i + 1 < (int) a.size(); i += 2) {
      cout << a[i] + 1 << " " << a[i + 1] + 1 << '\n';
    }
    return (a.size() % 2 == 1 ? a.back() : -1);
  };
  vector<int> t(n);
  iota(t.begin(), t.end(), 0);
  Solve(Solve, t, 0);
  return 0;
}