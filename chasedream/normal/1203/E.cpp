%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
 
const int N = 150005;
int a[N], b[N];
bool hsh[N << 2];
int n;
 
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1);
  
  int ans = 0;
  hsh[0] = 1;
  for (int i = 1; i <= n; i++) {
    if (!hsh[a[i] - 1]) {
      hsh[a[i] - 1] = 1;
      ans ++;
    }
    else if (!hsh[a[i]]) {
      hsh[a[i]] = 1;
      ans ++;
    }
    else if (!hsh[a[i] + 1]) {
      hsh[a[i] + 1] = 1;
      ans ++;
    }
  }
  printf("%d\n", ans);
  return 0;
}