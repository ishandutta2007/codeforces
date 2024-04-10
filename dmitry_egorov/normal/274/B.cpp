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
long long V[110000], Inc[110000], Dec[110000];
vector <int> G[110000];
int n;

void dfs (int v)
{
  u[v]=1;
  for (int i=0; i<(int)G[v].size(); i++)
    if (!u[G[v][i]])
      dfs(G[v][i]), Inc[v]=max(Inc[v],Inc[G[v][i]]), Dec[v]=max(Dec[v],Dec[G[v][i]]);
  long long tbal=V[v]+Inc[v]-Dec[v];
  (tbal>=0)?(Dec[v]+=tbal):(Inc[v]-=tbal);
}

int main()
{
  int i, v1, v2, x;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n-1; i++)
    scanf("%d%d", &v1, &v2), v1--, v2--, G[v1].pb(v2), G[v2].pb(v1);
  for (i=0; i<n; i++)
    scanf("%d", &x), V[i]=x;
  dfs(0);
  printf("%I64d\n", Inc[0]+Dec[0]);
  return 0;
}