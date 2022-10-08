#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

void calc( int w, int h, int x1, int y1, int x2, int y2, int &xmi, int &ymi, int &xma, int &yma )
{
  xmi = 1 + max(0, x1 - x2);
  ymi = 1 + max(0, y1 - y2);
  xma = w - max(0, x2 - x1);
  yma = h - max(0, y2 - y1);
//  printf("%d,%d -- %d,%d\n", xmi, ymi, xma, yma);
}

int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
    int w, h, x1, y1, x2, y2;
    int xmi1, ymi1, xma1, yma1;
    int xmi2, ymi2, xma2, yma2;

    scanf("%d%d%d%d%d%d", &w, &h, &x1, &y1, &x2, &y2);
    calc(w, h, x1, y1, x2, y2, xmi1, ymi1, xma1, yma1);
    calc(w, h, x2, y2, x1, y1, xmi2, ymi2, xma2, yma2);

    int dw = min(xma1, xma2) - max(xmi1, xmi2) + 1;
    int dh = min(yma1, yma2) - max(ymi1, ymi2) + 1;

    printf("%I64d\n", (ll)w * h - (ll)(xma1 - xmi1 + 1) * (yma1 - ymi1 + 1) - (ll)(xma2 - xmi2 + 1) * (yma2 - ymi2 + 1) + (ll)max(dw, 0) * max(dh, 0));
  }
  return 0;
}