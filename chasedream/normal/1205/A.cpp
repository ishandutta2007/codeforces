#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define RE register
#define ll long long
#define ull unsigned long long

const int N = 1000005;
int a[N << 2];
int n;

ll Abs(ll k) {
  return k > 0 ? k : -k;
}

bool check() {
  int m = n >> 1;
  long long ans = 0;
  ll mx = -1e15, mn = 1e15;
  for (int i = 1; i <= m; i++) {
    ans += a[i];
  }
  ll cnt = ans;
  for (int i = 2; i <= n; i++) {
    ans += a[i + m - 1] - a[i - 1];
    mx = max(mx, ans);
    mn = min(mn, ans);
  }
  return Abs(mx - mn) <= 1;
}

int main() {
  scanf("%d", &n);
  int pp = 1;
  for (int i = 1; i <= n; i++) {
    if (i & 1) {
      a[i] = 2 * pp - 1;
      a[i + n] = 2 * pp;
    }
    else {
      a[i] = 2 * pp;
      a[i + n] = 2 * pp - 1;
    }
    pp++;
  }
  n <<= 1;
  for (int i = 1; i <= n; i++) {
    a[i + n] = a[i];
  }
  
  if (check()) {
    puts("YES");
    for (int i = 1; i <= n; i++) {
      printf("%d ", a[i]);
    } 
    putchar('\n');
  }
  else puts("NO");
  return 0;
}