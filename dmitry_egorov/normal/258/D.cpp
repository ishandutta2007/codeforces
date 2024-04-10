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

long double C[1010][1010], P[1010][1010];
long double res;
int A[1100];

int main()
{
  int a, b, i, j, n, m, it;
  long double aa, bb;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (i=0; i<n; i++)
    scanf("%d", &A[i]), A[i]--;
  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      if (A[min(i,j)]>A[max(i,j)])
        C[i][j]=1;

 /* for (i=0; i<n; cerr<<endl, i++)
    for (j=0; j<n; j++)
      cerr<<C[i][j]<<" ";

      cerr<<endl;          */




  for (it=0; it<m; it++)
  {
    scanf("%d%d", &a, &b), a--, b--;
    C[a][b]=0.5, C[b][a]=0.5;
    if (a>b)
      swap(a,b);
    for (j=0; j<a; j++)
        C[a][j]=(C[a][j]+C[b][j])/2, C[b][j]=C[a][j], C[j][a]=C[a][j], C[j][b]=C[b][j];
    for (j=a+1; j<b; j++)
    {
        aa=C[a][j], bb=C[b][j];
        C[a][j]=(aa+1.0-bb)/2, C[b][j]=(bb+1.0-aa)/2, C[j][a]=C[a][j], C[j][b]=C[b][j];
    }
    for (j=b+1; j<n; j++)
      if (j!=a && j!=b)
        C[a][j]=(C[a][j]+C[b][j])/2, C[b][j]=C[a][j], C[j][a]=C[a][j], C[j][b]=C[b][j];



  }

  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      res+=C[i][j];
  printf("%.8lf\n", (double)(res/2.0));
  return 0;
}