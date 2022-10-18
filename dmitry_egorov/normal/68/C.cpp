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

//#define M_PI 3.141592653589793238462643
#define eps 1e-8
#define inf ((int)1e9)
#define pb push_back

using namespace std;

int res=inf, cost=0;
int n, m[8][8], M[8][8], c[8][8];
int E[60][2], e, D[8], Le[8];
int F[8][8];

void gen (int ne)
{
  int tmp2=0, i, j;
  if (ne==e)
  {
    for (i=0; i<n; i++)
      for (j=i+1; j<n; j++)
        if (F[i][j]>0)
          tmp2+=c[i][j]+F[i][j]*F[i][j];
    //cerr<<F[0][1]<<" "<<F[0][2]<<" "<<F[1][2]<<endl;
    if (res>-D[n-1] || (res==-D[n-1] && cost<tmp2))
      res=-D[n-1], cost=tmp2;
    return;
  }
  int v1=E[ne][0], v2=E[ne][1];
  for (F[v1][v2]=m[v1][v2], D[v1]+=m[v1][v2], D[v2]-=m[v1][v2]; F[v1][v2]<=M[v1][v2]; F[v1][v2]++, D[v1]++, D[v2]--)
  {
    if (v1>0 && Le[v1]==ne && D[v1]!=0)
    {
      //printf("%d %d %d %d %d %d\n", D[0], D[1], D[2], F[0][1], F[0][2], F[1][2]);
      continue;
    }
    //cerr<<ne<<" "<<F[v1][v2]<<endl;
    gen(ne+1);
  }
  D[v1]-=M[v1][v2]+1;
  D[v2]+=M[v1][v2]+1;
}

int main()
{
  int i, j, v1, v2, x, y, z;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<(n*(n-1))/2; i++)
  {
    scanf("%d%d%d%d%d", &v1, &v2, &x, &y, &z);
    v1--, v2--;
    m[v1][v2]=x, M[v1][v2]=y, c[v1][v2]=z;
  }
  for (i=0; i<n; i++)
  {
    for (j=i+1; j<n; j++)
      E[e][0]=i, E[e][1]=j, e++;
    Le[i]=e-1;
  }
  gen(0);
  if (res==inf)
    printf("-1 -1\n");
  else
    printf("%d %d", res, cost);  
  return 0;
}