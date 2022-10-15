#include <bits/stdc++.h>

using namespace std;

bool home = 1;
#define int ll
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

/**
mt19937 rng_home(0);
mt19937 rng_oj((long long) (new char));

int rng() {
  if (home) {
    return rng_home();
  } else{
    return rng_oj();
  }
}

ull rng_ull() {
  return (ull) rng() * rng() ^ ((ull) rng() * rng());
}

int rng_range(int l, int r) {
  return l + abs(rng()) % (r - l + 1);
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

int mod;

int add(int a, int b) {
  a += b;
  if (a >= mod) return a - mod;
  if (a < 0) return a + mod;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % mod;
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
  return mul(a, pw(b, mod - 2));
}

void baga(int &a, int x) {
  a = add(a, x);
}

const int N = 1234 + 7;
const int D = 10 + 7;
int fact[N], ifact[N], dp[N][D][N]; /// dp[i][kids][k]

int comb(int n, int k) {
  assert(k < D);
  int ret = ifact[k];
  for (int i = n - k + 1; i <= n; i++) ret = mul(ret, i);
  return ret;
}

signed realMain() {
  int n, wanda;
  cin >> n >> wanda >> mod;
  if (n <= 2) {
    cout << "1\n"; return 0;
  }
  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);
  ifact[N - 1] = dv(1, fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) ifact[i] = mul(ifact[i + 1], i + 1);
  { /// no kids
    dp[1][0][0] = dp[1][wanda - 1][0] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= wanda; j++) {
      for (int k = 1; k <= n; k++) {
        baga(dp[i][j][k], dp[i][j][k - 1]);
        for (int t = 1; t <= j && t * k <= i; t++) {
          baga(dp[i][j][k], mul(dp[i - t * k][j - t][k - 1], comb(dp[k][wanda - 1][k - 1] + t - 1, t)));
        }
      }
    }
  }
  int ret = dp[n][wanda][(n - 1) / 2];
  if (n % 2 == 0) {
    ret = add(ret, comb(dp[n / 2][wanda - 1][n / 2 - 1] + 1, 2));
  }
  cout << ret << "\n";
  return 0;
}