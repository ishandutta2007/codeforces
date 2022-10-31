%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 1000005;
ll a[N], m;
int n, wz;

bool check(int mid) {
  int r = 0, res = 0;
  for (int i = 1; i <= n; i++) {
    while (r <= n && a[r] - a[i] <= 2 * mid) r++;
    res = max(res, r - i);
    if (r - i >= m + 1) {
      wz = (a[i] + a[r - 1]) / 2;
    }
  }
  if (res >= m + 1) return 1;
  else return 0;
}

int main() {
  int T; scanf("%d", &T);
  while (T--) {
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
    }
    
    int l = 0, r = 1e9, ans = 0;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (check(mid)) r = mid;
      else l = mid + 1;
    }
    check(r);
    printf("%d\n", wz);
  } 
  return 0;
}