#include <bits/stdc++.h>

using namespace std;

#define int long long
bool home = 1;

int solve(int n, int m) {

  vector<bool> is_pow(n + 1, 0);
  vector<int> cnt(100, 0);

  for (int a = 2; a * a <= n; a++) {
    int cur = a;
    for (int p = 2; cur * a <= n; p++) {
      cur *= a;
      is_pow[cur] = 1;

    }
  }


  int sol = 1;

  for (int a = 2; a <= n; a++) {
    bool is_power = (is_pow[a] != 0);
    if (is_power) {
      continue;
    }
    int bmax = 1, prod = a;
    while (prod * a <= n) {
      bmax++;
      prod *= a;
    }
    cnt[bmax]++;
  }
  int cur = 0;
  for (int i = 99; i >= 1; i--) {
    cur += cnt[i];
    cnt[i] = 0;
    if (cur == 0) continue;
    for (int j = 1; j <= m; j++) {
      bool nw = 1;
      if (i * j > (i - 1) * m) {
        sol += (m - j + 1) * cur;
        break;
      }
      int L = (i * j + m - 1) / m, R = i - 1;
      for (int a = L; a <= R; a++) {
        if ((i * j) % a == 0) {
          nw = 0;
          break;
        }
      }

      sol += nw * cur;;
    }
  }
  return sol;
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int n, m;
  cin >> n >> m;
  cout << solve(n, m);
}