#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
bool home = 1;

const int M = 998244353;

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

int n, x;
const int N = 500 + 7;
int dp[N][N];
int pt[N][N];
int comb[N][N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);


  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("input", "r", stdin);
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      pt[i][j] = pw(i, j);
    }
  }

  for (int x = 1; x < N; x++) {
    dp[1][x] = x;
  }

  for (int i = 0; i < N; i++) {
    comb[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      comb[i][j] = add(comb[i - 1][j - 1], comb[i - 1][j]);
    }
  }

  for (int n = 2; n < N; n++) {
    for (int x = 1; x < N; x++) {
      if (x - (n - 1) < 0) {
        dp[n][x] = 0;
        continue;
      }
      for (int small = 0; small <= n; small++) {
        int big = n - small;
        int csmall = n - 1, cbig = x - (n - 1);
        if (small > 0 && csmall <= 0) continue;

        if (big > 0 && cbig <= 0) continue;

        int sol = 1;

        if (small) {
          mulup(sol, pt[csmall][small]);
        }
        mulup(sol, comb[n][small]);
        mulup(sol, dp[big][cbig]);
        addup(dp[n][x], sol);
      }
    }
  }


  cin >> n >> x;

  cout << add(pt[x][n], -dp[n][x]) << "\n";


  return 0;
}