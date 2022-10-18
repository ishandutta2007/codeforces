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

typedef pair <long long, long long> pll;

long long Mod[2]={inf+7,inf+9};
long long P[2]={239017,18959};
long long Deg[310000][2];
pll sh, Hash[310000];
char s[310000];
int res, e, len;
vector <int> G[110000];
string Str[110000];

pll operator + (pll a, pll b)
{
  return mp((a.first+b.first)%Mod[0],(a.second+b.second)%Mod[1]);
}

pll operator * (int len, pll a)
{
  return mp((a.first*Deg[len][0])%Mod[0],(a.second*Deg[len][1])%Mod[1]);
}

void dfs (int v)
{
  int i, pe=e, nv, j;
  for (i=0; i<(int)G[v].size(); i++, e=pe)
  {
    nv=G[v][i];
    for (j=0; j<(int)Str[nv].size(); j++)
    {
      e++, Hash[e]=(e-1)*mp(Str[nv][j],Str[nv][j])+Hash[e-1];
      if (e>=len && Hash[e]==((e-len)*sh)+Hash[e-len])
        res++;
    }
    dfs(nv);
  }
}

int main()
{
  int i, n, x, j;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  for (i=0; i<2; i++)
    for (Deg[0][i]=1, j=1; j<310000; j++)
      Deg[j][i]=(Deg[j-1][i]*P[i])%Mod[i];
  scanf("%d", &n);
  for (i=0; i<n-1; i++)
    scanf("%d%s", &x, s), Str[i+1]=string(s,s+strlen(s)), G[x-1].pb(i+1);
  scanf("%s", s), len=strlen(s);
  for (i=0; i<len; i++)
    sh=sh+i*mp(s[i],s[i]);
  dfs(0);
  printf("%d\n", res);
  return 0;
}