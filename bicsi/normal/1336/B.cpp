#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    
    vector<vector<int>> v;
    auto read = [&](int n) {
      vector<int> ret(n);
      for (auto& x : ret)
        cin >> x;
      return ret;
    };
    v.push_back(read(n1));
    v.push_back(read(n2));
    v.push_back(read(n3));
    
    for (int i = 0; i < 3; ++i)
      sort(v[i].begin(), v[i].end());

    int at[3] = {0, 0, 0};
    long long best = 5e18;

    while (true) {
      for (int i0 = at[0] - 1; i0 <= at[0] + 1; ++i0) {
        if (i0 < 0 || i0 >= v[0].size()) continue;
        for (int i1 = at[1] - 1; i1 <= at[1] + 1; ++i1) {
          if (i1 < 0 || i1 >= v[1].size()) continue;
          for (int i2 = at[2] - 1; i2 <= at[2] + 1; ++i2) {
            if (i2 < 0 || i2 >= v[2].size()) continue;

            
            long long a = v[0][i0], b = v[1][i1], c = v[2][i2];
            long long now = (a - b) * (a - b) + (a - c) * (a - c) + (b - c) * (b - c);
            best = min(best, now);
          }
        }
      } 

      
      int adv = -1;
      int minv = 2e9;

      for (int i = 0; i < 3; ++i) {
        if (at[i] == v[i].size() - 1) continue;
        if (minv > v[i][at[i] + 1]) {
          minv = v[i][at[i] + 1];
          adv = i;
        }
      }

      if (adv == -1) break;
      at[adv] += 1;
    }

    cout << best << '\n';
  }

  return 0;
}