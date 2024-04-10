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

char s[110][110], str[1100];
int n, m, k;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int X[30], Y[30], SS[1100];

int fdir (int x, int y,  int nx, int ny)
{
  for (int l=0; l<4; l++)
    for (int k=0; k<1100; k++)
      if (x+k*dx[l]==nx && y+k*dy[l]==ny)
        return l;
  assert(0);
}

void move (int x, int y, int xx, int yy)
{
  //cerr<<x<<" "<<y<<"      "<<xx<<" "<<yy<<"        "<<k<<endl;
  int dir=fdir(x,y,xx,yy);
  int st=abs(x-xx)+abs(y-yy);
  while (st>0)
  {
    int t=1;
    if (s[x][y]>='0' && s[x][y]<='9')
      t=(int)(s[x][y]-'0');
    if (k<t)
    {
      printf("%d %d\n", x, y);
      exit(0);
    }
    x+=dx[dir], y+=dy[dir], k-=t, st--;
  }
}

int main()
{
  int i, id, j, len, sx, sy, fx, fy;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d%d ", &n, &m, &k);
  for (i=0; i<n; i++)
    gets(s[i+1]+1);
  for (i=1; i<=n; i++)
    for (j=1; j<=m; j++)
      if (s[i][j]>='a' && s[i][j]<='z')
      {
        id=(int)(s[i][j]-'a'), X[id]=i, Y[id]=j;
        /*for (l=0; l<4; l++)
        {
          x=i+dx[l], y=j+dy[l];
          while (s[x][y]>='0' && s[x][y]<='9')
            x+=sx[l], y+=dy[l];
          if (s[x][y]>='a' && s[x][y]<='z')
            N[id][l]=((int)(s[x][y]-'a'));
        } */
      }
  scanf("%d%d %s %d%d", &sx, &sy, str, &fx, &fy), len=strlen(str); 
  for (i=0; i<len; i++)
    SS[i]=(int)(str[i]-'a');
  move(sx,sy,X[SS[0]],Y[SS[0]]);
  for (i=0; i<len-1; i++)
    move(X[SS[i]],Y[SS[i]],X[SS[i+1]],Y[SS[i+1]]);
  move(X[SS[len-1]],Y[SS[len-1]],fx,fy);
  printf("%d %d\n", fx, fy);  
  return 0;
}