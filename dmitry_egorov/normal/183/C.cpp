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

vector <int> V;
vector <pair <int, int> > G[110000];
bool u[110000];
int L[110000];

void dfs (int v)
{
  u[v]=1;
  int nv, nc;
  for (int i=0; i<(int)G[v].size(); i++)
  {
    nv=G[v][i].first, nc=G[v][i].second;
    if (!u[nv])
      L[nv]=L[v]+nc, dfs(nv);
    if (L[v]+nc!=L[nv])
      V.pb(abs(L[v]+nc-L[nv]));
  }
}

int main()
{
  int n, m, i, v1, v2;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (i=0; i<m; i++)
    scanf("%d%d", &v1, &v2), v1--, v2--, G[v1].pb(mp(v2,1)), G[v2].pb(mp(v1,-1));
  for (i=0; i<n; i++)
    if (!u[i])
      dfs(i);
  if (V.size()==0)    
  {
    printf("%d\n", n);
    return 0;
  }
  for (i=1; i<(int)V.size(); i++)
    V[0]=__gcd(V[0],V[i]);
  printf("%d\n", V[0]);
  return 0;
}