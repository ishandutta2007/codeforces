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

int D[110][110], n, m, q, E[110];
vector <int> A[110][110];
int Res[110];
vector <int> M[110];
int CM[110][110];

int main()
{
  int i, j, v, nv, l, k, a, b, q, v1, v2;
  bool fl=1;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d%d%d", &n, &m, &a, &b), a--, b--;
  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      if (i!=j)
        D[i][j]=inf;
  for (i=0; i<m; i++)
    scanf("%d%d", &v1, &v2), v1--, v2--, D[v1][v2]=1;
  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      for (k=0; k<n; k++)
        D[j][k]=min(D[j][k],D[j][i]+D[i][k]);
  scanf("%d", &q);
  for (i=0; i<q; i++)
  {
    scanf("%d%d", &v1, &v2), v1--, v2--; 
    if (D[v1][v2]==inf)
    {
      q--, i--;
      continue;
    }
    for (E[i]=D[v1][v2], j=0; j<n; j++)
      if (D[v1][v2]==D[v1][j]+D[j][v2]) 
        A[i][D[v1][j]].pb(j);
    for (j=0; j<=D[v1][v2]; j++)
      if ((int)A[i][j].size()==1)
        M[A[i][j][0]].pb(i);
    //cerr<<A[i][0].size()<<" "<<A[i][0][0]<<endl;
  }
  for (i=0; i<n; i++)
    Res[i]=inf;// cerr<<i<<" "<<M[i].size()<<endl;
  Res[b]=0;
  while (fl) 
  {
    fl=0;
    for (i=0; i<q; i++)
      for (j=E[i]; j>=0; j--)
        for (k=0; k<(int)A[i][j].size(); CM[i][v]=min(((l!=0)?(CM[i][v]):(inf)),Res[v]), k++)
          for (v=A[i][j][k], CM[i][v]=0, l=0; l<(int)A[i][j+1].size(); l++)
          {
            nv=A[i][j+1][l];
            if (D[v][nv]==1)
              CM[i][v]=max(CM[i][v],CM[i][nv]); 
          }
    for (i=0; i<n; i++)
      for (j=0; j<(int)M[i].size(); j++)
        if (Res[i]>CM[M[i][j]][i]+1)
          fl=1, Res[i]=CM[M[i][j]][i]+1;
  }
  (Res[a]>inf/2)?(puts("-1")):(printf("%d\n", Res[a]));
  return 0;
}