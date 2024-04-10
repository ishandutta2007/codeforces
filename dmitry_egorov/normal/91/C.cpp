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
#define mod (1000000009)

using namespace std;

//int Deg[1100000];

int SNM[110000], Sz[110000];

int Snm(int v)
{
  if (v==SNM[v])
    return v;
  SNM[v]=Snm(SNM[v]);
  return SNM[v];
}

void join (int f, int s)
{
  f=Snm(f), s=Snm(s);
  if (Sz[f]<Sz[s])
    SNM[f]=s, Sz[s]+=Sz[f]; //V[s]+=V[f];
  else
    SNM[s]=f, Sz[f]+=Sz[s]; //V[f]+=V[s];
}

int main()
{
  int res=1, i, v1, v2, n, m;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  //Deg[0]=1;
  //for (i=1; i<110000; i++)
  //  Deg[i]=(Deg[i-1]*2)%mod;
  scanf("%d%d", &n, &m);
  for (i=0; i<n; i++)
    SNM[i]=i, Sz[i]=1;
  for (i=0; i<m; i++)
  {
    scanf("%d%d", &v1, &v2);
    v1--, v2--;
    v1=Snm(v1), v2=Snm(v2);
    if (v1==v2)
      res*=2, res%=mod;
    else
      join(v1,v2);
    printf("%d\n", (res+mod-1)%mod);
  }
  return 0;
}