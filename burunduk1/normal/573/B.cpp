/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

struct Tree {
  int *t, n;

  Tree( int n, int *a ) : n(n) {
    t = new int[2 * n];
    copy(a, a + n, t + n);
    for (int i = n - 1; i > 0; i--)
      t[i] = min(t[2 * i], t[2 * i + 1]);
  }

  void change( int i, int x ) {
    t[n + i] = x;
    for (i = (n + i) / 2; i > 0; i /= 2)
      t[i] = min(t[2 * i], t[2 * i + 1]);
  }

  int get( int l, int r ) {
    int res = INT_MAX;
    for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
      if ((l & 1) == 1) res = min(res, t[l++]);
      if ((r & 1) == 0) res = min(res, t[r--]);
    }
    return res;
  }
};

int main() {
  int n;
  scanf("%d", &n), n += 2;
  int a[n], b[n];
  for (int i = 1; i < n - 1; i++)
    scanf("%d", &a[i]);
  a[0] = a[n - 1] = 0;
  forn(i, n)
    b[i] = a[i] - i;
  Tree l(n, b);
  forn(i, n)
    b[i] = a[i] + i;
  Tree r(n, b);
  int ma = 0;
/*
  forn(i, n) 
    printf("%d ", a[i]);
  puts("");
*/
  forn(i, n) {
    //printf("%d : %d = %d + %d, %d = %d - %d\n", i, l.get(0, i) + i, l.get(0, i), i, r.get(0, i) - i, r.get(0, i), i);
    ma = max(ma, min(l.get(0, i) + i, r.get(i, n - 1) - i));
  }
  printf("%d\n", ma);
  return 0;
}