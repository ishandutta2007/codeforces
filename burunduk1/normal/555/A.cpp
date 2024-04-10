/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n, k, m, len = 0;
  scanf("%d%d", &n, &k);
  forn(i, k) {
    scanf("%d", &m);
    int a[m];
    forn(i, m) 
      scanf("%d", &a[i]);
    if (a[0] == 1) {
      int p = 0;
      while (p + 1 < m && a[p + 1] == a[p] + 1)
        p++;
      len = p + 1;
    }
  }
  //printf("n = %d, len = %d, k = %d : ans = %d + %d\n", n, len, k, (n - len), (1 + (n - len) - k));
  printf("%d\n", (n - len) + (1 + (n - len) - k));
  return 0;
}