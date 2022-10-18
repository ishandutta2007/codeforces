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
#include <utility>

//#define M_PI 3.141592653589793238462643
#define eps 1e-8
#define inf ((int)1e9)
#define pb push_back
#define mp make_pair

using namespace std;

int L[110000];

int main()
{
  int i, j, x, y, cnt, n;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<110000; i++)
    L[i]=-inf;
  for (i=0; i<n; i++)
  {
    scanf("%d%d", &x, &y);
    cnt=0;
    for (j=1; j*j<=x; j++)
      if (x%j==0)
      {
      //  cerr<<j<<" "<<L[j]<<endl;
        if (i-L[j]>y)
          cnt++;
        L[j]=i;
        if (j*j!=x)
        {
          //cerr<<n/j<<" "<<L[n/j]<<endl;
          if (i-L[x/j]>y)
            cnt++;
          L[x/j]=i;
        }
      }
    printf("%d\n", cnt);
  }
  return 0;
}