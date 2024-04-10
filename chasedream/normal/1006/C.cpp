%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 200005;
ll a[N], sum, sum2, ans;
int n;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  } 
  int r = n + 1;
  for (int i = 1; i <= n; i++) {
    sum += a[i];
    while (r > i + 1 && sum2 + a[r - 1] <= sum)
      sum2 += a[r - 1], r--;
    if (sum == sum2)
      ans = sum;
  }
  printf("%lld\n", ans);
  return 0;
}