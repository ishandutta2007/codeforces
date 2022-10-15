#include <bits/stdc++.h>
///#prbgmb GCC target ("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")



///#pragma GCC opimize("O3")
#pragma GCC opimization ("unroint-loops")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;

signed realMain();

/**
bool eprim(int x) {
  if (x <= 1) {
    return 0;
  }
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}**/

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    a += M;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

int comb(int n, int k) {
  if (k > n - k) {
    k = n - k;
  }
  /// smart comb
  /// little boy, make sure that k <= n - k
  int up = 1, down = 1;
  for (int i = 1; i <= k; i++) {
    up = mul(up, n - i + 1);
    down = mul(down, i);
  }
  return dv(up, down);
}

void addup(int &a, int x) {
  a = add(a, x);
}

vector<vector<vector<int>>> memo;

int cnt2(int i, int j) {
  if (!memo.empty()) {
    return memo[i][j][0];
  }
  int bg = i, nd = j;
  i = 400;
  j = 400;
  /// i is small
  /// dp[len][cnt][c1]
  vector<vector<int>> dp(2, vector<int> (2, 0));
  dp[0][0] = 1;
  memo.push_back(dp);
  for (int n = 1; n <= i; n++) {
    vector<vector<int>> newdp(n + 2, vector<int> (n + 2, 0));
    for (int cnt = 0; cnt <= j && cnt < n; cnt++) {
      for (int one = 0; one <= j && one <= cnt; one++) {
        if (!dp[cnt][one]) {
          continue;
        }
        addup(newdp[cnt + 1][one + 1], dp[cnt][one]);
        if (one) {
          addup(newdp[cnt][one - 1], mul(one, dp[cnt][one]));
        }
        addup(newdp[cnt][one], mul(n - 1 - one, dp[cnt][one]));
      }
    }
    dp = newdp; /// change later
    memo.push_back(dp);
  }
  return cnt2(bg, nd);
  /// in each cycle I can insert it in size places


}

int cnt(int i, int j) {
  /// i-j is small
  int sol = 0;
  for (int one = max(0, 2 * j - i); one <= j; one++) {
    sol = add(sol, mul(comb(i, one), cnt2(i - one, j - one)));
  }
  return sol;
}

void solve(int n, int k) {
  vector<int> dp(k + 1, 0);
  for (int i = 0; i <= k; i++) {
    dp[i] = cnt(n, n - i);
    if (i >= 2) {
      dp[i] = add(dp[i], dp[i - 2]);
    }
  }
  for (int i = 1; i <= k; i++) {
    cout << dp[i] << " ";
  }
  cout << "\n";
}

signed realMain() {
/**
  In cate swap-uri pot ajunge la o permutare? In n-nr cicluri
  notez k = nr cicluri
  la op permutare pot ajunge la timpul n-k, n-k+2, n-k+4, ...
  dp[n][k] = dp[n][k - 2] + cnt(n, n - k)
  unde cnt(i, j) = nr permutari de lungime i care au j cicluri
  unde cnt2(i, j) = nr permutari de lungime i care au j cicluri si toate au lungime >= 2
  observam ca permutarea noastra o sa aiba putine cicluri de lungime >= 2 deci are sens sa folosim relatia dintre cnt(i,j) si cnt2(i,j)
  noi avem nevoie de j mare deci nr de cicluri de lungime 1 o sa fie mare. asa ca ne concentram pe nr cicluri de lungime >= 2

  cnt(i, j) = sum(one = 0...j| comb(i, one) * cnt2(i-one,j-one))
  ca sa aiba sens cnt2(i, j) trebuie 2*j<=i => in formula de mai sus avem
  2*(j-one)<=i-one ===>
  2*j-2*one<=i-one ===>
  2*j-i-2*one<=-one ===>
  2*j-i<=one ===>
  cnt(i, j) = sum(one = max(0,2*j-i)...j| comb(i, one) * cnt2(i-one,j-one))


  cnt(n, n - k) = sum(one = max(0,2*(n-k)-n)...n-k| comb(n, one) * cnt2(n-one,n-k-one))
  cnt(n, n - k) = sum(one = max(0,n-2*k)...n-k| comb(n, one) * cnt2(n-one,n-k-one))
**/
  int n, k;
  cin >> n >> k;
  solve(n, k);
  return 0;
}