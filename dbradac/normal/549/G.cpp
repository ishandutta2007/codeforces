#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1<<18;

struct str {
  int x, par, poz;
} p[MAX];

bool operator < (str a, str b)
{
  return a.x > b.x;
}

int main()
{
  int n;

  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    scanf("%d", &p[i].par);
    p[i].poz = n - i - 1;
    p[i].x = p[i].par - p[i].poz;
  }

  sort(p, p+n);

  int ne = 0;
  for (int i=0; i<n-1; i++)
    if (p[i].x == p[i+1].x)
      ne = 1;

  if (ne)
    printf(":(\n");
  else {
    for (int i=n-1; i>=0; i--)
      printf("%d ", p[i].x + i);
    printf("\n");
  }


  return 0;
}