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

int n, m, res;
char s[1100][1100];
int C[1100][1100], cc=1, cntc, stx, sty, cntc2, nx, ny;
int dx[8]={-1,0,1,1,1,0,-1,-1};
int dy[8]={-1,-1,-1,0,1,1,1,0};
int dx2[4]={0,0,-1,1};
int dy2[4]={1,-1,0,0};
int min0, min1;

void dfs (int x, int y)
{
  min0=min(min0,x);
  //cerr<<x<<" "<<y<<endl;
  int xx, yy;
  C[x][y]=cc;
  for (int i=0; i<8; i++)
  {
    xx=x+dx[i], yy=y+dy[i];
    if (s[xx][yy]=='1' && C[xx][yy]!=cc)
      C[xx][yy]=cc, cntc++, stx=xx, sty=yy;
    if (s[xx][yy]=='0' && C[xx][yy]==0)
      dfs(xx,yy);
  }
}

void dfs2 (int x, int y)
{
  //cerr<<x<<" "<<y<<endl;
  min1=min(x,min1);
  int i, ncnt=0, xx, yy;
  C[x][y]=cc+1, cntc2++;
  for (i=0; i<4; i++)
  {
    xx=x+dx2[i], yy=y+dy2[i];
    if (C[xx][yy]==cc && s[xx][yy]=='1')
    {
      ncnt++;
      if (x==stx && y==sty)
        nx=xx, ny=yy;
      dfs2(xx,yy);
      continue;
    }
    if (C[xx][yy]==cc+1 && s[xx][yy]=='1')
      ncnt++;
  }
  //cerr<<x<<" "<<y<<" "<<ncnt<<endl;
  if (ncnt!=2)
    cntc2=-inf;
}

int main()
{
  int i, j;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d ", &n, &m);
  for (i=1; i<=n; i++)
    gets(s[i]+1);
  for (i=1; i<n; i++)
    for (j=1; j<m; j++)
      if (s[i][j]=='1' && s[i+1][j]=='1' && s[i][j+1]=='1' && s[i+1][j+1]=='1')
        res=4;
  for (i=1; i<=n; i++)
    for (j=1; j<=m; j++)
      if (C[i][j]==0 && s[i][j]=='0')
      {
        min0=inf, min1=inf;
        dfs(i,j);
        /*cerr<<C[1][1]<<C[1][2]<<C[1][3]<<endl;
        cerr<<C[2][1]<<C[2][2]<<C[2][3]<<endl;
        cerr<<C[3][1]<<C[3][2]<<C[3][3]<<endl;  */
        dfs2(stx,sty);
        //cerr<<cntc<<" "<<cntc2<<" "<<stx<<" "<<sty<<endl;
        if (cntc==cntc2 && min0>min1)
          res=max(res,cntc);
        cc+=3, cntc=0, cntc2=0;
      }
  printf("%d\n", res);
  return 0;
}