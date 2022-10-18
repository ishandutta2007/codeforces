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

struct point 
{
  int x, y;
}A[8];

int ID[24][4], T[4];
vector <int> V, W;

int dist (point a, point b)
{
  return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

bool mul (point a, point b, point c)
{
  return (b.x-a.x)*(c.x-b.x)+(b.y-a.y)*(c.y-b.y)==0;
}

bool rec (point a, point b, point c, point d)
{
  return (dist(a,b)==dist(c,d) && dist(a,d)==dist(b,c) && mul(a,b,c) && mul(b,c,d) && mul(c,d,a) && mul(d,a,b));
}

bool sq (point a, point b, point c, point d)
{
  return (rec(a,b,c,d) && dist(a,b)==dist(b,c));
}

int main()
{
  int i, j, mask;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  for (i=0; i<8; i++)
    scanf("%d%d", &A[i].x, &A[i].y);
  for (i=0; i<4; i++)
    T[i]=i;
  for (i=0; i<24; i++)
  {
    for (j=0; j<4; j++)
      ID[i][j]=T[j];
    if (i!=23)
      next_permutation(T,T+4);
  }
  for (mask=0; mask<(1<<8); mask++)
  {
    V.clear(), W.clear();
    for (j=0; j<8; j++)
    {
      if (mask&(1<<j))
        V.pb(j);
      else
        W.pb(j);
    }
    if ((int)V.size()!=4)
      continue;
    for (i=0; i<24; i++)
      if (sq(A[V[ID[i][0]]],A[V[ID[i][1]]],A[V[ID[i][2]]],A[V[ID[i][3]]]))
        break;
    for (j=0; j<24; j++)
      if (rec(A[W[ID[j][0]]],A[W[ID[j][1]]],A[W[ID[j][2]]],A[W[ID[j][3]]]))
        break;
    if (i==24 || j==24)
      continue;
    puts("YES");
    for (i=0; i<4; i++)
      printf("%d ", V[i]+1);
    printf("\n");
    for (i=0; i<4; i++)
      printf("%d ", W[i]+1);
    printf("\n");
    return 0;
  }
  puts("NO");
  return 0;
}