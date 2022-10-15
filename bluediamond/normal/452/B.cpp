#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

ld eval(vector<pair<int, int>> v) {
  ld sol = 0;
  for (int i = 1; i < (int) v.size(); i++) {
    ld dx = v[i].first - v[i - 1].first;
    ld dy = v[i].second - v[i - 1].second;
    sol += sqrt(dx * dx + dy * dy);
  }
  return sol;
}

signed main() {
  int n, m;
  cin >> n >> m;
  set<pair<int, int>> s;

  function<void(int, int)> ins = [&] (int x, int y) {
    if (0 <= x && x <= n && 0 <= y && y <= m) {
      s.insert({x, y});
    }
  };

  for (int i = 0; i <= 3; i++) {
    for (int j = 0; j <= 3; j++) {
      ins(i, j);
      ins(n - i, m - j);
    }
  }


  vector<pair<int, int>> v;
  for (auto &it : s) {
    v.push_back(it);
  }

  vector<pair<int, int>> sol;

  for (int a = 0; a < (int) v.size(); a++)
  for (int b = 0; b < (int) v.size(); b++)
  for (int c = 0; c < (int) v.size(); c++)
  for (int d = 0; d < (int) v.size(); d++)
  {
    if (a == b || a == c || a == d || b == c || b == d || c == d) continue;
    vector<pair<int, int>> cur = {v[a], v[b], v[c], v[d]};
    if (eval(cur) > eval(sol)) sol = cur;
  }

  for (auto &it : sol) {
    cout << it.first << " " << it.second << "\n";
  }



  return 0;
}
/**



**/