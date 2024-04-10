#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

int main()
{
  int a, b, n, ans, i, l, a2;
  scanf("%d%d%d", &a, &b, &n);
  for (ans=-1010; ans<=1010; ans++)
  {
    l=0;
    a2=a;
    for (i=0; i<n; i++)
    {
      a2*=ans;
      if (abs(a2)>1010)
      {
        break;
        l=1;
      }
    }
    if (l==0 && a2==b)
    {
      printf("%d\n", ans);
      return 0;
    }
  }
  printf("No solution\n");
  return 0;
}