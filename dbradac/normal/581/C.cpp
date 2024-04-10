#include <algorithm>
#include <cstdio>

using namespace std;

const int MAX = 1<<17;

bool Manji(int a, int b)
{
  return a % 10 > b % 10;
}

int p[MAX];

int main()
{
  int n, k;
  
  scanf("%d%d", &n, &k);  

  for (int i=0; i<n; i++)
    scanf("%d", &p[i]);

  sort(p, p + n, Manji);
  
  for (int i=0; i<n; i++) {
    if (10 - p[i] % 10 > k)
      break;

    if (p[i] < 100) {
      k -= 10 - p[i] % 10;
      p[i] += 10 - p[i] % 10;
    }
  }

  for (int i=0; i<n; i++) {
    for (;;) {
      if (k >= 10 && p[i] < 100) {
        k -= 10;
        p[i] += 10;
      }
      else
        break;
    }
  }

  int ret=0;

  for (int i=0; i<n; i++)
    ret += p[i] / 10;

  printf("%d\n", ret);

  return 0;
}