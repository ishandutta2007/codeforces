%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 1000005;
struct Q {
  int x, id;
  bool operator < (const Q& b) const {
    return x < b.x; 
  }
} b[N];
int a[N], ans[N];
int n, m;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &b[i].x);
    b[i].id = i;
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  int tail = 0;
  for (int i = 1; i <= m; i++) {
    while (tail < n && a[tail + 1] <= b[i].x) tail++;
    ans[b[i].id] = tail;
  } 
  for (int i = 1; i <= m; i++)
    printf("%d ", ans[i]);
  putchar('\n');
  return 0;
}
// wlzhouzhuan, 233