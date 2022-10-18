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

int D[310][310], D2[310][310], A[310][310];

int main()
{
  int i, j, k, t, l, x1, x2, mx=0, Mx=0, nmx, nMx;
  int n, tmp;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      scanf("%d", &A[i][j]);
  for (i=0; i<310; i++)
    for (j=0; j<310; j++)
      D[i][j]=-inf, D2[i][j]=-inf;
  D[0][0]=A[0][0];
  for (i=0; i<2*n-2; i++)
  {
    nmx=max(0,i-n+2), nMx=min(n-1,i+1);
   /* cerr<<i<<"   !!!!!   "<<mx<<" "<<Mx<<endl;
    for (k=mx; k<=Mx; k++)
      for (j=k; j<=Mx; j++)
        cerr<<k<<" "<<j<<"         "<<D[k][j]<<endl;
    cerr<<nmx<<" "<<nMx<<endl;
    cerr<<endl<<endl<<endl;  */
    for (j=mx; j<=Mx; j++)
      for (k=j; k<=Mx; k++)
      {
        for (t=0; t<2; t++)
          for (l=0; l<2; l++)
          {
            x1=j+t, x2=k+l;
            if (x1>x2 || x1<nmx || x2>nMx)
              continue;
            tmp=A[x1][i+1-x1]+A[x2][i+1-x2];
            if (x1==x2)
              tmp-=A[x1][i+1-x1];
            //cerr<<"???  "<<x1<<" "<<x2<<"              "<<endl;
            D2[x1][x2]=max(D2[x1][x2],D[j][k]+tmp);
          }
        D[j][k]=-inf;
      }
    mx=nmx, Mx=nMx;
    for (k=mx; k<=Mx; k++)
      for (j=k; j<=Mx; j++)
        D[k][j]=D2[k][j], D2[k][j]=-inf;
  }
  printf("%d\n", D[n-1][n-1]);
  return 0;
}