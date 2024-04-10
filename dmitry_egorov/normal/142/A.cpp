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
#define inf ((long long)1e18)
#define pb push_back
#define mp make_pair

using namespace std;

long long resm=inf, resM;
vector <int> W;
vector <long long> V;

void gen (int v, long long a, long long b, long long c)
{
  if (v==(int)V.size())
  {
    long long t=(a+1ll)*(b+2ll)*(c+2ll)-a*b*c;
    resm=min(resm,t), resM=max(resM,t);
    return;
  }
  int i, j;
  vector <long long> Deg;
  Deg.clear(), Deg.pb(1);
  for (i=1; i<=W[v]; i++)
    Deg.pb(Deg.back()*V[v]);
  for (i=0; i<=W[v]; i++)
    for (j=0; j+i<=W[v]; j++)
      gen(v+1,a*Deg[i],b*Deg[j],c*Deg[W[v]-i-j]); 
}

int main()
{
  int a, i, t;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &a);
  for (i=2; i*i<=a; i++)
    if (a%i==0)
    {
      V.pb(i), t=1, a/=i;
      while (a%i==0)
        a/=i, t++;
      W.pb(t);
    }
  if (a!=1)
    V.pb(a), W.pb(1);
  gen(0,1,1,1);
  printf("%I64d %I64d\n", resm, resM);
  return 0;
}