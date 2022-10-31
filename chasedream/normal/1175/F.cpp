%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 300005;
int a[N], pos[N];
int pre[N], suf[N];
int f[N], g[N];

int mx[N][20];
int n;

int ans;

int rmq(int l, int r) {
  int len = (int)log2(r - l + 1);
  int mx1 = a[mx[l][len]];
  int mx2 = a[mx[r - (1 << len) + 1][len]];
  if (mx1 >= mx2) return mx[l][len];
  else return mx[r - (1 << len) + 1][len];
}

void solve(int l, int r) {
  if (l > r) return ;
  if (l == r) {
    if (a[l] == 1) {
      //printf("special %d\n", l);
      ans++;
    }
    return ;
  }
  
  int mid = rmq(l, r);
  
  //  
  if (mid - l < r - mid) {
    for (int i = l; i <= mid; i++) {
      int j = i + a[mid] - 1;
      if (j < mid || j > r || j >= g[i])
        continue;
      //printf("kinds1 %d %d\n", i, j);
      ans++;
    }
  }
  else {
    for (int i = mid; i <= r; i++) {
      int j = i - a[mid] + 1;
      if (j < l || j > mid || j <= f[i])
        continue;
      //printf("kinds2 %d %d\n", j, i);
      ans++;
    }
  }
  solve(l, mid - 1); solve(mid + 1, r);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    pre[i] = pos[a[i]];
    pos[a[i]] = i;
    f[i] = max(f[i - 1], pre[i]);
  } 
  
  for (int i = 1; i <= n; i++) {
    pos[i] = n + 1;
  }
  
  g[n + 1] = n + 1;
  for (int i = n; i >= 1; i--) {
    suf[i] = pos[a[i]];
    pos[a[i]] = i;
    g[i] = min(g[i + 1], suf[i]);
  }
  
  for (int i = 1; i <= n; i++) {
    mx[i][0] = i;
  }
  for (int j = 1; j <= 20; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      int mx1 = a[mx[i][j - 1]];
      int mx2 = a[mx[i + (1 << j - 1)][j - 1]];
      if (mx1 >= mx2)
        mx[i][j] = mx[i][j - 1];
      else
        mx[i][j] = mx[i + (1 << j - 1)][j - 1];
    }
  }
  
  solve(1, n);
  printf("%d\n", ans);
  return 0;
}