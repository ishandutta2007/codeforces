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

const int maxn = 30;

int res = 0, h, w;
char a[maxn][maxn];

int main()
{
  scanf("%d%d", &h, &w);
  forn(i, h)
    scanf("%s", a[i]);
  forn(y1, h)
    forn(x1, w)
      forn(y2, y1 + 1)
        forn(x2, x1 + 1)
        {
          int is = 0;
          for (int i = y2; i <= y1; i++)
            for (int j = x2; j <= x1; j++)
              if (a[i][j] == '1')
                is = 1;
          if (!is)
            res = max(res, (y1 - y2 + x1 - x2 + 2) * 2);
        }
  printf("%d\n", res);
  return 0;
}