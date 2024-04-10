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
#define mod (1000000007ll)

using namespace std;

int Snm[2100], Sz[2100];

int SNM (int v)
{
  if (Snm[v]!=v)
    Snm[v]=SNM(Snm[v]);
  return Snm[v];
}

void join (int a, int b)
{
  a=SNM(a), b=SNM(b);
  if (a==b)
    return;
  if (Sz[a]<=Sz[b])
    Snm[a]=b, Sz[b]+=Sz[a];
  else
    Snm[b]=a, Sz[a]+=Sz[b];
}

int main()
{
  int i, j, n, k;
  long long m, res=1ll;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%I64d%d", &n, &m, &k);
  for (i=0; i<n; i++)
    Snm[i]=i, Sz[i]=1;
  for (i=0; i+k<=n; i++)
    for (j=0; j<k; j++)
      join(i+j,i+k-1-j);
  for (i=0; i<n; i++)
    if (Snm[i]==i)
      res*=m, res%=mod;
  printf("%I64d\n", res);
  return 0;
}