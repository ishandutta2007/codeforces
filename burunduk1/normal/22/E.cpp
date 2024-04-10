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

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int maxn = (int)1e5 + 10;

int n, a[maxn], is[maxn];
int cc, u[maxn];
int k, ind[maxn], res[maxn], V[maxn];
vector <int> c[maxn];

int calc( int i )
{
  if (u[i] == -1)
    res[i] = i;
  else if (res[i] == -1)
    res[i] = calc(a[i]);
  return res[i];
}

int main()
{
  scanf("%d", &n);
  forn(i, n)
    scanf("%d", &a[i]), is[--a[i]] = 1;

  forn(i, n)
    if (!u[i])
    { 
      cc++;
      int st = i;
      while (!u[st])
        u[st] = cc, st = a[st];
      if (u[st] == cc)
        u[st] = -1, V[k] = st, ind[st] = k++;
    }

  memset(res, -1, sizeof(res));
  forn(i, n)
    calc(i);
  forn(i, n)
    if (!is[i])
      c[ind[res[i]]].pb(i);

  if (k == 1)
  {
    printf("%d\n", sz(c[0]));
    forn(i, sz(c[0]))
      printf("%d %d\n", V[0] + 1, c[0][i] + 1);
  }
  else
  {
    int n = k, res = 0;
    forn(i, n)
      res += max(1, sz(c[i]));
    printf("%d\n", res);
    forn(i, n)
    {
      forn(j, sz(c[i])) if (j)
        printf("%d %d\n", V[i] + 1, c[i][j] + 1);

      int next = (i + 1) % n;
      printf("%d %d\n", V[i] + 1, (sz(c[next]) ? c[next][0] : V[next]) + 1);
    }
  }
  return 0;
}