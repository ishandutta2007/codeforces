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

using namespace std;

long long m, A[60][2][2], R[2][2], T[2][2];

long long fn (long long l, long long r, long long k)
{
  long long res=min((r-l-1ll)/(k-1ll),(r-1ll)/k);
  r--, l--;
  long long t;
  //cerr<<res<<" "<<l<<" "<<r<<endl;
  while (r/res-l/res<k)
  {
    if (res<(long long)2e6)
      res--;
    else 
      t=r/res, t++, res=r/t;
  }
  return res;
}

int main()
{
  int i, j, k, t;
  long long l, r, kk;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  cin>>m>>l>>r>>kk;
  r++, R[0][0]=1%m, R[1][1]=1%m, A[0][0][0]=1%m, A[0][0][1]=1%m, A[0][1][0]=1%m;
  for (i=1; i<60; i++)
    for (j=0; j<2; j++)
      for (k=0; k<2; k++)
        for (t=0; t<2; t++)
          A[i][j][k]+=A[i-1][j][t]*A[i-1][t][k], A[i][j][k]%=m;
  long long n=fn(l,r,kk);
  n--;
  //cerr<<n<<endl;
  for (i=0; i<60;i++)
    if (n&(1ll<<i))
    {
      for (j=0; j<2; j++)
        for (k=0; k<2; k++)
          for (t=0; t<2; t++)
            T[j][k]+=R[j][t]*A[i][t][k], T[j][k]%=m;
      memcpy(R,T,sizeof(T));
      memset(T,0,sizeof(T));
    }        
  printf("%I64d\n", R[0][0]);
  return 0;
}