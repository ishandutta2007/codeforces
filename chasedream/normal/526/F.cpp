#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
const int N = 300010;
const int B = 300000;
ll ans, buc[N << 1];
int a[N], mx[N], mn[N];
int n;

void solve(int l, int r) {
  if (l == r) { ans++; return ; }
  int mid = l + r >> 1;
  solve(l, mid); solve(mid + 1, r);
  mn[mid] = mx[mid] = a[mid];
  mn[mid + 1] = mx[mid + 1] = a[mid + 1];
  for (register int i = mid - 1; i >= l; i--) {
    mx[i] = max(mx[i + 1], a[i]);
    mn[i] = min(mn[i + 1], a[i]);
  }
  for (register int i = mid + 2; i <= r; i++) {
    mx[i] = max(mx[i - 1], a[i]);
    mn[i] = min(mn[i - 1], a[i]);
  }
  
  // Case 1
  for (register int i = mid; i >= l; i--) {
    int j = i + (mx[i] - mn[i]);
    if (j > mid && j <= r && mx[j] < mx[i] && mn[j] > mn[i]) {
      ans++;
    }
  }
  // Case 2
  for (register int i = mid + 1; i <= r; i++) {
    int j = i - (mx[i] - mn[i]);
    if (j >= l && j <= mid && mx[j] < mx[i] && mn[j] > mn[i]) {
      ans++;
    }
  }
  // Case 3
  int L = mid + 1, R = mid + 1;
  for (register int i = mid; i >= l; i--) {
    while (R <= r && mn[R] > mn[i]) {
      buc[mx[R] - R + B]++; R++;
    }
    while (L < R && mx[L] < mx[i]) {
      buc[mx[L] - L + B]--; L++;
    }
    ans += buc[mn[i] - i + B];
  }
  while (L < R) {
    buc[mx[L] - L + B]--; L++;
  }
  // Case 4
  L = R = mid;
  for (int i = mid + 1; i <= r; i++) {
    while (L >= l && mn[L] > mn[i]) {
      buc[mx[L] + L]++; L--;
    }
    while (L < R && mx[R] < mx[i]) {
      buc[mx[R] + R]--; R--;
    }
    ans += buc[mn[i] + i]; 
  }
  while (L < R) {
    buc[mx[R] + R]--; R--;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[x] = y;
  }
  solve(1, n);
  printf("%lld\n", ans);
  return 0;
}