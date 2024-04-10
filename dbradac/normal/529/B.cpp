#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 1<<10;

struct str {
  int w, h;
} p[MAX];

bool operator < (str a, str b)
{
  return (a.w - a.h) > (b.w - b.h);
}

int lezi[MAX];

int main()
{
  int n, k, rje = MAX * MAX * MAX;

  scanf("%d", &n);
  k = n / 2;

  for (int i=0; i<n; i++)
    scanf("%d%d", &p[i].w, &p[i].h);

  sort(p, p+n);
  
  for (int i=0; i<=1000; i++) {
    int kolko=0;
    memset(lezi, 0, sizeof lezi);
    for (int j=0; j<n; j++) {
      if (p[j].h > i) {
        if (p[j].w > i)
          kolko = MAX;
        else {
          lezi[j] = 1;
          kolko++;
        }
      }
    }

    if (kolko > k)
      continue;

    for (int j=0; j<n; j++) {
      if (!lezi[j] && kolko < k && p[j].w <= i && p[j].w > p[j].h) {
        lezi[j] = 1;
        kolko++;
      }
    }
  
    int sir = 0;

    for (int j=0; j<n; j++) {
      if (lezi[j])
        sir += p[j].h;
      else
        sir += p[j].w;
    }

    rje = min(rje, i * sir);
  }

  printf("%d\n", rje);

  return 0;
}