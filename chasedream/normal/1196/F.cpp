%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

#define int long long
const int N = 5000005;
const int M = 805;
const int inf = 1e16;

struct ele {
  int l, r, w;
  bool operator < (const ele& x) const {
    return w < x.w;
  }
} b[N << 1];
int dis[M][M];
int id[M * M], tot = 0;
int n, m, k;
int ans[M * M];

signed main() {
  for (int i = 0; i < M; i++)
    for (int j = 0; j < M; j++)
      if (i != j) dis[i][j] = inf;
      else dis[i][i] = 0;

  scanf("%lld%lld%lld", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    scanf("%lld%lld%lld", &b[i].l, &b[i].r, &b[i].w);
  }
  sort(b + 1, b + m + 1);
  
  for (int i = 1; i <= min(m, k); i++) {
    int l = b[i].l, r = b[i].r;
    if (!id[l]) id[l] = ++tot;
    if (!id[r]) id[r] = ++tot;
    dis[id[l]][id[r]] = dis[id[r]][id[l]] = b[i].w;
  }
  
  for (int k = 1; k <= tot; k++)
    for (int i = 1; i <= tot; i++)
      for (int j = 1; j <= tot; j++)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
  
  int fuk = 0;
  for (int i = 1; i <= tot; i++) {
    for (int j = i + 1; j <= tot; j++) {
      ans[++fuk] = dis[i][j];
    }
  }
  sort(ans + 1, ans + fuk + 1);
  printf("%lld\n", ans[k]);
  return 0;
}