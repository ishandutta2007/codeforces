#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int n, arr[100005];

int mn[19][100005], mx[19][100005], len[100005];

int getmn(int l, int r) {
  int ind = len[r - l + 1];
  int ret = min(mn[ind][l], mn[ind][r - (1<<ind) + 1]);
  return ret;
}

int getmx(int l, int r) {
  int ind = len[r - l + 1];
  int ret = max(mx[ind][l], mx[ind][r - (1<<ind) + 1]);
  return ret;
}

int dp[100002], fen[100002];

void upd(int pos, int val) {
  for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
    fen[pos] = min(fen[pos], val);
}

int get(int l, int r) {
  if (l > r) return 1000000000;
  int ret = 1000000000, pos = l;
  for (; pos <= 100001; pos |= (pos + 1))
    ret = min(ret, fen[pos]);
  // for (int i = l; i <= r; ++i)
  //   ret = min(ret, dp[i]);
  return ret;
}


int main() {
  int s, l;
  scanf("%d%d%d", &n, &s, &l);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }

  memset(mn, -1, sizeof(mn));
  for (int i = 0; i < 18; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == 0) mn[i][j] = arr[j];
      else {
        mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1<<(i - 1))]);
      }
    }
  }

  memset(mx, -1, sizeof(mx));
  for (int i = 0; i < 18; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == 0) mx[i][j] = arr[j];
      else {
        mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1<<(i - 1))]);
      }
    }
  }

  len[1] = 0; len[2] = 1;
  int pw = 2, pc = 1;
  while (pw <= n) {
    for (int j = pw; j <= n && j < pw + pw; ++j)
      len[j] = pc;
    pw += pw; ++pc;
  }

  // cout << mn[1][1] << endl;
  // cout << getmn(1, 2) << endl;
  // return 0;

  // for (int i = 0; i < n; ++i)
  //   for (int j = i; j < n; ++j) {
  //     int v = getmx(i, j);
  //     for (int t = i; t <= j; ++t) {
  //       if (arr[t] > v)
  //         cout << i << "  " << j << " " << arr[t] << "  " << v << endl;
  //     }
  //   }

  for (int i = 0; i <= 100001; ++i)
    fen[i] = dp[i] = 1000000000;
  dp[0] = 0;
  if (l == 1)
    upd(0, 0);

  for (int i = 0; i < n; ++i) {
    int ll = -1, rr = i;
    while (rr - ll > 1) {
      int m = (ll + rr) >> 1;
      if (getmx(m, i) - getmn(m, i) <= s) rr = m;
      else ll = m;
    }
    dp[i + 1] = get(rr, i - l + 1) + 1;
    // cout << rr << " " << i - l + 1 << " " << dp[i + 1] << " " << get(rr, i - l + 1) << endl;
    if (i - l + 2 >= 0) {
      // cout << "Set: " << i - l + 1 << " " << dp[i - l + 1] << endl;
      upd(i - l + 2, dp[i - l + 2]);
    }
  }
  if (dp[n] >= 1000000000) dp[n] = -1;
  cout << dp[n] << endl;
  return 0;
}