%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ull unsigned long long
#define lll __int128
 
const int N = 1005;
int a[N << 2], b[N << 1];
int n, m;
 
void work() {
  scanf("%d", &n); m = 4 * n;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &a[i]);
  }     
  sort(a + 1, a + m + 1);
  int cnt = 0;
  for (int i = 1; i <= m; i += 2) {
    if (a[i] != a[i + 1]) {
      puts("NO"); return ;
    }
    b[++cnt] = a[i];
  } 
  
  if (cnt == 2) {
    puts("YES"); return ;
  }
  
  ll area = b[1] * b[cnt];
  for (int i = 1, j = cnt; i <= j; i++, j--) {
    if ((ll)b[i] * b[j] != area) {
      puts("NO"); return ;
    }
  }
  puts("YES"); return ;
}
 
int main() {
  int T; scanf("%d", &T);
  while (T--) work();
  return 0;
}