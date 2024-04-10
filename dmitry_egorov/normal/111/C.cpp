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

int D[(1<<6)][(1<<6)], D2[(1<<6)][(1<<6)];
int C[(1<<6)];
bool u[10];

int main()
{
  int n, m, i, j, p, p2, ans, st, cnt;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &m);
  if (n>m)
    swap(n,m);
  if (n==1)
  {
    printf("%d\n", m-((m+2)/3));
    return 0;
  }
  for (i=1; i<(1<<n); i++)
    C[i]=C[i/2]+(i%2);
  for (i=0; i<(1<<n); i++)
    for (D[0][i]=C[i], j=1; j<(1<<n); j++)
      D[j][i]=inf;
  for (st=0; st<m; st++)
  {
    memcpy(D2,D,sizeof(D2));
    for (j=0; j<(1<<n); j++)
      for (i=0; i<(1<<n); i++)
        D[j][i]=inf;
    for (p2=0; p2<(1<<n); p2++)
      for (p=0; p<(1<<n); p++)
      {
        //cout<<st<<" "<<p<<" "<<p2<<" "<<D2[p2][p]<<endl;
        for (i=0; i<(1<<n); i++)
        {
          cnt=D2[p2][p]+C[i];
          memset(u,0,sizeof(u));
          for (j=0; j<n; j++)
            if (p&(1<<j))
              u[j+1]=1;
          bool fl=1;
          for (j=0; j<n; j++)
            if ((!u[j]) && (!u[j+1]) && (!u[j+2]) && (!(p2&(1<<j))) && (!(i&(1<<j))))
            {
              fl=0;
              break;
            }
          //if (st==0 && p==0 && i==0)
          //  cerr<<p2<<" "<<cnt<<endl;
          if (fl)
            D[p][i]=min(D[p][i],cnt);
        }
      }
  }
  for (ans=inf, i=0; i<(1<<n); i++)
    ans=min(ans,D[i][0]);
  printf("%d\n", n*m-ans);   
  return 0;
}