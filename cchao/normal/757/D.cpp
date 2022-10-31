#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
#define PB push_back
#define EB emplace_back
using LL = long long;
using PII = pair<int, int>;
#define F first
#define S second

bool valid[1 << 20] = {};

int n;
char s[110], *p;

int dp[75][1 << 20];
const int mod = 1000000007;
int f(int x, int m) {
  if (x >= n) {
    return valid[m] ? 1 : 0;
  }
  if (dp[x][m] >= 0) return dp[x][m];
  int &ret = dp[x][m];
  ret = valid[m] ? 1 : 0;
  int r = 0;
  for (int i = x; i < n; ++i) {
    r = r * 2 + s[i] - '0';
    if (r > 20) break;
    if (r) {
      ret += f(i + 1, m | (1 << (r - 1)));
      if (ret >= mod) ret -= mod;
    }
  }
  return ret;
}

int main() {
  memset(dp, -1, sizeof dp);
  for (int i = 1; i <= 20; ++i) {
    valid[(1 << i) - 1] = true;
  }
  scanf("%d%s", &n, s);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += f(i, 0);
    if (ans >= mod) ans -= mod;
  }
  printf("%d\n", ans);
  return 0;
}