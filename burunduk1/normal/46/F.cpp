/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <functional>
#include <map>
#include <set>
         
using namespace std;

#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%Ld"
#endif

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fornd(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define forabd(i, a, b) for (int i = (int)(b); i >= (int)(a); i--)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair

#define EOL(i, n) " \n"[i == (n) - 1]

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

template <class T> T inline sqr(T x) { return x * x; }

const int maxn = 1010;

int n, m, k, a[maxn], b[maxn];
int is1[maxn][maxn], st1[maxn], was1[maxn];
int is2[maxn][maxn], st2[maxn], was2[maxn];
char has[maxn][maxn];
char end[maxn][maxn];

int pr[maxn], sz[maxn];

map <string, int> Map;
int cc = 0;

int getNo()
{
  static char s[(int)1e5];
  scanf("%s", s);
  if (!Map.count(s))
    Map[s] = cc++;
  return Map[s];
}

int Get( int i )
{
  return i == pr[i] ? i : (pr[i] = Get(pr[i]));
}

void Join( int i, int j )
{
  i = Get(i), j = Get(j);
  if (i == j)
    return;
  if (sz[i] < sz[j])
    swap(i, j);
  sz[i] += sz[j], pr[j] = i;
  forn(t, m)
    has[i][t] |= has[j][t];
}

void Solve( int is[maxn][maxn], int st[maxn], int was[maxn] )
{
  memset(has, 0, sizeof(has));
  forn(j, k)
  {
    int i = getNo(), num, t;
    scanf("%d%d", &st[i], &num), st[i]--;
    forn(j, num)
    {
      scanf("%d", &t), t--;
      has[st[i]][t] = 1;
      was[t] = st[i];
    }
  }
  forn(i, n)
    pr[i] = i, sz[i] = 1;
  forn(i, n)
    forn(e, m)
      if (has[Get(a[e])][e] || has[Get(b[e])][e])
        Join(a[e], b[e]);

  memset(end, 0, sizeof(end));
  forn(i, n)
    end[Get(i)][i] = 1;
  forn(i, n)
  {
    int v = Get(i);
    forn(j, n)
      is[i][j] = end[v][j];
  }
}

int main()
{
  scanf("%d%d%d", &n, &m, &k);
  forn(i, m)
    scanf("%d%d", &a[i], &b[i]), a[i]--, b[i]--;

  Solve(is1, st1, was1);
  Solve(is2, st2, was2);
  forn(i, k)
    if (!is2[st2[i]][st1[i]] || !is1[st1[i]][st2[i]])
    {
      puts("NO");
      return 0;
    }
  forn(i, m)
    if (!is2[was2[i]][was1[i]] || !is1[was1[i]][was2[i]])
    {
      puts("NO");
      return 0;
    }
  puts("YES");
  return 0;
}