#include <bits/stdc++.h>

using namespace std;

bool home = false;

const int N = (int) 1e6 + 7;
const int INF = (int) 1e9;
int n;
int a[N][2];
int dp[N][2][2];
vector<int> par[N][2][2];

int main() {

#ifndef ONLINE_JUDGE

  home = true;
  freopen ("TonyStark", "r", stdin);

#endif // ONLINE_JUDGE

  if (!home) {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int tests;
  cin >> tests;
  while (tests--) {
    cin >> n;
    for (int i = 0; i <= n + 1; i++) {
      dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = INF;
      par[i][0][0] = par[i][0][1] = par[i][1][0] = par[i][1][1] = {-1, -1, -1};
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[i][0];
      a[i][1] = -a[i][0];
    }


    function<void(int, int, int, int, int, int)> upd = [&] (int i, int m1, int m2, int c1, int c2, int cur) {
      assert(m1 == a[i][0] || m1 == a[i][1] || m2 == a[i][0] || m2 == a[i][1]);
      if (m1 == a[i][0] || m1 == a[i][1]) {
        if (m2 < dp[i][0][(m1 == a[i][1])]) {
          dp[i][0][(m1 == a[i][1])] = m2;
          par[i][0][(m1 == a[i][1])] = {c1, c2, cur};
        }
      } else {
        if (m1 < dp[i][1][(m2 == a[i][1])]) {
          dp[i][1][(m2 == a[i][1])] = m1;
          par[i][1][(m2 == a[i][1])] = {c1, c2, cur};
        }
      }
    };

    upd(1, a[1][1], -INF, 0, 0, 0);


    for (int i = 1; i < n; i++) {
      for (int pos = 0; pos <= 1; pos++) {
        for (int who = 0; who <= 1; who++) {
          int m1 = a[i][who], m2 = dp[i][pos][who];
          if (pos) {
            swap(m1, m2);
          }
          for (int t = 0; t <= 1; t++) {
            int x = a[i + 1][t];
            if (x > m1) {
              upd(i + 1, x, m2, pos, who, x);
            } else {
              if (x > m2) {
                upd(i + 1, m1, x, pos, who, x);
              }
            }
          }
        }
      }
    }
    bool good = false;
    int p, w;
    for (int pos = 0; pos <= 1; pos++) {
      for (int who = 0; who <= 1; who++) {
        if (dp[n][pos][who] != INF) {
          good = true;
          p = pos;
          w = who;
        }
      }
    }
    if (!good) {
      cout << "NO\n";
      continue;
    }
    vector<int> sol;
    for (int i = n; i >= 2; i--) {
      sol.push_back(par[i][p][w][2]);
      int p2, w2;
      p2 = par[i][p][w][0];
      w2 = par[i][p][w][1];

      assert(p2 != -1);
      assert(w2 != -1);
      p = p2;
      w = w2;
    }
    sol.push_back(a[1][1]);

    cout << "YES\n";
    reverse(sol.begin(), sol.end());

    for (auto &x : sol) {
      cout << x << " ";
    }
    cout << "\n";
  }

  return 0;
}