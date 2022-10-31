#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
  int x, y;

  scanf("%d%d", &x, &y);

  double rje;
  int raz = x / y;
  if (!(raz % 2))
    raz--;

  if (raz <= 0) {
    printf("-1\n");
    return 0;
  }

  if (x == y)
    rje = x;
  else
    rje = (x + y) / ((double) 1 + raz);

  printf("%.14lf\n", rje);

  return 0;
}