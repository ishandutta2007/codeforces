#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main()
{
  int n;
  scanf("%d", &n);

  int v;
  int min = INT_MAX;
  int mincount = 0;
  int max = 0;
  int maxcount = 0;
  for(int i=0;i<n;++i)
  {
    scanf("%d", &v);
    if( v < min)
    {
      min = v;
      mincount = 1;
    }
    else if( v == min)
    {
      ++mincount;
    }

    if(mincount > 0)
    {
      if(v > max)
      {
       max = v;
       maxcount = 1;
      }
      else if( v == max )
      {
        ++maxcount;
      }
    }
  }

  if(n-maxcount-mincount >= 0)
    printf("%d\n", n-maxcount-mincount);
  else
    printf("0\n");

  return 0;
}