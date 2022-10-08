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

const int maxn = 253;
const int maxs = maxn * maxn;

int tn, h, w, cc = 0, u[maxn][maxn];
char s[maxn][maxn];
int sn, sx[maxs], sy[maxs];

void dfs( int x, int y )
{
  if (!(0 <= x && x < w && 0 <= y && y < h && u[y][x] != cc && s[y][x] == '1'))
    return;
  u[y][x] = cc;
  sx[sn] = x, sy[sn++] = y;
  for (int dx = -1; dx <= 1; dx++)
    for (int dy = -1; dy <= 1; dy++)
      dfs(x + dx, y + dy);
}

int main()
{
  scanf("%d", &tn);
  while (tn--)
  {
    int cnt = 0;
    scanf("%d%d", &h, &w);
    forn(i, h)
      scanf("%s", s[i]);
    cc++;
    forn(i, h)
      forn(j, w)
        if (u[i][j] != cc && s[i][j] == '1')
        {
          sn = 0;
          dfs(j, i);

          int xmi = w, xma = 0, ymi = h, yma = 0;
          forn(k, sn)
          {
            xmi = min(xmi, sx[k]), xma = max(xma, sx[k]);
            ymi = min(ymi, sy[k]), yma = max(yma, sy[k]);
          }
          if (xma - xmi != yma - ymi)
            continue;

          int f1 = 1, f2 = 1, n = xma - xmi;
          if (4 * n != sn)
            f1 = 0;
//          printf("f1 = %d (n=%d sn=%d)\n", f1, n, sn);
          if (f1)
            forn(i, n)
              if (u[ymi][xmi + i] != cc ||
                  u[ymi + i][xma] != cc ||
                  u[yma][xma - i] != cc ||
                  u[yma - i][xmi] != cc)
                f1 = 0;
          if (2 * n != sn || n % 2 != 0)
            f2 = 0;
          if (f2)
          {
            int cx = (xmi + xma) / 2, cy = (ymi + yma) / 2;
            forn(i, n / 2)
              if (u[cy + i][xmi + i] != cc ||
                  u[yma - i][cx + i] != cc ||
                  u[cy - i][xma - i] != cc ||
                  u[ymi + i][cx - i] != cc)
                f2 = 0;
          }

          if (f1 || f2)
            cnt++;
        }
    printf("%d\n", cnt);
  }
  return 0;
}