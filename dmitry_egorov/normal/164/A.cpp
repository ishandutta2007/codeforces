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

bool u[110000];
int T[110000], n, m;
vector <int> G[110000], Rg[110000];
int Res[110000];

void dfs (int v)
{
  u[v]=1, Res[v]|=1;
  for (int i=0; i<(int)G[v].size(); i++)
    if ((!u[G[v][i]]) && T[G[v][i]]!=1)
      dfs(G[v][i]);
}

void dfs2 (int v)
{
  u[v]=1, Res[v]|=2;
  for (int i=0; i<(int)Rg[v].size(); i++)
  {
    if ((!u[Rg[v][i]]) && T[Rg[v][i]]!=1)
      dfs2(Rg[v][i]);
    Res[Rg[v][i]]|=2;
  }
}

int main()
{
  int i, v1, v2;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (i=0; i<n; i++)
    scanf("%d", &T[i]);
  for (i=0; i<m; i++)
    scanf("%d%d", &v1, &v2), v1--, v2--, G[v1].pb(v2), Rg[v2].pb(v1);// G[v2].pb(v1);
  for (i=0; i<n; i++)
    if (T[i]==1)
      dfs(i);
  memset(u,0,sizeof(u));
  for (i=0; i<n; i++)
    if (T[i]==2)
      dfs2(i);
  for (i=0; i<n; i++)
    printf("%d\n", Res[i]/3);
  return 0;
}