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

int Res[1100000], ans;
int X[300], Y[300];

inline long long get (int id, int dx, int dy)
{
  if (Y[id]%dy!=0)
    return -1ll;
  return ((long long)X[id])-((Y[id]/dy)*1ll*dx);
}

int main()
{
  long long nx;
  int n, m, dx, dy, d, i, j, k, tmp;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (i=0; i<m; i++)
    scanf("%d%d", &X[i], &Y[i]);
  for (i=0; i<m; i++)
    for (j=i+1; j<m; j++)
    {
      if (Y[i]==Y[j])
        continue;
      dy=Y[j]-Y[i], dx=X[j]-X[i];
      if (dx==0)
        d=dy;
      else
        d=__gcd(abs(dx),abs(dy));
      dy/=d, dx/=d;
      if (dy<0)
        dy*=-1, dx*=-1;
      nx=get(i,dx,dy);
      long long tnx=nx;
      if (nx<=0 || nx>n)
        continue;
      for (tmp=2, k=j+1; k<m; k++)
      {
        nx=get(k,dx,dy);
        if (tnx==nx)
          tmp++;
      }
      Res[tnx]=max(Res[tnx],tmp);
    }
  for (i=1; i<=n; i++)
    ans+=max(Res[i],1);// cerr<<Res[i]<<endl;
  printf("%d\n", ans);
  return 0;
}