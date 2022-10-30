#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

int Query(int r1, int r2, int s1, int s2, int sw)
{
  if (sw) {
    swap(r1, s1);
    swap(r2, s2);
  }

  printf("? %d %d %d %d\n", r1, s1, r2, s2);
  fflush(stdout);
  int x;
  scanf("%d", &x);
  return x;
}

pair<P, P> Rijesi1(int r1, int r2, int s1, int s2, int sw)
{
  int lo = s1, hi = s2;
  for (;lo < hi;) {
    int mid = (lo + hi) / 2;

    if (Query(r1, r2, s1, mid, sw))
      hi = mid;
    else
      lo = mid + 1;
  }

  s2 = lo;

  lo = s1, hi = s2;
  for (;lo < hi;) {
    int mid = (lo + hi + 1) / 2;

    if (Query(r1, r2, mid, s2, sw))
      lo = mid;
    else
      hi = mid - 1;
  }

  s1 = lo;



  lo = r1, hi = r2;
  for (;lo < hi;) {
    int mid = (lo + hi) / 2;

    if (Query(r1, mid, s1, s2, sw))
      hi = mid;
    else
      lo = mid + 1;
  }

  r2 = lo;

  lo = r1, hi = r2;
  for (;lo < hi;) {
    int mid = (lo + hi + 1) / 2;

    if (Query(mid, r2, s1, s2, sw))
      lo = mid;
    else
      hi = mid - 1;
  }

  r1 = lo;

  if (sw) {
    swap(r1, s1);
    swap(r2, s2);
  }
  return make_pair(P(r1, s1), P(r2, s2));
}

int main()
{
  int n;

  scanf("%d", &n);

  int sw = 0;

  for (;;) {
    int lo = 1, hi = n;
    for (; lo < hi; ) {
      int mid = (lo + hi) / 2;
      int tmp = Query(1, n, 1, mid, sw);
      if (tmp)
        hi = mid;
      else
        lo = mid + 1;
    }

    if (lo < n && Query(1, n, lo + 1, n, sw) == 1) {
      pair<P, P> a = Rijesi1(1, n, 1, lo, sw);
      pair<P, P> b = Rijesi1(1, n, lo + 1, n, sw);
      printf("! %d %d %d %d %d %d %d %d\n", a.X.X, a.X.Y, a.Y.X, a.Y.Y, b.X.X, b.X.Y, b.Y.X, b.Y.Y);
      fflush(stdout);
      return 0;
    }

    sw = 1;
  }

  return 0;
}