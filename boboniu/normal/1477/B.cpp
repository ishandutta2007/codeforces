#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 223456

int n, q;
char s[maxN], f[maxN];
int l[maxN], r[maxN];

bool solve() {
  scanf("%d%d", &n, &q);
  scanf("%s", s + 1);
  scanf("%s", f + 1);
  for (int i = 0; i < q; i++) {
    scanf("%d%d", &l[i], &r[i]);
  }
  set<array<int, 3>> seg;
  for (int i = 1; i <= n; i++) {
    seg.insert({i, i, f[i] - '0'});
  }
  seg.insert({0, 0, -1});
  seg.insert({n + 1, n + 1, -1});
  for (int i = q - 1; i >= 0; i--) {
    int L = l[i], R = r[i];
    auto segLit = seg.lower_bound({L, L, -1});
    --segLit;
    auto segL = *segLit;
    if (segL[1] != L - 1) {
      seg.insert({segL[0], L - 1, segL[2]});
      seg.insert({L, segL[1], segL[2]});
      seg.erase(segLit);
    }

    auto segRit = seg.lower_bound({R + 1, R + 1, -1});
    --segRit;
    auto segR = *segRit;
    if (segR[1] != R) {
      seg.insert({segR[0], R, segR[2]});
      seg.insert({R + 1, segR[1], segR[2]});
      seg.erase(segRit);
    }
    int c0 = 0, c1 = 0;
    while (true) {
      auto segXit = seg.lower_bound({L, L, -1});
      auto segX = *segXit;
      if (segX[0] > R)
        break;
      if (segX[2] == 0)
        c0 += segX[1] - segX[0] + 1;
      else
        c1 += segX[1] - segX[0] + 1;
      seg.erase(segXit);
    }
    if (c0 == c1)
      return false;
    if (c0 > c1)
      seg.insert({L, R, 0});
    else
      seg.insert({L, R, 1});
  }
  for (auto x : seg) {
    int l = x[0], r = x[1];
    for (int j = l; j <= r; j++)
      if (j >= 1 && j <= n && s[j] != x[2] + '0') {
        return false;
      }
  }
  return true;
}

int main() {
  int tc;
  scanf("%d", &tc);
  for (int T = 0; T < tc; T++) {
    if (solve()) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
}