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

char s[1550][1550];
int n, m, cc, u[1550][1550];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
vector <pair <int, int> > G[6100];
int Wx[6100], Wy[6100];
bool u2[6100];

void dfs (int x, int y)
{
  u[x][y]=cc;
  int nx, ny;
  for (int i=0; i<4; i++)
  {
    nx=x+dx[i], ny=y+dy[i];
    if (u[nx][ny]==0 && s[nx][ny]=='.')
      dfs(nx,ny);
  }
}

void dfs2 (int v)
{
  u2[v]=1;
  int nv, nx, ny;
  for (int i=0; i<(int)G[v].size(); i++)
  {
    nv=G[v][i].first, nx=Wx[v]+dx[G[v][i].second], ny=Wy[v]+dy[G[v][i].second];
    if (u2[nv] && (Wx[nv]!=nx || Wy[nv]!=ny))
    {
      puts("Yes");
      exit(0);
    }
    if (!u2[nv])
      Wx[nv]=nx, Wy[nv]=ny, dfs2(nv);
  }
}

int main()
{
  int i, j, sx=-1, sy=-1;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d ", &n, &m);
  for (i=1; i<=n; i++)
    gets(s[i]+1);
  for (i=1; i<=n; i++)
    for (j=1; j<=m; j++)
      if (s[i][j]=='S')
        s[i][j]='.', sx=i, sy=j;
  for (i=1; i<=n; i++)
    for (j=1; j<=m; j++)
      if ((i==1 || i==n || j==1 || j==m) && s[i][j]=='.' && u[i][j]==0)
        cc++, dfs(i,j);
  if (u[sx][sy]==0)
  {
    puts("No");
    return 0;
  }     
  for (i=1; i<=m; i++)
    if (s[1][i]=='.' && s[n][i]=='.')
      G[u[1][i]].pb(mp(u[n][i],0)), G[u[n][i]].pb(mp(u[1][i],1));
  for (i=1; i<=n; i++)
    if (s[i][1]=='.' && s[i][m]=='.')
      G[u[i][1]].pb(mp(u[i][m],2)), G[u[i][m]].pb(mp(u[i][1],3));
  dfs2(u[sx][sy]);
  puts("No");
  return 0;
}