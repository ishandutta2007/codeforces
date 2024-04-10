#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], all[N], st[N], d[N];
 
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for(int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    all[i] = a[i];
  }
  int nnnnnnn;
  sort(all + 1, all + 1 + n);
  int m = unique(all + 1, all + 1 + n) - all - 1;
  for(int i = 1; i <= n; ++i) {
    int pos = lower_bound(all + 1, all + 1 + m, a[i]) - all;
    if(!st[pos]) {
      d[++d[0]] = pos;
      st[pos] = d[0];
    } else {
      int tmp = d[0] - st[pos] + 1;
      if(tmp > k) {
        d[++d[0]] = pos;
        st[pos] = d[0];
      }
    }
  }
  int pos = min(k, d[0]);
  printf("%d\n", pos);
  for(int i = d[0]; i >= d[0] - pos + 1; --i)
    printf("%d ", all[d[i]]);
  puts("");
  return 0;
}