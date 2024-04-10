%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 1000005;
int L[N], R[N];
int f[N], g[N];
int a[N], n, m;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    L[i] = n + 1;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (L[a[i]] == n + 1) L[a[i]] = i;
    R[a[i]] = i;
  }
  
  int l, r;
  r = 0, f[0] = 0;
  for (int i = 1; i <= m; i++) {
    if (f[i - 1] == n + 1) {
      f[i] = n + 1;
    }
    else {
      if (L[i] < r) f[i] = n + 1;
      else {
        r = max(r, R[i]);
        f[i] = r;
      }
    }
  }
  
  l = n + 1, g[m + 1] = n + 1;
  for (int i = m; i >= 1; i--) {
    if (g[i + 1] == 0) {
      g[i] = 0;
    }
    else {
      if (R[i] > l) g[i] = 0;
      else {
        l = min(l, L[i]);
        g[i] = l;
      }
    }
  }
  
  long long ans = 0LL;
  for (int i = 1; i <= m; i++) {
    ans += m + 2 - (upper_bound(g + i + 1, g + m + 2, f[i - 1]) - g); 
  }
  printf("%lld\n", ans);
  return 0;
}