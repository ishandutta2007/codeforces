#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

char s[100005], t[100005];
int p1[100005], p[100005], start[100005], wh[100005], dp[100005];

int mod = 1000000007;
int add[100005], sum[100005];

void upd(int& r, int a) {
  r += a;
  if (r >= mod) r -= mod;
}

int main() {
  gets(s);
  gets(t);
  int ns = strlen(s), nt = strlen(t);
  int pref = 0;
  for (int i = 1; i < nt; ++i) {
    while (pref > 0 && t[pref] != t[i])
      pref = p1[pref - 1];
    if (t[pref] == t[i]) ++pref;
    p1[i] = pref;
    // cout << pref << endl;
  }
  pref = 0;
  for (int i = 0; i < ns; ++i) {
    while (pref > 0 && t[pref] != s[i])
      pref = p1[pref - 1];
    if (t[pref] == s[i]) ++pref;
    p[i] = pref;
    // cout << pref << endl;
    if (pref == nt) start[i - nt + 1] = 1;
  }
  int res = -1;
  memset(wh, -1, sizeof(wh));
  for (int i = nt - 1; i < ns; ++i) {
    if (start[i - nt + 1])
      res = i - nt + 1;
    wh[i] = res;
    // cout << i << "  " << res << endl;
  }
  int ans = 0;
  for (int i = nt - 1; i < ns; ++i) {
    int last = wh[i] - 1;
    if (last >= -1) {
      dp[i] = (wh[i] + 1 + (last == -1 ? 0 : add[last])) % mod;
    }
    // dp[i] %= mod;
    // if (i)
    //   dp[i] += dp[i - 1];
    // dp[i] %= mod;
    if (i) {
      sum[i] = sum[i - 1];
      add[i] = add[i - 1];
    }
    upd(sum[i], dp[i]);
    upd(add[i], sum[i]);
    // cout << dp[i] << "  " << sum[i] << "  " << add[i] << endl;
  }
  cout << sum[ns - 1] << endl;
  return 0;
}