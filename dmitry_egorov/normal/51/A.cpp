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

int ans=1, n;
char A[1100][4];

int mod (int i)
{
  if (i>=4)
    return i-4;
  return i;
}

int main()
{
  int i, j, t, k;
  bool fl, fl2;
  //freopen(".in", "r", stdin);
  scanf("%d %c %c %c %c", &n, &A[0][0], &A[0][1], &A[0][3], &A[0][2]);
  for (i=1; i<n; i++)
  {                         
    scanf(" ** %c %c %c %c",  &A[i][0], &A[i][1], &A[i][3], &A[i][2]);
    fl=1;
    for (j=0; j<i && fl; j++)
    {
      for (t=0; t<4; t++)
      {
        fl2=1;
        for (k=0; k<4; k++)
          if (A[j][k]!=A[i][mod(k+t)])
          {
            fl2=0;
            break;
          }
        if (fl2)
        {
          fl=0;
          break;
        }    
      }
    }
    if (fl)
      ans++;
  }
  printf("%d\n", ans);
  return 0;
}