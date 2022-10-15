#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int get_dist1(int r1, int c1, int r2, int c2) {
  return abs(r1 - r2) + abs(c1 - c2);
}

int get_dist2(int r1, int c1, int r2, int c2) {
  {
    int r, c;
    r = r1 + c1;
    c = r1 - c1;

    r1 = r;
    c1 = c;
  }

  {
    int r, c;
    r = r2 + c2;
    c = r2 - c2;

    r2 = r;
    c2 = c;
  }
  return max(abs(r1 - r2), abs(c1 - c2));
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

  int Tests;
  cin >> Tests;
  for (int tc = 1; tc <= Tests; tc++) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int> (m, 0));
    vector<pair<int, int>> all, check;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      assert((int) s.size() == m);
      for (int j = 0; j < m; j++) {
        char ch = s[j];
        assert(ch == 'W' || ch == 'B');
        v[i][j] = (ch == 'B');
        all.push_back({i + j, i - j});
        if (v[i][j] == 1) {
          check.push_back({i + j, i - j});
          assert(!all.empty());
          assert(!check.empty());
          assert(all.back() == check.back());
        }
      }
    }
    assert(!check.empty());
    vector<int> xs, ys;
    for (auto &it : check) {
      xs.push_back(it.first);
      ys.push_back(it.second);
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    int the_sol = (int) 1e9 + 7, rr = -1, cc = -1;
    for (auto &it : all) {
      int big = 0, estim = 0;

      estim = max(estim, abs(it.first - xs[0]));
      estim = max(estim, abs(it.first - xs.back()));

      estim = max(estim, abs(it.second - ys[0]));
      estim = max(estim, abs(it.second - ys.back()));
      big = estim;

      if (big < the_sol) {
        the_sol = big;
        rr = it.first + it.second;
        cc = it.first - it.second;
      }
    }
    cout << rr / 2 + 1 << " " << cc / 2 + 1 << "\n";
  }
}