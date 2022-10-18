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

int D[160][160];
char F[160][180];
int L[160][2];

int main()
{
  int i, j, n, m;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (i=0; i<n; i++)
    for (j=0; j<m; j++)
      scanf(" %c", &F[i+5][j+5]);
  for (i=0; i<160; i++)
    for (j=0; j<160; j++)
      D[i][j]=inf;
  D[5][5]=0;
  for (i=5; i<n+5; i++)
  {
    for (j=5; j<m+5; j++)
      if (F[i][j]=='W')
        L[i][1]=j;
    for (L[i][0]=158, j=m+4; j>=5; j--)
      if (F[i][j]=='W')
        L[i][0]=j;
  } 
  for (i=5; i<n+5; i++)
  {
    if (i%2==1)
      for (j=5; j<m+5; j++)
      {
        D[i][j]=min(D[i][j],D[i][j-1]+1);
        if (L[i][0]>=j && L[i-1][0]>=j)
          D[i][j]=min(D[i][j],D[i-1][j]+1);
      }
    else
      for (j=m+4; j>=5; j--)
      {
        D[i][j]=min(D[i][j],D[i][j+1]+1);
        if (L[i][1]<=j && L[i-1][1]<=j)
          D[i][j]=min(D[i][j],D[i-1][j]+1);
      }
  }
  /*for (i=2; i<=n+7; i++)
  {
    for (j=2; j<=m+7; j++)
      cerr<<D[i][j]<<" ";
    cerr<<endl;
  }     */
  for (i=n+4; i>=5; i--)
  {
    if (i%2==1)
      for (j=m+4; j>=5; j--)
      {
        //cerr<<i<<" "<<j<<endl;
        if (F[i][j]=='W')
        {
          //cerr<<i<<" !!!! "<<j<<endl;
          printf("%d\n", D[i][j]);
          return 0;
        }
      } 
    else
      for (j=5; j<m+5; j++)
      {
        if (F[i][j]=='W')
        {
          //cerr<<i<<" SYG! "<<j<<endl;
          printf("%d\n", D[i][j]);
          return 0;
        }  
      }
  }
  puts("0");
  return 0;
}