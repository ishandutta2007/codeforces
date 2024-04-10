#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 5000 + 7;
const int A = (int) 1e5 + 7;
const int INF = (int) 1e9;
int n, a[N], b[N];
short int dp[N][N], s1[N][7], no[A], ce[A], s2[N][N], s3[N][7], s4[N][N];

bool match(int i, int j) {
  if (i == 0) return 1;
  return (abs(a[i] - a[j]) == 1 || (a[i] % 7 == a[j] % 7));
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 // freopen ("input", "r", stdin);

  set<int> sdistinct;
  cin >> n;
  assert(n < N);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sdistinct.insert(a[i]);
    b[i] = a[i] % 7;
  }
  {
    int kol = 0;
    for (auto &x : sdistinct) {
      ce[x] = ++kol;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      dp[i][j] = 2;
    }
  }
  for (int j = 1; j <= n; j++) {
    dp[0][j] = 1;
  }


  for (int x = 1; x <= n; x++) {
    for (int i = 1; i < x; i++) {
      dp[i][x] = max({(int) s1[i][b[x]], (int) dp[0][i] + 1, (int) s2[i][ce[a[x] - 1]], (int) s2[i][ce[a[x] + 1]]});
      if (i >= 1) {
        dp[i][x] = max((int) dp[i][x], (int) 2);
      }
    }
    for (int j = 0; j < x; j++) {

      s4[j][ce[a[x - 1]]] = max((int) s4[j][ce[a[x - 1]]], (int) dp[j][x - 1] + 1);
      s3[j][b[x - 1]] = max((int) s3[j][b[x - 1]], (int) dp[j][x - 1] + 1);

      dp[j][x] = max(dp[j][x], max({s3[j][b[x]], s4[j][ce[a[x] + 1]], s4[j][ce[a[x] - 1]]}));
      if (j >= 1) {
        dp[j][x] = max((int) dp[j][x], (int) 2);
      }
    }

    for (int j = 1; j < x; j++) {
      short int unu = 1;
      s1[x][b[j]] = max((int) s1[x][b[j]], (int) dp[j][x] + unu);
      s2[x][ce[a[j]]] = max((int) s2[x][ce[a[j]]], (int) dp[j][x] + unu);

    }
  }

  int sol = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      sol = max(sol, (int) dp[i][j]);
    }
  }
  cout << sol << "\n";


  return 0;
}