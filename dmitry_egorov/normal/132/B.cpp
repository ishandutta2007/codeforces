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

char s[60][60];
int D[60][60][3][3][3], x=1, y=1, dpx, dpy=1, cp=-1;

int main()
{
  int mx, my, i, j, n, m, st;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d ", &n, &st);
  gets(s[1]+1), m=strlen(s[1]+1);
  for (i=2; i<=n; i++)
    gets(s[i]+1);
  for (i=0; i<=n+1; i++)
    for (j=0; j<=m+1; j++)
      if (i==0 || i==n+1 || j==0 || j==m+1)
        s[i][j]='0';
  while (st>0)
  {
    //cerr<<st<<" "<<x<<" "<<y<<endl;
    while (s[x+dpx][y+dpy]==s[x][y])
      x+=dpx, y+=dpy;
    if (cp==-1)
      mx=-dpy, my=dpx;
    else
      mx=dpy, my=-dpx;
    while (s[x+mx][y+my]==s[x][y])
      x+=mx, y+=my;
    if (s[x+dpx][y+dpy]!='0')
    {
      x+=dpx, y+=dpy, st--;
      if (D[x][y][dpx+1][dpy+1][cp+1]>0)
        st%=(D[x][y][dpx+1][dpy+1][cp+1]-st);
      D[x][y][dpx+1][dpy+1][cp+1]=st;
      continue;
    }
    if (cp==-1)
    {
      cp=1, st--;
      if (D[x][y][dpx+1][dpy+1][cp+1]>0)
        st%=(D[x][y][dpx+1][dpy+1][cp+1]-st);
      D[x][y][dpx+1][dpy+1][cp+1]=st;
      continue;
    }
    cp=-1, mx=dpx, my=dpy, dpx=my, dpy=-mx, st--;
    if (D[x][y][dpx+1][dpy+1][cp+1]>0)
      st%=(D[x][y][dpx+1][dpy+1][cp+1]-st);
    D[x][y][dpx+1][dpy+1][cp+1]=st;
  }
  printf("%c\n", s[x][y]);
  return 0;
}