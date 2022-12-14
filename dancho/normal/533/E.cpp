#include <cstdio>
#include <cstring>

int n;
char s[1 << 20];
char t[1 << 20];

int dp[1 << 17][2][2];

int getDP(int pt, int ad, int rm) {
  if (dp[pt][ad][rm] != -1) {
    return dp[pt][ad][rm];
  }
  int ps = pt - ad + rm;
  if (pt >= n) {
    if (ps >= n) {
      return 1;
    }
    return 1;
  }
  if (ps >= n) {
    // must add letter from t to w.
    //
    if (!ad) {
      return 1;
    } else {
      return 0;
    }
  }
  int sl = 0;
  if (s[ps] == t[pt]) {
    sl += getDP(pt + 1, ad, rm);
  }
  if (!ad && s[ps] != t[pt]) {
    // add letter from t.
    //
    sl += getDP(pt + 1, 1, rm);
  }
  if (!rm && s[ps] != t[pt]) {
    sl += getDP(pt, ad, 1);
  }
  return (dp[pt][ad][rm] = sl);
}

int main() {
  scanf("%d", &n);
  scanf("%s", s);
  scanf("%s", t);

  if (strcmp(s, t) == 0) {
    int ans = 26 + n * 25;
    printf("%d\n", ans);
    return 0;
  }

  memset(dp, -1, sizeof(dp));
  printf("%d\n", getDP(0, 0, 0));
  return 0;
}