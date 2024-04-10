#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 31607;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

int matrix[21][21];
int rp[21][21];

int rev[mod];
bool take[21][21];
int prob[21][1<<21];
int kek[1<<21];

int dp[2];

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  for (int i = 0; i < mod; ++i) rev[i] = bp(i, mod-2);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> matrix[i][j];
      rp[i][j] = mult(matrix[i][j], rev[10000]);
    }
  }

  int ans = 0;
  for (int a = 0; a < 2; ++a) {
    for (int b = 0; b < 2; ++b) {

      int G = 1;

      for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        take[i][j] = false;
        if (i == j && a == 1) take[i][j] = true;
        if (i + j == n - 1 && b == 1) take[i][j] = true;
        if (take[i][j]) G = mult(G, rp[i][j]);
      }

      for (int i = 0; i < n; ++i) {
        int Q = 1;
        for (int j = 0; j < n; ++j) {
          if (!take[j][i]) Q = mult(Q, rp[j][i]);
        }

        prob[i][0] = Q;
        kek[0] = 1;

        int nxt = 1;
        int bit = -1;

        for (int mask = 1; mask < (1<<n); ++mask) {
          if (mask == nxt) {
            nxt *= 2;
            bit++;
          }

          if (take[bit][i]) prob[i][mask] = prob[i][mask ^ (1<<bit)];
          else prob[i][mask] = mult(prob[i][mask ^ (1<<bit)], rev[rp[bit][i]]);
          if (i == 0) {
            int Z = 1;
            for (int j = 0; j < n; ++j) {
              if (!take[bit][j]) Z = mult(Z, rp[bit][j]);
            }
            kek[mask] = mult(kek[mask ^ (1<<bit)], Z);
          }
        }
      }

      for (int mask = 0; mask < (1<<n); ++mask) {
        for (int i = 0; i < 2; ++i) dp[i] = 0;
        
        dp[(a + b + __builtin_popcount(mask)) % 2] = mult(G, kek[mask]);

        for (int i = 0; i < n; ++i) {
          
          int A = dp[0];
          add(A, mult(dp[1], prob[i][mask]));

          int B = dp[1];
          add(B, mult(dp[0], prob[i][mask]));
          dp[0] = A;
          dp[1] = B;
        }

        if (a == 0 && b == 0 && mask == 0) add(dp[0], -1);
        add(ans, dp[1]);
        add(ans, -dp[0]);



      }

    }
  }

  cout << ans;

  

}