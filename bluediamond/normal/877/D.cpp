/// 103
#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 7;
int n, m, a[N][N], rr1, cc1, rr2, cc2, sum[N][N], dp[N][N];
set<int> lr[N], lc[N];
queue<pair<int, int>> q;

int get(int r1, int c1, int r2, int c2) {
  return sum[r2][c2] - sum[r2][c1 - 1] - sum[r1 - 1][c2] + sum[r1 - 1][c1 - 1];
}

bool gol(int r1, int c1, int r2, int c2) {
  if (r1 < 1 || c1 < 1 || r2 > n || c2 > m) return 0;
  return get(r1, c1, r2, c2) == 0;
}

void updr(int r, int c1, int c2, int val) {
  while (1) {
    auto it = lr[r].lower_bound(c1);
    if (it == lr[r].end()) return;
    int c = *it;
    if (c > c2) return;
    lr[r].erase(c);
    lc[c].erase(r);
    dp[r][c] = val;
    q.push({r, c});
  }
}

void updc(int c, int r1, int r2, int val) {
  while (1) {
    auto it = lc[c].lower_bound(r1);
    if (it == lc[c].end()) return;
    int r = *it;
    if (r > r2) return;
    lr[r].erase(c);
    lc[c].erase(r);
    dp[r][c] = val;
    q.push({r, c});
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= m; j++) a[i][j] = (s[j - 1] == '#');
    int curs = 0;
    for (int j = 1; j <= m; j++) curs += a[i][j], sum[i][j] = sum[i - 1][j] + curs, dp[i][j] = -1;
    for (int j = 1; j <= m; j++) if (a[i][j] == 0) lr[i].insert(j), lc[j].insert(i);
  }
  cin >> rr1 >> cc1 >> rr2 >> cc2;
  q.push({rr1, cc1});
  lr[rr1].erase(cc1);
  lc[cc1].erase(rr1);
  dp[rr1][cc1] = 0;
  while (!q.empty()) {
    pair<int, int> it = q.front();
    q.pop();
    int r = it.first, c = it.second;
    int lo = c - k, hi = c, c1, c2, r1, r2;
    while (lo <= hi) {
      int half = (lo + hi) / 2;
      if (gol(r, half, r, c)) {
        c1 = half;
        hi = half - 1;
      } else {
        lo = half + 1;
      }
    }
    lo = c;
    hi = c + k;
    while (lo <= hi) {
      int half = (lo + hi) / 2;
      if (gol(r, c, r, half)) {
        c2 = half;
        lo = half + 1;
      } else {
        hi = half - 1;
      }
    }
    lo = r - k;
    hi = r;
    while (lo <= hi) {
      int half = (lo + hi) / 2;
      if (gol(half, c, r, c)) {
        r1 = half;
        hi = half - 1;
      } else {
        lo = half + 1;
      }
    }
    lo = r;
    hi = r + k;
    while (lo <= hi) {
      int half = (lo + hi) / 2;
      if (gol(r, c, half, c)) {
        r2 = half;
        lo = half + 1;
      } else {
        hi = half - 1;
      }
    }
    updr(r, c1, c2, dp[r][c] + 1);
    updc(c, r1, r2, dp[r][c] + 1);
  }
  cout << dp[rr2][cc2] << "\n";

}