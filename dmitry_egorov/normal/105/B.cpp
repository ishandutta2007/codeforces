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

int K[10], n, L[10], Lv[10], a;
long double res;

void gen (int st, int col)
{
  //cerr<<st<<" "<<col<<endl;
  if (st!=n-1)
  {
    for (int i=0; i<=col; i++)
    {
      K[st]=i;
      gen(st+1,col-i);
    }
    return;
  }
  int p, j, cnt, cnt2;
  long double v, tres;
  K[st]=col, tres=0.0;
  for (p=0; p<(1<<n); p++)
  {
    v=1.0;
    for (j=0, cnt=0, cnt2=0; j<n; j++)
    {
      if (p&(1<<j))
        v*=(long double)(min(1.0,((double)(L[j]+K[j]))/10.0)), cnt++;
      else
        v*=(long double)(max(0.0,((double)(10.0-L[j]-K[j])/10.0))), cnt2+=Lv[j];
    }
    //cerr<<v<<endl;
    if (2*cnt>n)
      continue;
    //cerr<<v<<" "<<cnt2<<" "<<a<<endl;
    tres+=(v*((long double)cnt2))/((long double)(cnt2+a));
  }

  res=max(res,((long double)1.0)-tres);
  //cerr<<res<<endl;
}

int main()
{
  int i, k;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d%d", &n, &k, &a);
  //cerr<<"!!!!"<<endl;
  for (i=0; i<n; i++)
  {
    //cerr<<i<<endl;
    scanf("%d%d", &Lv[i], &L[i]);
    L[i]/=10;
  }
  gen(0,k);
  printf("%.8lf\n", (double)res);
  return 0;
}