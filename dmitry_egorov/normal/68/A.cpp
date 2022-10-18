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

//#define M_PI 3.141592653589793238462643
#define eps 1e-8
#define inf ((int)1e9)
#define pb push_back

using namespace std;

int tmp[4], p[4];
int perm[24][4], e;

void gen (int v)
{
  int i;
  if (v==4)
  {
    for (i=0; i<4; i++)
      perm[e][i]=tmp[i];
    e++;
    return;
  }
  for (i=v; i<4; i++)
  {
    swap(tmp[v],tmp[i]);
    gen(v+1);
    swap(tmp[v],tmp[i]);
  }
}

int main()
{
  int i, j;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  for (i=0; i<4; i++)
    tmp[i]=i;
  gen(0);
  /*for (i=0; i<24; i++)
  {
    for (j=0; j<4; j++)
      printf("%d ", perm[i][j]);
    printf("\n");
  }  */
  for (i=0; i<4; i++)
    scanf("%d", &p[i]);
  int res=0, c, a, b, d, k;
  scanf("%d%d", &a, &b);
  for (i=a; i<=b; i++)
  {
    c=0;
    for (j=0; j<24; j++)
    {
      d=i;
      for (k=0; k<4; k++)
        d%=p[perm[j][k]];
      if (d==i)
        c++;
    }  
    if (c>=7)
      res++;
  }
  printf("%d\n", res);
  return 0;
}