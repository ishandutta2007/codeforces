#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 1234567

const int T = 501;
bitset<T * 1000> dp[1111];

int h, w, a[1111], b[1111];
void partition(int n, int *a, vector<int> &plus, vector<int> &minus) {
  int s = 0;
  dp[0].reset();
  dp[0][0] = 1;
  for (int i = 0; i < n; i++)
    s += a[i];
  for (int i = 0; i < n; i++)
    dp[i + 1] = dp[i] | dp[i] << a[i];
  if (s % 2 != 0 || !dp[n][s / 2])
    return;
  vector<int> v;
  if (dp[n][s / 2]) {
    int t = s / 2, m = n;
    while (m) {
      if (dp[m - 1][t])
        m -= 1, minus.push_back(a[m]);
      else
        m -= 1, t -= a[m], plus.push_back(a[m]);
    }
  }
}

void solve() {
  scanf("%d", &h);
  for (int i = 0; i < h; i++)
    scanf("%d", &a[i]);
  scanf("%d", &w);
  for (int i = 0; i < w; i++)
    scanf("%d", &b[i]);
  if (h != w) {
    printf("No\n");
    return;
  }
  vector<int> hplus, hminus, wplus, wminus;
  partition(h, a, hplus, hminus);
  partition(w, b, wplus, wminus);
  if (hplus.empty() || wplus.empty()) {
    printf("No\n");
    return;
  }
  vector<int> RU[2], LU[2], RD[2], LD[2];
  while (!hplus.empty() && !wplus.empty()) {
    RU[0].push_back(hplus.back());
    RU[1].push_back(wplus.back());
    hplus.pop_back();
    wplus.pop_back();
  }
  while (!hminus.empty() && !wplus.empty()) {
    LU[0].push_back(hminus.back());
    LU[1].push_back(wplus.back());
    hminus.pop_back();
    wplus.pop_back();
  }
  while (!hplus.empty() && !wminus.empty()) {
    RD[0].push_back(hplus.back());
    RD[1].push_back(wminus.back());
    hplus.pop_back();
    wminus.pop_back();
  }
  while (!hminus.empty() && !wminus.empty()) {
    LD[0].push_back(hminus.back());
    LD[1].push_back(wminus.back());
    hminus.pop_back();
    wminus.pop_back();
  }
  assert(RU[0].empty() || LU[0].empty() || LD[0].empty() || RD[0].empty());
  printf("Yes\n");
  int x = 0, y = 0;
  auto print = [&](vector<int> h, vector<int> w, int dh, int dw) {
    sort(h.begin(), h.end());
    sort(w.begin(), w.end());
    reverse(h.begin(), h.end());
    for (int i = 0; i < h.size(); i++) {
      printf("%d %d\n", x, y);
      x += h[i] * dh;
      printf("%d %d\n", x, y);
      y += w[i] * dw;
    }
  };
  if (RD[0].empty() || LU[0].empty()) {
    print(RU[0], RU[1], 1, 1);
    print(LU[0], LU[1], -1, 1);
    print(LD[0], LD[1], -1, -1);
    print(RD[0], RD[1], 1, -1);
  } else {
    print(LU[0], LU[1], 1, -1);
    print(RU[0], RU[1], -1, -1);
    print(RD[0], RD[1], -1, 1);
    print(LD[0], LD[1], 1, 1);
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int tc = 0; tc < T; tc++) {
    solve();
  }
}