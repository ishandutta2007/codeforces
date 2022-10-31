#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
  double r, x1, y1, x2, y2, dist;

  scanf("%lf%lf%lf%lf%lf", &r, &x1, &y1, &x2, &y2);

  dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) + 1e-13;

  if (dist / (2 * r) - 1e-11 < 0)
    printf("0\n");
  else
    printf("%d\n", (int) (dist / (2 * r) - 1e-11) + 1);

  return 0;
}