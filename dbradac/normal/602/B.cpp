#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1<<17;

int p[MAX];
int ima[MAX];

int main()
{
  int n;
  
  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    scanf("%d", &p[i]);
    p[i] += 5;
  }

  int rje=0;
  for (int i=0, j=0; i<n; i++) {
    for (; ima[p[i] - 2] || ima[p[i] + 2]; j++)
      ima[p[j]]--;

    ima[p[i]]++;
    rje = max(rje, i - j + 1);    
  }

  printf("%d\n", rje);

  return 0;
}