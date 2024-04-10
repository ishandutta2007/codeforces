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

const int maxn = 19;

int n, m, c[maxn][maxn];
ll res = 0;
ll f[1 << maxn][maxn];

int main()
{
  scanf("%d%d", &n, &m);
  while (m--)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    a--, b--;
    c[a][b] = c[b][a] = 1;
  }

  forn(i, n)
    f[1 << i][i] = 1;
  forn(pr, 1 << n)
  {
    int first = 0, bn = 0;
    forn(i, n)
      if ((pr >> i) & 1)
        first = i, i = n;
    forn(i, n)
      bn += (pr >> i) & 1;

    forn(i, n)
      if (f[pr][i])
      {
//        printf("%d %d : %I64d\n", pr, i, f[pr][i]);
        if (c[i][first] && bn >= 3)
          res += f[pr][i];
        forn(j, n)
          if (j > first && !((pr >> j) & 1) && c[i][j])
          {
//            printf("j = %d\n", j);
            f[pr | (1 << j)][j] += f[pr][i];
          }
      }
  }
  cout << res / 2 << endl;
  return 0;
}