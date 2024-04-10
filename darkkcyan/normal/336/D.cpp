#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

#define maxn 301010
#define rem ((llong)1e9+7)

llong mpow(llong b, llong ex) {
  llong ans = 1;
  for (; ex > 0; ex >>= 1) {
    if (ex & 1) (ans *= b) %= rem;
    (b *= b) %= rem;
  }
  return ans;
}

llong fac[maxn], rfac[maxn];
llong comb(int n, int k) {
  return fac[n] * rfac[k] % rem * rfac[n - k] % rem;
}

int g;
int n, m;

vector<vector<llong>> dp;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fac[0] = rfac[0] = 1;
    rep1(i, maxn - 1) {
      fac[i] = (fac[i - 1] * i) % rem;
      rfac[i] = mpow(fac[i], rem - 2);
    }

    cin >> m >> n >> g;
    if (g == 1) {
      if (m == 0) {
        cout << (n == 1);
        exit(0);
      }
      --m;
      g = 0;
    }

    dp.resize(max(n + 1, 4));
    dp[0].resize(m + 1);
    dp[1].resize(m + 1);
    dp[2].resize(m + 1);
    for (int i = 3; i < len(dp); ++i) dp[i].resize(min(3, m + 1));

    // formulas times!!!
    rep1(i, m) dp[0][i] = i & 1;
    dp[1][0] = 0;
    rep1(i, m) dp[1][i] = (i + 1) / 2 + (i & 1);

    for (int i = 2; i < len(dp); ++i) {
      dp[i][0] = 1;
      dp[i][1] = i;
      for (int f = 2; f < len(dp[i]); ++f) {
        if (i == 2) dp[i][f] = (dp[i][f - 1] + dp[i - 1][f - 1] + dp[i - 2][f]) % rem;
        else dp[i][f] = (dp[i - 1][f] + dp[i][f - 1]) % rem;
      }
    }

    if (m < len(dp[n])) {
      cout << dp[n][m] << '\n';
      exit(0);
    }

    llong ans = 0;
    for (int f = 3; f <= m; ++f) {
      llong times = comb(n + m - f - 2 - 1, n - 3);
      // clog << 2 << ' ' << f << ' ' << times << ' ' << dp[2][f] << endl;
      (ans += times * dp[2][f]) %= rem;
    }

    for (int i = 3; i <= n; ++i) {
      llong times = comb(n + m - i - 3, m - 3);
      // clog << i << ' ' << 2 << ' ' << times << ' ' << dp[i][2] << endl;
      (ans += times * dp[i][2]) %= rem;
    }
    cout << ans;

    return 0;
}