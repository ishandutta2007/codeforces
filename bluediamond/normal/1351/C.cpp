#include <bits/stdc++.h>

using namespace std;



int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    string st;
    int sol = 0;
    cin >> st;
    set<pair<pair<int, int>, pair<int, int>>> s;
    s.insert({{0, 0}, {0, 0}});
    pair<int, int> it = {0, 0};
    for (auto &x : st) {
      auto it2 = it;
      if (x == 'N') it.first--;
      if (x == 'S') it.first++;
      if (x == 'E') it.second++;
      if (x == 'W') it.second--;
      pair<pair<int, int>, pair<int, int>> lol = {min(it, it2), max(it, it2)};
      if (s.count(lol)) {
        sol++;
      } else {
        sol += 5;
        s.insert(lol);
      }
    }
    cout << sol << "\n";
  }
  return 0;
}