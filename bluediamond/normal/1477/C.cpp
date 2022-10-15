#include <bits/stdc++.h>

using namespace std;

#define int long long

struct potus46 {
  int x;
  int y;
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;
  vector<potus46> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
  }

  function<int(potus46, potus46)> dist = [&] (potus46 a, potus46 b) {
    int dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
  };

  function<int(int, int)> distance = [&] (int i, int j) {
    return dist(a[i], a[j]);
  };

  vector<int> ret = {0};
  vector<bool> used(n, 0);
  used[0] = 1;
  for (int step = 1; step < n; step++) {
    int jediMaster = ret.back(), sol = jediMaster;
    for (int j = 0; j < n; j++) {
      if (!used[j] && distance(jediMaster, j) > distance(jediMaster, sol)) {
        sol = j;
      }
    }
    used[sol] = 1;
    ret.push_back(sol);
  }
  for (auto &i : ret) {
    cout << i + 1 << " ";
  }
  cout << "\n";
}