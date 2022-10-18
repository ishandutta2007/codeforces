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

using namespace std;

int N[110000], R[110000];
int M[110000];

int main()
{
  int n, i, j, k, a, t;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=1; i<=n; i++)
  {
    for (j=1; j*j<=2*i; j++)
    {
      if ((2*i)%(j+1)==0)
      {
        a=(((2*i)/(j+1))-j)/2;
        if ((2*a+j)*(j+1)!=2*i || a<=0)
          continue;
        //cerr<<i<<" "<<j+1<<endl;
        t=0;
        for (k=a; k<=a+j; k++)
          t^=N[k];
        M[t]=i;
        if (t==0 && R[i]==0)
          R[i]=j+1;
      }
    }
    for (t=0; ; t++)
      if (M[t]!=i)
      {
        N[i]=t;
        break;
      }
    //cerr<<i<<" "<<N[i]<<" "<<R[i]<<endl;
  }
  if (N[n]==0)
    printf("-1\n");
  else
    printf("%d\n", R[n]);   
  return 0;
}