#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <vector>

//#define M_PI 3.141592653589793238462643
#define eps 1e-8
#define inf ((int)1e9)
#define pb push_back

using namespace std;

double A[11000], k;

int main()
{
  int i;
  int n;
  double  l, r, m, c;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%lf", &n, &k);
  k/=100.0;
  for (i=0; i<n; i++)
    scanf("%lf", &A[i]);
  l=0.0, r=2000.0;
  while (r-l>1e-8)
  {
    m=(l+r)/2.0;
    c=0.0;
    for (i=0; i<n; i++)
    {
      if (A[i]>m)
        c+=(1.0-k)*(A[i]-m);
      if (A[i]<m)
        c-=m-A[i];
    }
    if (c>=0.0)
      l=m;
    else
      r=m;
  }
  printf("%.8lf\n", l);
  return 0;
}