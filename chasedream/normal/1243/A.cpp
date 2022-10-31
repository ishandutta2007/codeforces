#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int a[N], n;

bool check(int mid) {
  int tots = 0;
  for (register int i = 1; i <= n; i++) {
    if (a[i] >= mid) tots++;
  }
  return tots < mid;
}

void work() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1);
  
  int l = 0, r = 100001, ans = 0;
  while (l < r) {
    int mid = l + r >> 1;
    if (check(mid)) r = mid;
    else ans = mid, l = mid + 1;
  }
  printf("%d\n", ans);
  return ;
}

int main() {
  int T; scanf("%d", &T);
  while (T--) work();
  return 0;
}