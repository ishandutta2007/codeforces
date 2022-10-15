#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 500 + 7;
int n;
int m;
int a[N][N];
vector<vector<int>> sol;

void op(int r1, int c1, int r2, int c2, int r3, int c3) {
  a[r1][c1] ^= 1;
  a[r2][c2] ^= 1;
  a[r3][c3] ^= 1;
  int rmin = min(r1, min(r2, r3));
  int cmin = min(c1, min(c2, c3));

  int rmax = max(r1, max(r2, r3));
  int cmax = max(c1, max(c2, c3));

  assert(rmin == rmax - 1 && cmin == cmax - 1);
  sol.push_back({r1, c1, r2, c2, r3, c3});
}

void solve() {
  vector<pair<int, int>> ones, nup;
  for (int i = 1; i <= 2; i++) {
    for (int j = 1; j <= 2; j++) {
      if (a[i][j] == 1) {
        ones.push_back({i, j});
      } else {
        nup.push_back({i, j});
      }
    }
  }
  if ((int) ones.size() == 0) {
    return;
  }
  if ((int) ones.size() == 1) {
    op(ones[0].first, ones[0].second, nup[0].first, nup[0].second, nup[1].first, nup[1].second);
    solve();
    return;
  }
  if ((int) ones.size() == 2) {
    op(ones[0].first, ones[0].second, nup[0].first, nup[0].second, nup[1].first, nup[1].second);
    solve();
    return;
  }
  if ((int) ones.size() == 3) {
    op(ones[0].first, ones[0].second, ones[1].first, ones[1].second, ones[2].first, ones[2].second);
    return;
  }
  if ((int) ones.size() == 4) {
    op(ones[0].first, ones[0].second, ones[1].first, ones[1].second, ones[2].first, ones[2].second);
    solve();
    return;
  }
  assert(0);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ///freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    sol.clear();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      string s;
      cin >> s;
      for (int j = 1; j <= m; j++) {
        a[i][j] = s[j - 1] - '0';
      }
    }
    for (int i = n; i >= 3; i--) {
      for (int j = 1; j < m; j++) {
        if (a[i][j] && a[i][j + 1]) {
          if (a[i - 1][j]) {
            op(i, j, i, j + 1, i - 1, j);
            continue;
          }
          if (a[i - 1][j + 1]) {
            op(i, j, i, j + 1, i - 1, j + 1);
            continue;
          }
        }
      }
      for (int j = 1; j <= m; j++) {
        if (a[i][j]) {
          if (j == 1) {
            op(i, j, i - 1, j, i - 1, j + 1);
          } else {
            op(i, j, i - 1, j, i - 1, j - 1);
          }
        }
      }
    }
    for (int j = m; j >= 3; j--) {
      if (a[1][j] && a[2][j]) {
        op(1, j, 2, j, 1, j - 1);
        continue;
      }
      if (a[1][j]) {
        op(1, j, 1, j - 1, 2, j - 1);
        continue;
      }
      if (a[2][j]) {
        op(2, j, 1, j - 1, 2, j - 1);
        continue;
      }
    }
    solve();
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        assert(a[i][j] == 0);
      }
    }
    cout << (int) sol.size() << "\n";
    for (auto &it : sol) {
      for (auto &x : it) {
        cout << x << " ";
      }
      cout << "\n";
    }
  }
}