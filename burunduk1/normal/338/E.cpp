/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.08.16
 */

#include <cstdio>
#include <ctime>
#include <cassert>
#include <cstring>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int N = (int)1.5e5 + 10;
const int K = 400; // N/K = 500
const int NUM = 3000;

int k, n, m, h, a[N], b[N];
int cn, c[N];

struct part
{
  int i, len, f;

  part() { }
  part( int _i, int _len ) : i(_i), len(_len) { }

  // O(K*logm)
  void calc()
  {
    int l = -1, r = m - len;
    while (l < r)
    {
      int x = (l + r + 1) >> 1, bad = 0;
      forn(j, len)
        if (c[i + j] < b[x + j])
          bad = 1, j = len;
      if (bad)
        r = x - 1;
      else
        l = x;
    }
    f = l;
  }
};

int pn;
part p[NUM + 10];

// O(NUM)
int check()
{
  int pos = 0;
  forn(i, pn)
  {
    if (p[i].f < pos)
      return 0;
    pos += p[i].len;
  }
  return 1;
}

// O(NUM)
void shift( int i ) // >= i
{
  memmove(p + i + 1, p + i, sizeof(p[0]) * (pn - i));
}

// O(NUM)
void del_part( int i )
{
  pn--;
  memmove(p + i, p + i + 1, sizeof(p[0]) * (pn - i));
}

int split( int x )
{
  // log
  int li = 0, ri = pn;
  while (li < ri)
  {
    int mi = (li + ri) / 2;
    if (c[p[mi].i + p[mi].len - 1] < x)
      li = mi + 1;
    else
      ri = mi;
  }

  int i = li;
  if (i == pn)
    return i;
  shift(i);
  pn++;  
  p[i].len = lower_bound(c + p[i].i, c + p[i].i + p[i].len, x) - (c + p[i].i);
  p[i + 1].i += p[i].len, p[i + 1].len -= p[i].len;
  p[i + 1].calc();
  if (!p[i].len)
    del_part(i), i--;
  else
    p[i].calc();
  return i + 1;
}

// O(NUM + K*logm)
void del( int x )
{
  int i = split(x);
  c[p[i].i] = -1;
  p[i].i++;
  p[i].len--;
  if (p[i].len)
    p[i].calc();
  else
    del_part(i);
}

// O(NUM + K*logm)
void add( int x )
{
  int i = split(x);
  shift(i);
  c[cn] = x;
  p[i] = part(cn, 1);
  p[i].calc();
  pn++, cn++;
}

// O(mlogm)
void build() 
{
  int cc = 0;
  forn(i, cn)
    if (c[i] >= 0)
      c[cc++] = c[i];
  cn = cc;
  sort(c, c + cn);
  pn = 0;

  for (int pos = 0; pos < cn; pos += k)
  {
    p[pn] = part(pos, min(k, cn - pos));
    p[pn].calc();
    pn++;
  }
}

int main()
{
  scanf("%d%d%d", &n, &m, &h);
  forn(i, m)
    scanf("%d", &b[i]), b[i] = h - b[i];
  forn(i, n)
    scanf("%d", &a[i]);
  sort(b, b + m);
  k = min(m, K);

  cn = 0;
  forn(i, m)
    c[cn++] = a[i];
  build();

  int cnt = check();
  // (n-m) * (NUM + K*logm + mlogm/NUM)
  forn(i, n - m)
  {
    if (a[i] != a[i + m])
    {
      del(a[i]);     // +1 part
      add(a[i + m]); // +2 parts
      if (pn > NUM)
        build();
    }
    cnt += check();
  }
  fprintf(stderr, "time = %.2f\n", (double)clock() / CLOCKS_PER_SEC);
  printf("%d\n", cnt);
  return 0;
}