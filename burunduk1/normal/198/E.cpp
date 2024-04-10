/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2012.06.16
 */

#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define BS(x) (x = lower_bound(a, a + an, x) - a)

typedef long long ll;

const int maxN = 250010;
const int maxT = 1 << 19;
const int maxMem = maxT * 19;

int X, Y, P, N, p[maxN], m[maxN], used[maxN];
ll R, r[maxN], d[maxN];
ll an, a[2 * maxN];

int qst, qen, qP[maxN];
ll qR[maxN];

int mpos = 0, mem[maxMem];
int pos[2 * maxT], num[2 * maxT], *val[2 * maxT];

ll sqr( ll x ) { return x * x; }

int *getMem( int n )
{
  int *res = mem + mpos;
  mpos += n;
  assert(mpos <= maxMem);
  return res;
}

inline bool mless( int i, int j )
{
  return m[i] < m[j];
}

inline void add( int p, ll r )
{
  qP[qen] = p, qR[qen++] = r;
}

void AddAll( int v, int P )
{
  int &Pos = pos[v], i;
  while (Pos < num[v] && m[i = val[v][Pos]] <= P)
  {
    if (!used[i])
      add(p[i], r[i]), used[i] = 1;
    Pos++;
  }
}

int main()
{
  scanf("%d%d%d%I64d%d", &X, &Y, &P, &R, &N);
  R *= R;
  forn(i, N)
  {
    int x, y;
    scanf("%d%d%d%d%I64d", &x, &y, &m[i], &p[i], &r[i]);
    r[i] *= r[i];
    d[i] = sqr(X - x) + sqr(Y - y);
  }

  an = 0;
  forn(i, N)
    a[an++] = d[i], a[an++] = r[i];
  a[an++] = R;
  sort(a, a + an);
  forn(i, N)
    BS(d[i]), BS(r[i]);
  BS(R);

  an = 0;
  forn(i, N)
    a[an++] = m[i], a[an++] = p[i];
  a[an++] = P;
  sort(a, a + an);
  forn(i, N)
    BS(m[i]), BS(p[i]);
  BS(P);

  forn(i, N)
    num[maxT + d[i]]++;
  for (int i = maxT - 1; i >= 1; i--)
    num[i] = num[2 * i] + num[2 * i + 1];
  forn(i, 2 * maxT)
    val[i] = getMem(num[i]);

  memset(num, 0, sizeof(num));
  forn(i, N)
  {
    int j = maxT + d[i];
    val[j][num[j]++] = i;
  }
  forn(i, maxT)
  {
    int j = maxT + i;
    sort(val[j], val[j] + num[j], mless);
  }

  for (int i = maxT - 1; i >= 1; i--)
  {
    int l = 2 * i, r = 2 * i + 1;
    num[i] = num[l] + num[r];
    merge(val[l], val[l] + num[l], val[r], val[r] + num[r], val[i], mless);
  }

  qst = 0, qen = 0;
  add(P, R);
  while (qst < qen)
  {
    P = qP[qst], R = qR[qst++];
    //printf("use P = %d, R = %d\n", (int)P, (int)R);

/*
    forn(i, N)
      if (m[i] <= P && d[i] <= R && !used[i])
        used[i] = 1, add(p[i], r[i]);
*/
        
    int l = maxT, r = maxT + R;
    while (l <= r)
    {
      if (l % 2 == 1) AddAll(l++, P);
      if (r % 2 == 0) AddAll(r--, P);
      l >>= 1, r >>= 1;
    }
  }

  printf("%d\n", qen - 1);
  return 0;
}