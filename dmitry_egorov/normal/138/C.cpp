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

struct segm
{
  int id, x;
  long double p; 
  segm ()
  {
    id=-1, x=0, p=0.0;
  }
  segm (int _x, int _id, long double _p)
  {
    id=_id, x=_x, p=_p;
  }
};

bool operator < (segm i, segm j)
{
  if (i.x!=j.x)
    return i.x<j.x;
  return i.id<j.id;
}

long double P[(1<<18)+100];
vector <segm> V;
pair<int, long double> W[11000];
long double res;

void add (int v, long double p)
{
  v+=(1<<17), P[v]=p, v/=2;
  while (v>0)
    P[v]=P[2*v]*P[2*v+1], v/=2;
}

int main()
{
  int n, m, i, x, h, il, ir, j;
  double l, r;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (i=0; i<n; i++)
  {
    scanf("%d%d%d%d", &x, &h, &il, &ir), 
    l=((double)il)/100.0, r=((double)ir)/100.0;
    V.pb(segm(x-h,i,1.0-l)), V.pb(segm(x,i,1.0));
    V.pb(segm(x+1,i,1.0-r)), V.pb(segm(x+h+1,i,1.0));
  }
  for (i=1; i<(1<<18); i++)
    P[i]=1.0;
  sort(V.begin(),V.end());
  for (i=0; i<m; i++)
    scanf("%d%d", &x, &h), W[i]=mp(x,h);
  sort(W,W+m);
  for (i=0, j=0; j<m; )
  {
    while (j<m && (i==(int)V.size() || W[j].first<V[i].x))
      res+=W[j].second*P[1], j++;
    if (i!=(int)V.size())
      add(V[i].id,V[i].p), i++;
  }
  printf("%.8lf\n", (double)res);
  return 0;
}