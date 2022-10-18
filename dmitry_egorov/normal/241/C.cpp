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

int res, n, S[110];
long long A[110], B[110], hl, hr;
char Tp[110];
int T[2][110000];
bool u[110];

void solve ()
{
  int i, j, st, cs, id;
  long long dx, dy, cy, cx;
  bool fl;
  memset(T,-1,sizeof(T));
  for (i=0; i<n; i++)
  {
    if (Tp[i]=='F')
      for (j=A[i]; j<B[i]; j++)
        T[1][j]=i; 
    else
      for (j=A[i]; j<B[i]; j++)
        T[0][j]=i; 
  }
  for (st=1; st<=n; res=max(res,cs), st++)
  {
    memset(u,0,sizeof(u));
    dx=100000ll, dy=hl+(st-1)*100ll+((st&1)?(hr):(100ll-hr));
    cy=hl, cs=0, fl=1;
    for (j=1; j<=st; cy+=100ll, j++)
    {
      cx=(cy*dx)/dy;
      //cerr<<st<<" "<<cx<<"        "<<res<<endl;
      if ((cy*dx)%dy!=0)
      {
        id=T[j&1][cx];
        if (id==-1 || u[id])
          fl=0;
        else
          cs+=S[id], u[id]=1;
      }
      else
      {
        id=max(T[j&1][cx],T[j&1][cx-1]);
        if (id==-1 || u[id])
          fl=0;
        else
          cs+=S[id], u[id]=1;
      } 
    }
    if (!fl)
      cs=0;
  }
}

int main()
{
  int i;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%I64d%I64d%d", &hl, &hr, &n);
  for (i=0; i<n; i++)
    scanf("%d %c%I64d%I64d", &S[i], &Tp[i], &A[i], &B[i]); 
  solve();
  for (i=0; i<n; i++)
    (Tp[i]=='F')?(Tp[i]='T'):(Tp[i]='F');
  hl=100-hl, hr=100-hr;
  solve();
  printf("%d\n", res);
  return 0;
}