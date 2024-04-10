%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
 
const int N = 500005;
int a[N], n, I;
int b[N], sum[N], k;
 
int main() {
  scanf("%d%d", &n, &I);
  I = 8 * I / n;
  if (I >= 30) {
    puts("0"); exit(0);
  }
 
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  } 
  sort(a + 1, a + n + 1);
  /*
  for (int i = 1; i <= n; i++)
    printf("%d ", a[i]);
  putchar('\n');
  */
  for (int i = 1; i <= n; i++) {
    int j = i;
    while (j < n && a[j + 1] == a[i]) j++;
    b[++k] = j - i + 1;
    sum[k] = sum[k - 1] + b[k];
    i = j;
  }
  
  /*
  printf("%d\n", k);
  for (int i = 1; i <= k; i++)
    printf("%d ", b[i]);
  putchar('\n');
  */ 
 
  I = pow(2, I);
  if (k <= I) {
    puts("0"); exit(0);
  }
  
  int ans = INT_MAX;
  for (int i = 1; i <= k - I + 1; i++) {
    int j = i + I - 1;
    ans = min(ans, sum[i - 1] + sum[k] - sum[j]);
  }
  printf("%d\n", ans);
  return 0;
} // orz