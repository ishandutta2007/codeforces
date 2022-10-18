#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

//#define M_PI 3.141592653589793238462643
//#define eps 1e-2

using namespace std;

int n, m, k, a[1010][1010], ans, x, y;
double X[1010], Y[1010], R[1010], cx[1010], cy[1010];

int main()
{
  int i, j;
  scanf("%d%d%d", &n, &m, &k);
  for (i=0; i<n; i++)
    scanf("%lf%lf", &X[i], &Y[i]);
  for (i=0; i<m; i++)
    scanf("%lf%lf%lf", &R[i], &cx[i], &cy[i]);
  for (i=0; i<n; i++)
  {
    for (j=0; j<m; j++)
    {
      if (R[j]*R[j]>(X[i]-cx[j])*(X[i]-cx[j])+(Y[i]-cy[j])*(Y[i]-cy[j]))
        a[i][j]=1;
    }
  }
  for (i=0; i<k; i++)
  {
    ans=0; 
    scanf("%d%d", &x, &y);
    x--;
    y--;
    for (j=0; j<m; j++)
    {
      if (a[x][j]+a[y][j]==1)
        ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}