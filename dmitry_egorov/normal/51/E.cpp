#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

//#define M_PI 3.141592653589793238462643
//#define eps 1e-8

using namespace std;

int n, m;
bool A[800][800];
int D[800][800], Deg[800];
long long ans=0;

int main()
{
  int i, v1, v2, j, k;
  //freopen(".in", "r", stdin);
  scanf("%d%d", &n, &m);
  for (i=0; i<m; i++)
  {
    scanf("%d%d", &v1, &v2);
    v1--, v2--;
    A[v1][v2]=A[v2][v1]=1;
    Deg[v1]++, Deg[v2]++;
  }
  for (i=0; i<n; i++)
    for (j=i+1; j<n; j++)
      for (k=0; k<n; k++)
      {
        if (A[i][k] && A[j][k])
          D[i][j]++, D[j][i]++;
      }
  //printf("%d %d %d %d %d\n", D[0][0], A[1][1], A[2][2], A[3][3], A[4][4]);
  //cerr<<ans<<endl;
  for (i=0; i<n; i++)
    for (j=i+1; j<n; j++)
      if (A[i][j])
      {
        for (k=0; k<n; k++)
        {
          //if (i==0 && j==1)
          //  cerr<<k<<" "<<ans<<endl;
          if (i!=k && j!=k)
          {
            if (A[i][k] && A[j][k])
            {
              ans+=(long long)((D[i][k]-1)*(D[j][k]-1));
              continue;
            }
            if (A[i][k])
            {
              ans+=(long long)(D[i][k]*(D[j][k]-1));
              continue;
            }
            if (A[j][k])
            {
              ans+=(long long)((D[i][k]-1)*D[j][k]);
              continue;
            }
            ans+=(long long)(D[i][k]*D[j][k]);
          }
        }
        //cerr<<ans<<endl;
      }
  //printf("%d\n", ans);
  for (i=0; i<n; i++)
    for (j=i+1; j<n; j++)
      for (k=j+1; k<n; k++)
        if (A[i][j] && A[i][k] && A[j][k])
          ans-=(long long)(Deg[i]+Deg[j]+Deg[k]-6ll);  
  printf("%I64d\n", ans/(5ll));
  return 0;
}