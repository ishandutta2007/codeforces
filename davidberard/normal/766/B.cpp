#include <stdio.h>
#include <stdlib.h>

int segments[100000];

int cmpre(const void * a, const void * b)
{
  return (*(int*)a - *(int*)b);
}

int main()
{
  int n;
  scanf("%d", &n);

  for(int i=0;i<n;++i)
    scanf("%d", &segments[i]);

  qsort(segments, n, sizeof(int), cmpre);

  int found = 0;

  for(int i=0;i<n-2;++i)
  {
    if(segments[i] + segments[i+1] > segments[i+2])
    {
      found = 1;
      printf("YES\n");
      break;
    }
  }

  if(!found)
    printf("NO\n");

  return 0;
}