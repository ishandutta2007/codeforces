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

const int maxm = 10 + 3;
const int maxn = 35 + 3;

int res = 0, n, m, K[maxm];
char s[maxm][maxn], z[maxm];

void go( int i, int k )
{
  if (i == n)
  { 
    int good = 1;
    forn(i, m)
    {
      int cnt = 0;
      forn(j, n)
        cnt += (z[j] != s[i][j]);
      good &= (cnt == K[i]);
    }
    res += good;
    return;
  }

  z[i] = s[0][i];
  go(i + 1, k);
  z[i] ^= 1;
  if (k > 0)
    go(i + 1, k - 1);
}

int main()
{
  scanf("%d%d ", &n, &m);
  forn(i, m)
    scanf("%s%d", s[i], &K[i]);
  go(0, K[0]);
  printf("%d\n", res);
  return 0;
}