#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
long long h[1<<20], p[1<<20];

long long ia( long long x ) {
  if ( x < 0 ) return -x;
  return x;
}

long long di( long long x, long long a, long long b ) {
  if ( x < a )
    return b-x;
  if ( x > b )
    return x-a;
  return min(b + x - a -a, b + b - x- a);
}

int main() {
  int k;

  long long l, r, mi;

  scanf( "%d %d", &n, &m );
  for (int i = 0; i < n; ++i) {
    scanf( "%I64d", &h[i] );
  }
  for (int i = 0; i < m; ++i) {
    scanf( "%I64d", &p[i] );
  }

  l = -1; r = (1LL<<40);
  while (l+1 < r) {
    mi = (l+r) / 2;
    k = 0;
    for (int i = 0; i < n; ++i) {
      int j = k;
      while ((j<m) && di(h[i], p[k], p[j]) <= mi)
        j++;
      k = j;
    }
    if (k >= m)
      r = mi;
    else
      l = mi;
  }
  printf( "%I64d\n", r );
  return 0;
}