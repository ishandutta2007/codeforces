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

int res, tmp, P[20][110][3];
pair <int, int> V[110];
char s[1100];

int main()
{
  int i, j, k, c, cl, n, m;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d%d", &n, &m, &c);
  for (i=0; i<n; i++)
    for (scanf(" %s", s), j=0; j<m; j++)
      for (k=0; k<3; k++)
        scanf("%d", &P[i][j][k]);
  for (i=0; i<n; i++)
    for (j=0; j<n; j++, res=max(res,tmp))
    {
      tmp=0;
      for (k=0; k<m; k++)
        V[k]=mp(-max(0,P[j][k][1]-P[i][k][0]),P[i][k][2]);
      sort(V,V+m), cl=c;
      for (k=0; k<m; k++)
        tmp-=min(cl,V[k].second)*V[k].first, cl-=min(cl,V[k].second);
    }
  printf("%d\n", res);
  return 0;
}