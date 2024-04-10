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

long long F[110][110];

long long go (int p, int d, long long len)
{
  if (d<0)
    return 0;
  if (len==0)
    return 0;
  if (p==0)
    return F[p][d];
  if (len<(1ll<<(p-1)))
    return go(p-1,d,len);
  return F[p-1][d]+go(p-1,d-1,len-(1ll<<(p-1)));
}

int main()
{
  int d, i, j;
  long long res=0;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  for (F[0][0]=1, i=0; i<80; i++)
    for (j=0; j<70; j++)
      F[i+1][j]+=F[i][j], F[i+1][j+1]+=F[i][j];
  long long n, t;
  cin>>n>>t;
  for (d=0; d<60; d++)
    if ((1ll<<d)==t)
      break;
  if (d>58)
  {
    puts("0");
    return 0;
  }
  for (i=1; ; i++)
  {
    if (n<(1ll<<i))
    {
      res+=go(i,d,n);
      break;
    }
    res+=F[i][d], n-=(1ll<<i);
  }
  cout<<res<<endl;
  return 0;
}