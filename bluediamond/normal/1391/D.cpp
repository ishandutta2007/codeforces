#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9;
#define matrix vector<vector<int>>

matrix base(int n, int m) {
  matrix a(n);
  for (int i = 0; i < n; i++) {
    a[i].resize(m, 0);
  }
  return a;
}

matrix get_rot(matrix a) {
  int n = (int) a.size(), m = (int) a[0].size();
  matrix b = base(m, n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      b[j][i] = a[i][j];
    }
  }
  return b;
}

int cost2(int x, int y, int mask) {
  int a = (mask & 1) ? 1 : 0, b = (mask & 2) ? 1 : 0;
  return (a != x) + (b != y);
}

int cost3(int x, int y, int z, int mask) {
  int a = (mask & 1) ? 1 : 0, b = (mask & 2) ? 1 : 0, c = (mask & 4) ? 1 : 0;
  return (a != x) + (b != y) + (c != z);
}

bool ok2(int mask1, int mask2) {
  int a1 = (mask1 & 1) ? 1 : 0, b1 = (mask1 & 2) ? 1 : 0;
  int a2 = (mask2 & 1) ? 1 : 0, b2 = (mask2 & 2) ? 1 : 0;
  return ((a1 + a2 + b1 + b2) % 2 == 1);
}

bool ok3(int mask1, int mask2) {
  int a1 = (mask1 & 1) ? 1 : 0, b1 = (mask1 & 2) ? 1 : 0, c1 = (mask1 & 4) ? 1 : 0;
  int a2 = (mask2 & 1) ? 1 : 0, b2 = (mask2 & 2) ? 1 : 0, c2 = (mask2 & 4) ? 1 : 0;
  return (((a1 + a2 + b1 + b2) % 2 == 1) && ((b1 + b2 + c1 + c2) % 2 == 1));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  matrix a = base(n, m);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      a[i][j] = s[j] - '0';
    }
  }
  if (n > m) {
    a = get_rot(a);
    swap(n, m);
  }
  if (n == 1) {
    cout << "0\n";
    return 0;
  }
  if (n == 2) {
    int x = a[0][0], y = a[1][0];
    vector<int> dp(4);
    for (int i = 0; i < 4; i++) {
      dp[i] = cost2(x, y, i);
    }
    for (int c = 1; c < m; c++) {
      int x = a[0][c], y = a[1][c];
      vector<int> now(4);
      for (int i = 0; i < 4; i++) {
        now[i] = cost2(x, y, i);
      }
      vector<int> ndp(4, INF);
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          if (ok2(i, j)) {
            ndp[j] = min(ndp[j], dp[i] + now[j]);
          }
        }
      }
      dp = ndp;
    }
    int sol = INF;
    for (auto &it : dp) {
      sol = min(sol, it);
    }
    cout << sol << "\n";
    return 0;
  }
  if (n == 3) {
    int x = a[0][0], y = a[1][0], z = a[2][0];
    vector<int> dp(8);
    for (int i = 0; i < 8; i++) {
      dp[i] = cost3(x, y, z, i);
    }
    for (int c = 1; c < m; c++) {
      int x = a[0][c], y = a[1][c], z = a[2][c];
      vector<int> now(8);
      for (int i = 0; i < 8; i++) {
        now[i] = cost3(x, y, z, i);
      }
      vector<int> ndp(8, INF);
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          if (ok3(i, j)) {
            ndp[j] = min(ndp[j], dp[i] + now[j]);
          }
        }
      }
      dp = ndp;
    }
    int sol = INF;
    for (auto &it : dp) {
      sol = min(sol, it);
    }
    cout << sol << "\n";
    return 0;
  }
  cout << "-1\n";
  return 0;
}