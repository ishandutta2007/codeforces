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

int D[2][210000], Q[410000][2], b, e;
char s[2][210000];
int n, k;

void upd (int x, int y, int t)
{
  if (y>=0 && D[x][y]>t && s[x][y]!='X')
    D[x][y]=t, Q[e][0]=x, Q[e++][1]=y;
}

int main()
{
  int i, x, y, j, t;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d ", &n, &k);
  gets(s[0]), gets(s[1]);
  for (i=0; i<2; i++)
    for (j=0; j<210000; j++)
      D[i][j]=inf;
  D[0][0]=0, e=1;
  while (b<e)
  {
    x=Q[b][0], y=Q[b][1], t=D[x][y], b++;
    if (y<t)
      continue;
    if (y>=n)
    {
      puts("YES");
      return 0;
    }
    t++;
    upd(x,y+1,t);
    upd(x,y-1,t);
    upd(1-x,y+k,t);
  }
  puts("NO");
  return 0;
}