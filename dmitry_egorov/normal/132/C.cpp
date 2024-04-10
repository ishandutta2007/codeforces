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

int D[110][60][2], res, l;
char s[200];

int main()
{
  int i, j, k, n;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  gets(s), l=strlen(s);
  scanf("%d", &n);
  for (i=0; i<110; i++)
    for (j=0; j<60; j++)
      for (k=0; k<2; k++)
        D[i][j][k]=-inf;
  for (D[0][0][0]=0, D[0][0][1]=0, i=1; i<=l; i++)
    for (j=0; j<=n; j++)
    {
      if (j!=0)
      {
        (s[i-1]=='F')?(s[i-1]='T'):(s[i-1]='F');
        if (s[i-1]=='T')
          D[i][j][0]=max(D[i][j][0],D[i-1][j-1][1]), D[i][j][1]=max(D[i][j][1],D[i-1][j-1][0]);
        else
        {
          D[i][j][0]=max(D[i][j][0],D[i-1][j-1][0]+1);
          (D[i-1][j-1][1]!=0)?(D[i][j][1]=max(D[i][j][1],D[i-1][j-1][1]-1)):(D[i][j][0]=max(D[i][j][0],1));
        }
        (s[i-1]=='F')?(s[i-1]='T'):(s[i-1]='F');
      }
      if (s[i-1]=='T')
        D[i][j][0]=max(D[i][j][0],D[i-1][j][1]), D[i][j][1]=max(D[i][j][1],D[i-1][j][0]);
      else
      {
        D[i][j][0]=max(D[i][j][0],D[i-1][j][0]+1);
        (D[i-1][j][1]!=0)?(D[i][j][1]=max(D[i][j][1],D[i-1][j][1]-1)):(D[i][j][0]=max(D[i][j][0],1));
      }
    }
  for (i=n; i>=0; i-=2)
    res=max(res,max(D[l][i][0],D[l][i][1]));
  printf("%d\n", res);
  return 0;
}