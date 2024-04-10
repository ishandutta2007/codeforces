#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

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

const int N = 5000 + 7;
const int INF = (int) 1e9;
int n;
int digits[N];
int dp[N][N];
int mn[N][N];
int com[N][N];
string s;

int alldp[N], allmn[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 // freopen ("input", "r", stdin);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      mn[i][j] = INF;
    }
    allmn[i] = INF;
  }

  cin >> s;
  n = (int) s.size();
  for (int i = 1; i <= n; i++) {
    digits[i] = s[i - 1] - '0';
  }
  for (int i = n; i >= 1; i--) {
    for (int j = n; j >= 1; j--) {
      if (digits[i] == digits[j]) com[i][j] = 1 + com[i + 1][j + 1];
    }
  }
  for (int lr = 1; lr <= n; lr++) {
    dp[1][lr] = mn[1][lr] = 1;
    for (int l = 1; l + lr - 1 <= n; l++) {
      if (digits[l] == 0) continue;
      int r = l + lr - 1;
      int r2 = l - 1;
      addup(dp[l][r], alldp[r2]);
      mn[l][r] = min(mn[l][r], 1 + allmn[r2]);
      int l2 = r2 - lr + 1;
      if (l2 >= 1) {
        bool ok = 1;
        if (com[l][l2] < lr) {
          int j = com[l][l2];
          //bool found = 0;

          //for (int j = 0; j < lr; j++) {
          //  if (digits[l2 + j] == digits[l + j]) {continue;}
            if (digits[l2 + j] > digits[l + j]) ok = 0;
          //  found = 1;
          //  break;
         // }
         // assert(found);
        }
        if (ok) {
          addup(dp[l][r], dp[l2][r2]);
          mn[l][r] = min(mn[l][r], 1 + mn[l2][r2]);
        }
      }
    }
    for (int r = lr; r <= n; r++) {
      addup(alldp[r], dp[r - lr + 1][r]);
      allmn[r] = min(allmn[r], mn[r - lr + 1][r]);
    }
  }
  int sol = 0;
  for (int i = 1; i <= n; i++) {
    addup(sol, dp[i][n]);
  }

  cout << sol << "\n";

  int guy = INF;
  for (int j = n; j >= max(1, n - 20); j--) {
    if (dp[j][n]) {
      int base2 = 0;
      for (int k = j; k <= n; k++) {
        base2 = 2 * base2 + digits[k];
      }
      guy = min(guy, mn[j][n] + base2);
    }
  }
  if (guy != INF) {
    cout << guy << "\n";
    return 0;
  }
  for (int i = n; i >= 1; i--) {
    if (dp[i][n]) {
      int base2 = 0;
      for (int k = i; k <= n; k++) {
        base2 = add(digits[k], mul(2, base2));
      }
      cout << add(mn[i][n], base2) << "\n";
      return 0;
    }
  }
  assert(0);
  return 0;
}