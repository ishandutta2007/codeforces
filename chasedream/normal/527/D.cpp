%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 200005;
struct ele {
  int l, r;
  ele (int l = 0, int r = 0):
    l(l), r(r) {}
  bool operator < (const ele& b) const {
    if (r != b.r) return r < b.r;
    else return l > b.l;
  }
} a[N];
int n;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x, w; scanf("%d%d", &x, &w);
    a[i] = ele(x - w, x + w);
  }
  sort(a + 1, a + n + 1);

  int lst = a[1].r, tot = 1;
  for (int i = 2; i <= n; i++) {
    if (lst <= a[i].l)
      lst = a[i].r, tot++;
  }
  printf("%d\n", tot);
  return 0; 
}