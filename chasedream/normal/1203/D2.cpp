%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
 
const int N = 400005;
char a[N], b[N];
int n, m;
int pre[N], suf[N];
 
int main() {
  scanf("%s%s", a + 1, b + 1);
  n = strlen(a + 1); m = strlen(b + 1);
  
  int tail = 1;
  for (int i = 1; i <= n; i++) {
    if (tail <= m && a[i] == b[tail]) {
      pre[tail] = i;
      tail++;
    }
  }
  
  suf[m + 1] = n + 1;
  tail = m;
  for (int i = n; i >= 1; i--) {
    if (tail > 0 && a[i] == b[tail]) {
      suf[tail] = i;
      tail--;
    }
  }
  
  /*
  for (int i = 1; i <= m; i++) {
    printf("pre[%d] = %d\n", i, pre[i]);
    printf("suf[%d] = %d\n", i, suf[i]);
  } 
  */
  
  int ans = 0;
  for (int i = 1; i <= m + 1; i++) {
    ans = max(ans, suf[i] - pre[i - 1] - 1);
  }
  printf("%d\n", ans);
  return 0;
} //