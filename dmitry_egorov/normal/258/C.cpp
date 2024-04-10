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
#include <assert.h>

#define MPI 3.141592653589793238462643
#define eps 1e-8
#define inf ((int)1e9)
#define pb push_back
#define mp make_pair
#define mod (1000000007)

using namespace std;

long long deg (long long v, int d)
{
  if (d==0)
    return 1;
  if (d&1)
    return (v*deg(v,d-1))%mod;
  return deg((v*v)%mod,(d>>1));
}

long long res, tres;
int C[110000], D[510], D2[510], e, e2;
int A[110000];

int main()
{
  int n, i, p, j;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d", &A[i]);
  sort(A,A+n);
  for (i=0; i<n; i++)
    C[A[i]+1]++;
  for (i=1; i<110000; i++)
    C[i]+=C[i-1];
  for (p=1; p<=100000; p++)
  {
    for (e=0, e2=0, j=1; j*j<=p; j++)
      if (p%j==0)
      {
        D[e++]=j;
        if (j*j!=p)
          D2[e2++]=p/j;
      }
    while (e2>0)
      D[e++]=D2[--e2];
    for (tres=1, i=1; i<e; i++)
      tres*=deg(i,C[D[i]]-C[D[i-1]]), tres%=mod;
    tres*=(deg(e,n-C[p])-deg(e-1,n-C[p])+mod), tres%=mod;
    res+=tres;  
  }
  res%=mod;
  cout<<res<<endl;
  return 0;
}