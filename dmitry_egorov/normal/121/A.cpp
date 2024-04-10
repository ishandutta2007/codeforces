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

int e=1;
long long Deg[15], A[5000];

long long solve (long long r)
{
  int i=1;
  long long res=0ll;
  while (A[i]<=r)
    res+=A[i]*(A[i]-A[i-1]), i++;
  res+=A[i]*(r-A[i-1]);
  //cerr<<r<<" "<<res<<endl;
  return res;
}

int main()
{
  long long l, r;
  int i, j, k;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  for (Deg[0]=1ll, i=1; i<15; i++)
    Deg[i]=Deg[i-1]*(10ll);
  for (i=1; i<=10; i++)
    for (j=0; j<(1<<i); j++, e++)
      for (k=0; k<i; k++)
      {
        A[e]+=(4ll)*Deg[k];
        if (j&(1<<k))
          A[e]+=(3ll)*Deg[k];
      }
  sort(A,A+e);
  /*for (i=0; i<10; i++)
    cerr<<A[i]<<" ";
  cerr<<endl;*/
  //cerr<<e<<endl;
  scanf("%I64d%I64d", &l, &r); 
  printf("%I64d\n", solve(r)-solve(l-1));
  return 0;
}