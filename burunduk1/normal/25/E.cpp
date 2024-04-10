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

char s[3][maxn], t[maxn * 3], z[maxn * 3];
int p[maxn * 3];

void Join( char *s )
{
  int sn = strlen(s);
  int tn = strlen(t);

  sprintf(z, "%s#%s", s, t);

  p[0] = 0;
  int k = 0, zn = strlen(z);
  for (int i = 1; i < zn; i++)
  {
    while (k && z[i] != z[k])
      k = p[k - 1];
    if (z[i] == z[k])
      k++;
    p[i] = k;
  }

  forn(i, zn)
    if (p[i] >= sn)
      return;
  sprintf(t + tn, "%s", s + p[zn - 1]);
}

int main()
{
  int res = 0, p[3], len[3];
  forn(i, 3)
  {
    gets(s[i]), p[i] = i;
    res += (len[i] = strlen(s[i]));
  }

  do
  {
    t[0] = 0;
    forn(i, 3)
      Join(s[p[i]]);
    res = min(res, (int)strlen(t));
  } while (next_permutation(p, p + 3));

  printf("%d\n", res);
  return 0;
}