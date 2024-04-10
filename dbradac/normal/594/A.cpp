#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 200100;

int p[MAX];

int main()
{
  int n, brmic;

  scanf("%d", &n); brmic = (n - 1) / 2;

  for (int i=0; i<n; i++)
    scanf("%d", &p[i]);

  sort(p, p + n);
  int rje = p[n-1] - p[0];

  for (int i=0; i<=brmic; i++)
    rje = min(rje, p[n-(brmic-i)-1] - p[i]);
  
  printf("%d\n", rje);

  return 0;
}