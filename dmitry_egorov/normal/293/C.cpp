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

long long n, Pr[40];
int Deg[40], e, res;
vector <long long> V;

void gen (long long d, int v)
{
  if (d>(n+d-1)/d)
    return;
  if (v==e)
  {
    V.pb(d);
    return;
  }
  for (int i=0; i<=Deg[v]; i++, d*=Pr[v])
    gen(d,v+1);
}

int main()
{
  int i, j;
  long long nn, v1, v2, v3, a, b, c;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%I64d", &n);
  if (n%3!=0)
  {
    puts("0");
    return 0;
  }
  n/=3, nn=n;
  for (i=2; i*1ll*i<=n; i++)
    if (n%i==0)
    {
      Pr[e++]=i;
      while (n%i==0)
        n/=i, Deg[e-1]++;
    } 
  if (n>1)
    Pr[e]=n, Deg[e++]=1;
  n=nn, gen(1,0), e=V.size();
  sort(V.begin(),V.end());
  for (i=0; i<e; i++)
    for (v1=V[i], j=i; j<e; j++)
    {
      v2=V[j];
      if (v2>(n+v1-1)/v1)
        break;
      v3=v1*v2;
      if (n%v3!=0)
        continue;
      v3=n/v3;
      if (v3<v2)
        break;
      a=(v3+v2-v1), b=(v3+v1-v2), c=(v1+v2-v3);
      if (c<=0)
        continue;
      if ((a&1) || (b&1) || (c&1))
        continue;
      //res++;
      if (a==c)
      {
        res++;
        continue;
      }
      if (a==b || b==c)
      {
        res+=3;
        continue;
      }
      res+=6;
    }
  printf("%d\n", res);
  return 0;
}