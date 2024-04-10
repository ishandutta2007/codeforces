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

int n, m;
int res=inf, A[110][11000];
char s[110000];

int main()
{
  int i, j, ct, c, tmp;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d ", &n, &m);
  for (i=0; i<n; i++)
    for (j=0; j<m; j++)
      A[i][j]=inf;
  for (i=0; i<n; i++)
  {
    gets(s);
    for (j=0; j<m; j++)
      if (s[j]=='1')
      {
        A[i][j]=0;
        c=(j+1)%m, ct=1; 
        while (s[c]!='1')
          A[i][c]=min(A[i][c],ct), ct++, c=(c+1)%m;
        c=(j+m-1)%m, ct=1; 
        while (s[c]!='1')
          A[i][c]=min(A[i][c],ct), ct++, c=(c+m-1)%m;
      } 
  }
  for (i=0; i<m; i++, res=min(res,tmp))
    for (tmp=0, j=0; j<n; j++)
      tmp+=A[j][i], tmp=min(tmp,inf);
  (res==inf)?(puts("-1")):(printf("%d\n", res));
  return 0;
}