%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 300005;
int a[N], b[N];
int n, k;
long long ans = 0LL;

bool cmp(int a, int b) {
  return a > b;
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    b[i] = a[i] - a[i - 1];
  }
  ans = a[n] - a[1];
  sort(b + 2, b + n + 1, cmp);
  for (int i = 1; i < k; i++) {
    ans -= b[i + 1];
  }
  printf("%lld\n", ans);
  return 0;
}