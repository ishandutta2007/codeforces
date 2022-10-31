%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
 
const int N = 200005;
int opt[N], p[N], del[N];
int a[N], tag[N], n, delta;
int ans[N];
 
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  int q; scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d", &opt[i]);
    if (opt[i] == 1) {
      scanf("%d%d", &p[i], &del[i]);
    }
    else {
      scanf("%d", &del[i]);
    }
  } 
  
  for (int i = q; i >= 1; i--) {
    if (opt[i] == 1) {
      int v = p[i];
      if (tag[v] == 1) continue;
      tag[v] = 1;
      ans[v] = max(del[i], delta);
    }
    else {
      delta = max(delta, del[i]);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!tag[i])
      ans[i] = max(a[i], delta);
    printf("%d ", ans[i]);
  }
  return putchar('\n') & 0;
}