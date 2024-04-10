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

const int maxL = (int)1e5 + (int)1e4;
const int maxn = 103;

int L, b, f, n, ind[maxn], len[maxn], is[maxL];

void add( int x, int len, int d )
{
  forn(i, len)
    is[x + i] += d;
}

int main()
{
  scanf("%d%d%d%d", &L, &b, &f, &n);
  forn(i, n)
  {
    int type, x;
    scanf("%d%d", &type, &x);
    if (type == 1)
    {
      int sum = 0;
      forn(j, x + f)
        sum += is[j];
      ind[i] = -1;
      for (int pos = 0; pos + x <= L; pos++)
      {
        if (!sum)
        {
          ind[i] = pos, len[i] = x;
          add(ind[i], len[i], 1);
          break;
        }
        sum += is[pos + x + f];
        if (pos - b >= 0)
          sum -= is[pos - b];
      }
      printf("%d\n", ind[i]);
    }
    else
    {
      x--;
      if (ind[x] != -1)
        add(ind[x], len[x], -1);
    }
  }
  return 0;
}