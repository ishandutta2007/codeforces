%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 2005;
struct ele {
  int num, pos;
} s[N];
bool cmp(ele x, ele y) {
  return x.num > y.num;
}

bool vis[N];
int a[N], n;
int ans, k, l, r;

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    s[i].num = a[i]; s[i].pos = i;
  }
  sort(s + 1, s + n + 1, cmp);
  
  for (int i = 1; i <= k; i++) {
    ans += s[i].num;
    vis[s[i].pos] = 1;
  } 
  printf("%d\n", ans);
  
  l = r = 1;
  while (!vis[r]) r++;
  for (int i = 1; i <= k; i++) {
    while (!vis[r + 1] && (r < n)) r++;
    printf("%d ", r - l + 1);
    l = r = r + 1; 
  }
  return putchar('\n'), 0;
}