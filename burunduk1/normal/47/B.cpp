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

int c[3][3];
int bad, pn, p[3], u[3];

void dfs( int v )
{
  u[v] = 1;
  forn(i, 3)
    if (c[v][i])
    {
      if (u[i] == 0)
        dfs(i);
      else if (u[i] == 1)
        bad = 1;
    }
  u[v] = 2;
  p[pn++] = v;
}

int main()
{
  forn(i, 3)
  {
    char s[9];
    scanf("%s", s);
    int a = s[0] - 'A', b = s[2] - 'A';
    if (s[1] == '>')
      c[a][b] = 1;
    else
      c[b][a] = 1;
  }
  forn(i, 3)
    if (!u[i])
      dfs(i);

  if (bad)
    puts("Impossible");
  else
    forn(i, 3)
      putc('A' + p[i], stdout);
  return 0;
}