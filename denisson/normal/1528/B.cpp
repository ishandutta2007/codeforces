#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 998244353;

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

int dp[1000007];
int p[1000007];

int cnt[1000007];

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  dp[1] = 1;
  p[1] = 1;

  for (int i = 1; i <= 1000000; ++i) {
    for (int j = i; j <= 1000000; j += i) cnt[j]++;
  }

  for (int i = 2; i <= n; ++i) {
    dp[i] = p[i - 1];
    add(dp[i], cnt[i]);


    /* for (int len = 1; len <= 2 * i - 1; ++len) {
      cout << i << ' ' << len << endl;
      if (2 * len > 2 * i) {
        // add(dp[i], dp[(2 * len - 2 * i) / 2]);
        // cout << "=====" << i << ' ' << (2 * len - 2 * i) / 2 << endl;
      } else {
        if ((2 * i) % (2 * len) == 0) add(dp[i], 1);
      }
    } */
    p[i] = p[i - 1];
    add(p[i], dp[i]);
  }

  cout << dp[n];
}