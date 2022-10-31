%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 300005;
const int inf = 1e9;

long long a[N], sum[N], b[15];
int n, m, k;

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < m; i++) b[i] = -1e18;

  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    sum[i] = sum[i - 1] + a[i];
  }
  
  long long ans = 0LL;
  for (int i = n; i >= 0; i--) {
    long long mx = -1e18;
    for (int j = 0; j < m; j++) {
      mx = max(mx, b[j]);
    } 
    ans = max(ans, mx - sum[i] - k);
    b[i % m] = max(b[i % m] - k, sum[i]);
  }
  printf("%lld\n", ans);
  return 0;
}