#include <bits/stdc++.h>

using namespace std;

///#define int long long
typedef long long ll;
typedef long double ld;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

void addup(int &a, int b) {
  a = add(a, b);
}

void mulup(int &a, int b) {
  a = mul(a, b);
}


const int N = 100 + 7;
const int K = 20 + 7;
const int INF = (int) 1e9;

void propag(int k, int dp1[K][K], int all1[K], int dp2[K][K], int all2[K], int dp[K][K], int all[K]) {
  int x;
  for (int db1 = 0; db1 <= k + 1; db1++) {
    if (all1[db1]) {

      for (int db2 = 0; db2 <= k + 1; db2++) {
        if (all2[db2]) {
          x = mul(all1[db1], all2[db2]);
          addup(all[min(db1, db2 + 1)], x);

        }
        for (int dw2 = 0; dw2 <= k; dw2++) {
          if (!dp2[db2][dw2]) continue;

          x = mul(all1[db1], dp2[db2][dw2]);
          if (dw2 + 1 + db1 <= k) {
            addup(all[min(db1, db2 + 1)], x);
          } else {
            addup(dp[min(db1, db2 + 1)][dw2 + 1], x);
          }

        }
      }
    }
    for (int dw1 = 0; dw1 <= k; dw1++) {
      if (!dp1[db1][dw1]) continue;

      for (int db2 = 0; db2 <= k + 1; db2++) {
        if (all2[db2]) {
          x = mul(dp1[db1][dw1], all2[db2]);
          if (dw1 + 1 + db2 <= k) {
            addup(all[min(db1, db2 + 1)], x);
          } else {
            addup(dp[min(db1, db2 + 1)][dw1], x);
          }
        }
        for (int dw2 = 0; dw2 <= k; dw2++) {
          if (!dp2[db2][dw2]) continue;

          x = mul(dp1[db1][dw1], dp2[db2][dw2]);

          int mx = -INF;
          if (dw2 + 1 + db1 > k) {
            mx = max(mx, dw2 + 1);
          }

          if (dw1 + 1 + db2 > k) {
            mx = max(mx, dw1);
          }

          if (mx == -INF) {
            addup(all[min(db1, db2 + 1)], x);
          } else {
            addup(dp[min(db1, db2 + 1)][mx], x);
          }

        }
      }
    }
  }
}

int n, k, d;
vector<int> g[N];

int dp[N][K][K], all[N][K]; /// dp[a][min dist to black][max dist to not covered white] sau allCovered[a][min dist to black]
int now[K][K], allcover[K];

#define print(x) cout << #x << " = " << x << "\n"

void dfs(int a, int p = -1) {
  vector<int> kids;
  for (auto &b : g[a]) {
    if (b != p) {
      kids.push_back(b);
      dfs(b, a);
    }
  }
  g[a] = kids; /// si daca gresesc, fac bine

  for (int db = 0; db <= k + 1; db++) {
    for (int dw = 0; dw <= k; dw++) {
      dp[a][db][dw] = 0;
      now[db][dw] = 0;
    }
    all[a][db] = 0;
    allcover[db] = 0;
  }

  /// pun black
  all[a][0] = 1;

  /// pun white
  dp[a][k + 1][0] = 1;


  for (auto &b : g[a]) {
    propag(k, dp[a], all[a], dp[b], all[b], now, allcover);

    for (int db = 0; db <= k + 1; db++) {
      for (int dw = 0; dw <= k; dw++) {
        dp[a][db][dw] = now[db][dw];
        now[db][dw] = 0;
      }
      all[a][db] = allcover[db];
      allcover[db] = 0;
    }
  }
return;
  for (int db = 0; db <= k + 1; db++) {
    if (all[a][db]) {
      cout << "all[" << a << "][" << db << "] = " << all[a][db] << "\n";
    }
    for (int dw = 0; dw <= k; dw++) {
      if (dp[a][db][dw]) {
        cout << "dp[" << a << "][" << db << "][" << dw << "] = " << dp[a][db][dw] << "\n";
      }
    }
  }
  cout << "\n";
}


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);

  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }


  dfs(1);

  int sol = 0;
  for (int db = 0; db <= k; db++) {
    addup(sol, all[1][db]);
  }
  cout << sol << "\n";
}