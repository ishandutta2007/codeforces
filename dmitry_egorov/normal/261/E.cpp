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

bool u[100];
long long up=inf+1000;
int V[3100000], e=1, res;
bool g[3100000];
int D[3100000];

int main()
{
  int k, i, j, tmp, l, r, p;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  cin>>l>>r>>p;
  for (i=2; i<100; i++)
    if (!u[i]) 
    {
      for (j=i*i; j<100; j+=i)
        u[j]=1;
    }
  V[0]=1;
  for (i=2; i<100; i++)
    if (!u[i])
    {
      int ee=e;
      for (j=0; j<ee; j++)
      {
        tmp=V[j];
        while (tmp*1ll*i<=up)
          tmp*=i, V[e++]=tmp;
      }
    }
  sort(V,V+e);
  for (i=1, g[0]=1; i<e; i++)
    D[i]=inf;
  for (i=2; i<=p; i++)
  {
    j=0, k=0;
    while (true)
    {
      tmp=V[j]*i;
      while (k<e && V[k]<tmp)
        k++;
      if (k==e)
        break;
      if (V[k]==tmp && D[k]>D[j]+1)
      {  
        D[k]=D[j]+1;
        if (D[k]+i<=p)
          g[k]=1;
      }
      j++;
    }
  }
  for (i=0; i<e; i++)
    if (l<=V[i] && V[i]<=r && g[i])
      res++;
  printf("%d\n", res);
  return 0;
}