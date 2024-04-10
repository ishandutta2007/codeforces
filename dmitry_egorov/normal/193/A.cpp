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

char s[60][60];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int u[60][60], t, cnt;

void dfs (int x, int y)
{
  u[x][y]=t;
  for (int i=0; i<4; i++)
    if (u[x+dx[i]][y+dy[i]]==0 && s[x+dx[i]][y+dy[i]]=='#')
      dfs(x+dx[i],y+dy[i]);
}

int main()
{
  int n, m, i, j, k, l;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d ", &n, &m);
  for (i=1; i<=n; i++)
    gets(s[i]+1);
  for (i=1; i<=n; i++)
    for (j=1; j<=m; j++)
      if (s[i][j]=='#')
        cnt++;
  if (cnt<=2)
  {
    puts("-1");
    return 0;
  }
  for (i=1; i<=n; i++)
    for (j=1; j<=m; j++)
      if (s[i][j]=='#')
      {
        s[i][j]=0;
        memset(u,0,sizeof(u)), t=1;
        for (k=1; k<=n; k++)
          for (l=1; l<=m; l++)
            if (s[k][l]=='#' && u[k][l]==0)
              dfs(k,l), t++;
        if (t>2)
        {
          puts("1");
          return 0;
        }
        s[i][j]='#';
      }
  puts("2");
  return 0;
}