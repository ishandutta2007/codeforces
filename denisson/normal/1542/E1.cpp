#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
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

int n;

int cnk[555][555];
int fac[555];

const int MID = 130000;

int dp[503][507 * 507];
int p[507 * 507];

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> mod;

  fac[0] = 1;
  for (int i = 0; i < 555; ++i) {
    cnk[i][0] = 1;
    if (i) fac[i] = mult(fac[i - 1], i);
    for (int j = 1; j <= i; ++j) {
      add(cnk[i][j], cnk[i - 1][j]);
      add(cnk[i][j], cnk[i - 1][j - 1]);
    }
  }

  int res = 0;

  dp[1][MID] = 1;

  for (int len = 1; len < 501; ++len) {
    for (int w = -len * (len - 1) / 2; w <= len * (len - 1) / 2; ++w) {
      // -len...len
      // 1..len+1..1

      add(p[MID + w - len], dp[len][w + MID]);
      add(p[MID + w + 1], -dp[len][w + MID]);
      add(p[MID + w + 1], -dp[len][w + MID]);
      add(p[MID + w + len + 2], dp[len][w + MID]);
    }
    for (int w = len * (len - 1) / 2; w >= -len * (len - 1) / 2; --w) {
      add(dp[len][w + MID], dp[len][w + MID + 1]);
    }

    int step = 0, val = 0;

    for (int w = -len * (len + 1) / 2; w <= len * (len + 1) / 2; ++w) {
      add(step, p[w + MID]);
      add(val, step);
      dp[len + 1][w + MID] = val;
    }

    // if (len == 2) cout << step << ' ' << val << endl;

    for (int w = 0; w < 507 * 507; ++w) p[w] = 0;
  }

 // cout << dp[3][MID-3] << ' ' << dp[3][MID-2] << ' ' << dp[3][MID-1] << ' ' << dp[3][MID] << ' ' << dp[3][MID + 1] << ' ' << dp[3][MID + 2] << ' ' << dp[3][MID + 3] << endl;

  for (int com = 0; com + 2 <= n; ++com) {
    int now = 0;
    int ost = n - com;

    for (int i = 0; i + 1 < ost; ++i) for (int j = i + 1; j < ost; ++j) {
      int dist = j - i + 1;

     // cout << ost - 1 << ' ' << dist << ' ' << dp[ost - 1][dist + MID] << endl;

      add(now, dp[ost - 1][dist + MID]);

      //  for (int w1 = 0; w1 <= 50 * 50 / 2; ++w1) for (int w2 = w1 + dist; w2 <= 50 * 50 / 2; ++w2)
      //    add(now, mult(dp[ost - 1][w1], dp[ost - 1][w2]));
      // cout << com << ' ' << i << ' '  << j << ' ' << now << endl;
    }

    add(res, mult(mult(fac[com], cnk[n][com]), now));
  }

  cout << res;
}