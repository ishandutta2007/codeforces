/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

template <class T> inline void relaxMax( T &a, T b ) { a = max(a, b); }

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int a[n];
  forn(i, n)
    scanf("%d", &a[i]);
  sort(a, a + n);

  int cnt = 0, base = n / k;
  forn(i, k)
    cnt += (n + i) / k > base;
  int cc = 0, ma[2][cnt + 1];
  memset(ma, -1, sizeof(ma));
  ma[cc][0] = 0;
  //printf("base = %d, cnt = %d\n", base, cnt);
  //forn(i, n) 
  //  printf("%d: %d\n", i, a[i]);
  forn(i, k - 1) {
    memset(ma[cc ^ 1], -1, sizeof(ma[cc ^ 1]));
    forn(j, min(i, cnt) + 1) 
      if (ma[cc][j] != -1) {
        int pos = (i + 1) * base + j - 1;
        //assert(j <= cnt);
        //assert(0 <= pos && pos < n);
        //printf("pos=%d, j=%d <-- %d + (%d - %d)\n", pos, j, ma[cc][j], a[pos + 1], a[pos]);
        relaxMax(ma[cc ^ 1][j], ma[cc][j] + a[pos + 1] - a[pos]);
        if (j + 1 <= cnt) {
          //printf("pos=%d, j=%d <-- %d + (%d - %d)\n", pos, j + 1, ma[cc][j], a[pos + 2], a[pos + 1]);
          relaxMax(ma[cc ^ 1][j + 1], ma[cc][j] + a[pos + 2] - a[pos + 1]);
        }
      }
    cc ^= 1;
  }
  //printf("%d - %d - %d\n", a[n], a[0], ma[cc][cnt]);
  printf("%d\n", a[n - 1] - a[0] - max(ma[cc][cnt], ma[cc][max(cnt - 1, 0)]));
}