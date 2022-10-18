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

map <int,double> w;
map <int,double> trw;
double ans, M;
int h;

double gen (int v, int st)
{
  double wv=w[v];
  if (st==h)
    return max(wv,M);
  if (wv<=M)
    return M;
  double res=0.0;
  double wv2=w[2*v], trwv=trw[v], wv21=w[2*v+1];
  if (wv2>=wv21)
  {
    res=max(M,wv2+trwv)/2.0;
    M=max(M,wv21+trwv);
    res+=gen(2*v,st+1)/2.0;
  }
  else
  {
    res=max(M,wv21+trwv)/2.0;
    M=max(M,wv2+trwv);
    res+=gen(2*v+1,st+1)/2.0;
  }
  return res;
}

int main()
{
  char s[10];
  int q, i, v;
  double e; //tt=clock();
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &h, &q);
  for (i=0; i<q; i++)
  {
    scanf(" %s", &s);
    if (s[0]=='d')
    {
      printf("%.6lf\n", ans);
      continue;
    }
    scanf("%d%lf", &v, &e);
    trw[v]+=e;
    while (v>0)
    {
      if (w.count(v)==0)
        w[v]=e;
      else
        w[v]+=e;
      v/=2;
    }
    M=0.0;
    ans=gen(1,0);
  }
  //cerr<<((clock()-tt)/CLOCKS_PER_SEC)<<endl;
  return 0;
}