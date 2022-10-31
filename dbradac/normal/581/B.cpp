#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1<<17;

int p[MAX], rje[MAX];

int main()
{
  int n;

  scanf("%d", &n);

  for (int i=0; i<n; i++)
    scanf("%d", &p[i]);

  int maxx = 0;
  for (int i=n-1; i>=0; i--) {
    rje[i] = max(0, maxx + 1 - p[i]);
    maxx = max(maxx, p[i]);
  }

  for (int i=0; i<n; i++)
    printf("%d ", rje[i]);
  printf("\n");

  return 0;
}