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

int Snm[110000], Sz[110000];

bool isluck (int a)
{
  while (a>0)
  {
    if ((a%10)!=4 && (a%10)!=7)
      return 0;
    a/=10ll;
  }
  return 1;
}

int SNM (int a)
{
  if (Snm[a]==a)
    return a;
  Snm[a]=SNM(Snm[a]);
  return Snm[a];
}

void join (int a, int b)
{
  a=SNM(a), b=SNM(b);
  if (a!=b)
  {
    if (Sz[a]>Sz[b])
      Sz[a]+=Sz[b], Snm[b]=a;
    else
      Sz[b]+=Sz[a], Snm[a]=b;
  }
}

int main()
{
  long long res=0, tmpl;
  int i, n, a, b, tmp;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=1; i<=n; i++)
    Snm[i]=i, Sz[i]=1;
  for (i=0; i<n-1; i++)
  {
    //cerr<<i<<endl;
    scanf("%d%d%d", &a, &b, &tmp);
    if (!isluck(tmp))
      join(a,b);
  }
  for (i=1; i<=n; i++)
  {
    tmpl=n-Sz[SNM(i)];
    //cerr<<tmpl<<endl;
    res+=tmpl*(tmpl-1ll);
  }  
  printf("%I64d\n", res);
  return 0;
}