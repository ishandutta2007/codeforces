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

int dp[404][404];
int cnk[404][404];
int kek[404];

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> mod;

  for (int i = 0; i < 404; ++i) {
    cnk[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      add(cnk[i][j], cnk[i - 1][j]);
      add(cnk[i][j], cnk[i - 1][j - 1]);
    }
  }

  for (int len = 1; len <= n; ++len) {
    for (int pos = 1; pos <= len; ++pos) {
      int w1 = pos - 1, w2 = len - pos;
      add(kek[len], cnk[len - 1][w1]);
    }
  }

  for (int i = 0; i <= n; ++i) dp[n + 1][i] = 1;

  for (int w = n + 1; w > 0; --w) {
    for (int tot_len = w - 1; tot_len > 0; tot_len--) if (dp[w][tot_len] != 0) {
      for (int len = 1; len <= tot_len; ++len) {
        add(dp[w - len - 1][tot_len - len], mult(dp[w][tot_len], mult(kek[len], cnk[tot_len][len])));
      }
    }
  }

  cout << dp[0][0];
}