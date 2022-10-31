#include <cstdio>
#include <algorithm>

using namespace std;

int a[1000][1000];
int w, h;

int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

int main() {
  scanf("%d%d", &h, &w);
  for(int y = 0; y < h; y++)
    for(int x = 0; x < w; x++)
      scanf("%d", &a[y][x]);
  int ans = -1;
  for(int y1 = 0; y1 < h; y1++)
    for(int y2 = y1 + 1; y2 < h; y2++) {
      int m1 = -1, m2 = -1;
      for(int x = 0; x < w; x++) {
        const int v = fastMin(a[y1][x], a[y2][x]);
        if (__builtin_expect(m1 < v,0)) { m2 = m1; m1 = v; }
        else if(__builtin_expect(m2 < v,0)) { m2 = v; }
      }
      ans = fastMax(ans, m2);
    }
  printf("%d\n", ans);
  return 0;
}