#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

//#define M_PI 3.141592653589793238462643
//#define eps 1e-8

using namespace std;

int A[110000], M[120][2], n, f, b, l, s, t, v;

int main()
{
  int i, fl, j, fl2;
  //freopen(".in", "r", stdin);
  scanf("%d%d%d%d", &l, &b, &f, &n);
  for (s=0; s<n; s++)
  {
    scanf("%d%d", &t, &v);
    if (t==1)
    {
      fl=0;
      for (i=1000; i<=l+1000; i++)
      {
        fl2=1;
        for (j=i-b+1; j<i+f+v; j++)
          if (A[j]==1)
            fl2=0;
        if (i+v>l+1000)
          fl2=0;
        if (fl2==1)
        {
          fl=1;
          printf("%d\n", i-1000);
          M[s][0]=i;
          M[s][1]=v;
          for (j=i; j<=i+v; j++)
            A[j]=1;
          break;
        }
      }
      if (fl==0)
        printf("-1\n");
    }
    if (t==2)
    {
      v--;
      for (i=M[v][0]; i<=M[v][1]+M[v][0]; i++)
        A[i]=0;
    }
  }
  return 0;
}