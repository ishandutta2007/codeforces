%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 105;
int l[N], r[N];
int vis[N], n;
int ans[N];

bool cmp(int i, int j) {
  if (l[i] != l[j]) return l[i] < l[j];
  else return r[i] < r[j];
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &l[i], &r[i]);
  }
  l[0] = r[0] = INT_MAX;
  for (int i = 1; i <= n; i++) {
    int k = 0;
    for (int j = 1; j <= n; j++) {
      if (!vis[j] && cmp(j, k))
        k = j;
    }
    
    ans[k] = l[k]; vis[k] = 1;
    int fy = ans[k] + 1;
    for (int j = 1; j <= n; j++)
      if (l[j] < fy) l[j] = fy; 
  }
  for (int i = 1; i <= n; i++)
    printf("%d ", ans[i]);
  return putchar('\n') & 0;
}