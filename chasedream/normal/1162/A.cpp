#include <bits/stdc++.h>
using namespace std;

int a[55], n, m, h;

int main() {
  scanf("%d%d%d", &n, &h, &m);
  for (int i = 1; i <= n; i++)
    a[i] = h;

  while (m--) {
    int l, r, x; scanf("%d%d%d", &l, &r, &x);
    for (int i = l; i <= r; i++)
      a[i] = min(a[i], x);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) ans += pow(a[i],2);
  cout<<ans;
  return 0;
}