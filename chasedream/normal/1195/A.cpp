%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 1005;
int a[N], n, k;
int tot;

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    int x; scanf("%d", &x);
    if (a[x] == 1) tot--;
    else tot++;
    a[x] ^= 1;
  }
  printf("%d\n", n - tot + (tot + 1) / 2);
  return 0;
}
// wlzhouzhuan, 233