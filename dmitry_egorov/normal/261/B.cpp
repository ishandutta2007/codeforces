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

long long D[55][105][55];
long double C[55][55], res, F[55];
int A[60];

int main()
{
  int i, p, n, it, j, k, s=0;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d", &A[i]), s+=A[i];
  scanf("%d", &p);
  if (s<=p)
  {
    printf("%.8lf\n", (double)n);
    return 0;
  }
  for (F[0]=1, i=1; i<55; i++)
    F[i]=i*F[i-1];
  for (C[0][0]=1, i=1; i<=n; i++)
    for (C[i][0]=C[i-1][0]/2.0, j=1; j<=i; j++)
      C[i][j]=(C[i-1][j-1]+C[i-1][j])/2.0;
  for (it=0; it<n; swap(A[it],A[0]), it++)
  {
    swap(A[0],A[it]);
    memset(D,0,sizeof(D)), D[0][0][0]=1;
    for (i=1; i<n; i++)
      for (j=0; j<=p; j++)
        for (k=0; k<n; k++)
          D[i][j][k]+=D[i-1][j][k], D[i][j+A[i]][k+1]+=D[i-1][j][k];
    for (i=max(p-A[0]+1,0); i<=p; i++)
      for (j=0; j<n; j++)
      {
      //  if (D[n-1][i][j])
      //    cerr<<it<<" "<<i<<" "<<j<<" "<<D[n-1][i][j]<<endl;
        res+=D[n-1][i][j]*j*F[j]*F[n-1-j];
      }
  //  cerr<<res<<endl;
  }
  res/=F[n];
  printf("%.8lf\n", (double)(res));
  return 0;
}