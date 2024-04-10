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
#define mod (1000003)

using namespace std;

inline char getnext (void)
{
  char ans=0;
  while (ans!='.' && (ans<'1' || ans>'4'))
    ans=getc(stdin);
  return ans;
}

bool Str[510000][2], Stl[510000][2];
int res=1;

int main()
{
  int n, m, i, j;
  char c;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (i=0; i<n; i++)
    for (j=0; j<m; j++)
    {
      c=getnext();
      if (c=='.')
        continue;
      if (c=='1' || c=='2')
        Str[i][j%2]=1;
      else
        Str[i][(j+1)%2]=1;
      if (c=='1' || c=='4')
        Stl[j][i%2]=1;
      else
        Stl[j][(i+1)%2]=1;
    }
  for (i=0; i<n; i++)
  {
    if (Str[i][0] && Str[i][1])
    {
      puts("0");
      return 0;
    }
    if (!(Str[i][0] || Str[i][1]))
    {
      res*=2;
      if (res>=mod)
        res-=mod;
    }
  }
  for (i=0; i<m; i++)
  {
    if (Stl[i][0] && Stl[i][1])
    {
      puts("0");
      return 0;
    }
    if (!(Stl[i][0] || Stl[i][1]))
    {
      res*=2;
      if (res>=mod)
        res-=mod;
    }
  }
  printf("%d\n", res);
  return 0;
}