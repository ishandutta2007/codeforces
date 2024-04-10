#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

typedef vector <int> vi;
typedef long long ll;
typedef pair <int, int> pii;

const int maxN = 1 << 19;
const ll P = 17239;

int d, n, N;
char s[maxN];
ll h1[2 * maxN], h2[2 * maxN], deg[maxN + 1];

void NO()
{
  puts("Impossible");
  exit(0);
}

int D0, D1;

void Set( int i, int val )
{
  int len = 1;
  i += N;
  h1[i] = h2[i] = val;
  for (i /= 2; i > 0; i /= 2, len *= 2)
  {
    h1[i] = h1[2 * i] * deg[len] + h1[2 * i + 1];
    h2[i] = h2[2 * i] + h2[2 * i + 1] * deg[len];
  }
}

inline int Len( int L1, int R1, int L2, int R2 )
{
  return max(min(R1, R2) - max(L1, L2) + 1, 0);
}

ll Get1( int v, int vL, int vR, int l, int r )
{
  if (l > vR || vL > r)
    return 0;
  if (l <= vL && vR <= r)
    return h1[v];
  int vM = (vL + vR) / 2;
  ll x = Get1(2 * v, vL, vM, l, r);
  ll y = Get1(2 * v + 1, vM + 1, vR, l, r);
  return x * deg[Len(vM + 1, vR, l, r)] + y;
}

ll Get2( int v, int vL, int vR, int l, int r )
{
  if (l > vR || vL > r)
    return 0;
  if (l <= vL && vR <= r)
    return h2[v];
  int vM = (vL + vR) / 2;
  ll x = Get2(2 * v, vL, vM, l, r);
  ll y = Get2(2 * v + 1, vM + 1, vR, l, r);
  return x + y * deg[Len(vL, vM, l, r)];
}

inline int isPal( int a, int b )
{
  if (a > b)
    return 1;
  return Get1(1, 0, N - 1, a, b) ==
         Get2(1, 0, N - 1, a, b);
}

int can( int i, char c )
{
  //printf("D0 = %d, D1 = %d, can[%d,%c] = ", D0, D1, i, s[i]);
  if (i + 1 >= D0 && isPal(i - D0 + 2, i - 1) && s[i - D0 + 1] == c)
    return 0;
  if (i + 1 >= D1 && isPal(i - D1 + 2, i - 1) && s[i - D1 + 1] == c)
    return 0;
  return 1;
}

int main()
{
  scanf("%d%s", &d, s);
  n = strlen(s);
  if (d == 1)
    NO();

  N = 1;
  while (N < n)
    N *= 2; 
  assert(N <= maxN); // N <= 2^{19}
  deg[0] = 1;
  forn(i, maxN)
    deg[i + 1] = deg[i] * P;

  forn(i, n)
    Set(i, s[i]);

  D0 = d + (d & 1);
  D1 = d + !(d & 1);
  assert(D0 % 2 == 0 && D1 % 2 == 1);

  int f = 0, first = 1;
  forn(i, n)
  {
    if (!f && !can(i, s[i]))
      f = 1;
    if (i == n - 1 && !f)
      f = 1;
    //printf("i = %d, f = %d, first = %d\n", i, f, first);
    if (f)
    {
      if (first)
        s[i]++, first = 0;
      else
        s[i] = 'a';
      while (s[i] <= 'z' && !can(i, s[i]))
        s[i]++;
      if (s[i] > 'z')
      {
        if (i == 0)
          NO();
        i -= 2;
        first = 1;
      }
      else
        Set(i, s[i]);
    }
  }
  puts(s);
  return 0;
}