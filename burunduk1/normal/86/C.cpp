/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <ctime>
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
#include <fstream>

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
#define LEN(a) (int)(sizeof(a) / sizeof(a[0]))
#define IS(a, i) (((a) >> (i)) & 1)

typedef double dbl;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int mlen = 11;
const int maxM = 11;
const int maxN = (int)1e3 + 3;
const int maxV = maxM * mlen + 1;

int n, m, root = 0, vn = 1, next[maxV][4];
char s[maxM][mlen + 1];
int suf[maxV], last[maxV], p[maxV], dep[maxV], len[maxV], go[maxV][4];
vector <int> q[maxV];

const int MOD = (int)1e9 + 9;

int res, f[maxN][maxV][mlen + 1];

void add( int &a, int b )
{
  if ((a += b) >= MOD)
    a -= MOD;
}

int get( char c )
{
  const char *str = "ACGT";
  return strchr(str, c) - str;
}

int main()
{
  scanf("%d%d", &n, &m);
  forn(i, m)
  {
    scanf("%s", s[i]);
    int v = root;
    for (int j = 0; s[i][j]; j++)
    {
      int ch = get(s[i][j]);
      if (!next[v][ch])
        last[vn] = ch, p[vn] = v, dep[vn] = j + 1, next[v][ch] = vn++;
      v = next[v][ch];
    }
    len[v] = dep[v];
  }
  forn(i, vn)
    q[dep[i]].pb(i);
  forn(i, maxV)
    forn(j, sz(q[i]))
    {
      int v = q[i][j];
      if (v == root || p[v] == root)
        suf[v] = root;
      else
        suf[v] = go[suf[p[v]]][last[v]];
      forn(t, 4)
        if (next[v][t])
          go[v][t] = next[v][t];
        else
          go[v][t] = go[suf[v]][t];
      len[v] = max(len[v], len[suf[v]]);
    }
  
  f[0][0][0] = 1;
  forn(i, n + 1)
    forn(j, vn)
      forn(l, mlen)
      {
        int F = f[i][j][l];
        if (F > 0)
        {
          if (i == n)
          {
            if (l == 0)
              add(res, F);
          }
          else
          {
            forn(t, 4)
            {
              int v = go[j][t];
              if (dep[v] < l + 1)
                continue;
              int len1 = l + 1;
              if (len[v] >= len1)
                len1 = 0;
              add(f[i + 1][v][len1], F);
            }
          }
        }
      }
  
  cout << res << endl;
  return 0;
}