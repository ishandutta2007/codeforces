#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int mod = 1000000007;
int n;
string s;

int base = 31, hmod = 994648181;
int bpow[5005], hs[5005];

inline int get(int l, int r) {
  int h = hs[r];
  if (l) {
    h -= 1LL * hs[l - 1] * bpow[r - l + 1] % hmod;
    if (h < 0) h += hmod;
  }
  return h;
}

inline bool isLess(int x, int y, int len) {
  int l = 0, r = len + 1;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (get(x, x + m - 1) == get(y, y + m - 1)) l = m;
    else r = m;
  }

  // for (int i = 0; i < len; ++i) cout << s[x + i];
  // cout << " ";
  // for (int i = 0; i < len; ++i) cout << s[y + i];
  // cout << " " << (l < len && s[x + l] < s[y + l]) << endl;

  return l < len && s[x + l] < s[y + l];
}

int dp[5005][5005];

inline void add(int &r, int a) {
  if (a < 0) a += mod;
  r += a;
  if (r >= mod) r -= mod;
}

int main() {
  cin >> n >> s;

  // n = 5000; s = "";
  // for (int i = 0; i < n; ++i) {
  //   s += '1';
  // }

  base = 31 + rand() % 1000;
  if (base % 2 == 0) ++base;
  bpow[0] = 1;
  for (int i = 1; i <= 5001; ++i)
    bpow[i] = 1LL * bpow[i - 1] * base % hmod;

  int h = 0;
  for (int i = 0; i < n; ++i) {
    h = (1LL * h * base + s[i] - '0' + 4) % hmod;
    hs[i] = h;
  }

  for (int i = 0; i <= n; ++i) dp[0][i] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int ln = 1; ln <= n; ++ln) {
      add(dp[i][ln], dp[i][ln - 1]);
      if (i < ln || s[i - ln] == '0') continue;
      add(dp[i][ln], dp[i - ln][ln - 1]);
      if (i >= 2 * ln && isLess(i - 2 * ln, i - ln, ln))
        add(dp[i][ln], dp[i - ln][ln] - dp[i - ln][ln - 1]);
    }
  }

  printf("%d\n", dp[n][n]);
  return 0;
}