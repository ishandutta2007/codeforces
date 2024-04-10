%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 500005;
int a[N], mx;
int jump[N][21], n, m;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    a[l] = max(a[l], r); // 
    mx = max(mx, r);
  }
  for (int i = 1; i <= mx; i++) {
    a[i] = max(a[i], a[i - 1]);
  }
  
  //  
  for (int i = 0; i <= mx; i++) {
    jump[i][0] = a[i];
  }
  for (int j = 1; j <= 20; j++) {
    for (int i = 0; i <= mx; i++) {
      jump[i][j] = jump[jump[i][j - 1]][j - 1];
    }
  }
  
  while (m--) {
    int l, r;
    scanf("%d%d", &l, &r);
    
    int ans = 0;
    for (int i = 20; i >= 0; i--) {
      if (jump[l][i] < r) {
        ans += (1 << i);
        l = jump[l][i];
      }
    }
    
    if (a[l] >= r) printf("%d\n", (++ans));
    else puts("-1"); 
  }
  return 0;
}