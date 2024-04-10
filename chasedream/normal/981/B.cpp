%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 100005;
int a[N], b[N], x[N], y[N];
int tmp[N << 1], n, m;
int mx[N << 1];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i], &x[i]);
    tmp[i] = a[i];
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &b[i], &y[i]);
    tmp[i + n] = b[i];
  }
  sort(tmp + 1, tmp + n + m + 1);
  
  for (int i = 1; i <= n; i++) {
    int k = lower_bound(tmp + 1, tmp + n + m + 1, a[i]) - tmp;
    mx[k] = max(mx[k], x[i]);
  }
  
  for (int i = 1; i <= m; i++) {
    int k = lower_bound(tmp + 1, tmp + n + m + 1, b[i]) - tmp;
    mx[k] = max(mx[k], y[i]); 
  }
  
  long long ans = 0;
  for (int i = 1; i <= n + m; i++)
    ans += mx[i];
  cout << ans << '\n';
  return 0; 
}
// 233