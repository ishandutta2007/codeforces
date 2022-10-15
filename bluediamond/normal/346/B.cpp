#include <bits/stdc++.h>

using namespace std;

const int N = 100 + 7;
const int A = 26;
string a, b, t;
int n, m, l;
int urm_a[N][A];
int urm_b[N][A];
int state[N][A];
set<string> rev;
int dp[N][N][N]; /// dp[i][j][state]

void build() {
  for (int x = 0; x < A; x++) {
    urm_a[n + 1][x] = n + 1;
  }
  for (int i = n; i >= 1; i--) {
    for (int x = 0; x < A; x++) {
      urm_a[i][x] = urm_a[i + 1][x];
    }
    urm_a[i][a[i] - 'A'] = i;
  }
  for (int x = 0; x < A; x++) {
    urm_b[m + 1][x] = m + 1;
  }
  for (int i = m; i >= 1; i--) {
    for (int x = 0; x < A; x++) {
      urm_b[i][x] = urm_b[i + 1][x];
    }
    urm_b[i][b[i] - 'A'] = i;
  }
  string cp;
  rev.insert(cp);
  for (int i = 1; i <= l; i++) {
    cp += t[i];
    string rcp = cp;
    reverse(rcp.begin(), rcp.end());
    rev.insert(rcp);
  }
  for (int i = 0; i <= l; i++) {
    for (int c = 0; c < A; c++) {
      string now;
      now += (char) ('A' + c);
      if (rev.count(now)) {
        state[i][c] = (int) now.size();
      }
      for (int j = i; j >= 1; j--) {
        now += t[j];
        if (rev.count(now)) {
          state[i][c] = (int) now.size();
        }
      }
    }
  }
}

struct State {
  int i;
  int j;
  int k;
};

State par[N][N][N];

string solve() {
  dp[0][0][0] = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int x = 0; x < A; x++) {
        if (urm_a[i + 1][x] <= n && urm_b[j + 1][x] <= m) {
          for (int cur = 0; cur < l; cur++) {
            if (state[cur][x] == l) {
              continue;
            }
            dp[urm_a[i + 1][x]][urm_b[j + 1][x]][state[cur][x]] = max(dp[urm_a[i + 1][x]][urm_b[j + 1][x]][state[cur][x]], 1 + dp[i][j][cur]);
            if (dp[urm_a[i + 1][x]][urm_b[j + 1][x]][state[cur][x]] == 1 + dp[i][j][cur]) {
              par[urm_a[i + 1][x]][urm_b[j + 1][x]][state[cur][x]] = {i, j, cur};
            }
          }
        }
      }
    }
  }
  State it;
  int sol = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int cur = 0; cur <= l; cur++) {
        sol = max(sol, dp[i][j][cur]);
        if (sol == dp[i][j][cur]) {
          it = {i, j, cur};
        }
      }
    }
  }
  string sool;
  while (sool.size() < sol) {
    sool += a[it.i];
    it = par[it.i][it.j][it.k];
  }
  if (sool.empty()) {
    sool = "0";
  }
  reverse(sool.begin(), sool.end());
  return sool;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b >> t;
  n = (int) a.size();
  m = (int) b.size();
  l = (int) t.size();
  a = "." + a;
  b = "." + b;
  t = "." + t;
  build();
  cout << solve() << "\n";


}