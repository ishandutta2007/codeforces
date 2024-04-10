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

long double resnum, resden;
int e=1;
long long A[5000], Deg[20];

int main()
{
  int k, i, j, l;
  long long c, pl, pr, vl, vr;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%I64d%I64d%I64d%I64d%d", &pl, &pr, &vl, &vr, &k);
  Deg[0]=1ll, k--;
  for (i=1; i<=9; i++)
  {
    Deg[i]=Deg[i-1]*10ll;
    for (j=0; j<(1<<i); j++)
    {
      c=0; 
      for (l=0; l<i; l++)
      {
        if (j&(1<<l))
          c+=4ll*Deg[l];
        else
          c+=7ll*Deg[l];
      }  
      A[e]=c, e++;
    }
  }
  sort(A,A+e);
  A[e]=1234567890ll;
  for (i=0; i+k<e; i++)
  {
    if (vl<=A[i] && pr>=A[i+k] && vr>A[i-1] && pl<A[i+k+1])
    {
      resnum+=(long double)((min(A[i],vr)-max(A[i-1]+1ll,vl)+1ll)*(min(A[i+k+1]-1ll,pr)-max(A[i+k],pl)+1ll));
    }
    if (pl<=A[i] && vr>=A[i+k] && pr>A[i-1] && vl<A[i+k+1])
    {
      resnum+=(long double)((min(A[i],pr)-max(A[i-1]+1ll,pl)+1ll)*(min(A[i+k+1]-1ll,vr)-max(A[i+k],vl)+1ll));
    }
    if (k==0 && A[i]>=vl && A[i]<=vr && A[i]>=pl && A[i]<=pr)
      resnum-=(long double)(1.0);
  }
  resden=(long double)((pr-pl+1ll)*(vr-vl+1ll));
  printf("%.10lf\n", (double)(resnum/resden));
  return 0;
}