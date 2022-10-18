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

vector <int> G[5100], Res;
bool C[5100], u[5100], C2[5100];
int n, V[5100];

void dfs (int v)
{
  u[v]=1, V[v]=1;
  vector <int> Cmp;
  int i, j;
  for (i=0; i<(int)G[v].size(); i++)
    if (!u[G[v][i]])
      dfs(G[v][i]), V[v]+=V[G[v][i]], Cmp.pb(V[G[v][i]]);
  memset(C2,0,sizeof(C2)), C2[0]=1, Cmp.pb(n-V[v]);
  for (i=0; i<(int)Cmp.size(); i++)
    for (j=n; j>=0; j--)
      if (C2[j])
        C2[j+Cmp[i]]=1;
  for (i=0; i<=n; i++)
    if (C2[i])
      C[i]=1;
}

int main()
{
  int i, v1,v2;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n-1; i++)
    scanf("%d%d", &v1, &v2), v1--, v2--, G[v1].pb(v2), G[v2].pb(v1);
  dfs(0);
  for (i=1; i<n-1; i++)
    if (C[i])
      Res.pb(i);
  for (printf("%d\n", Res.size()), i=0; i<(int)Res.size(); i++)
    printf("%d %d\n", Res[i], n-1-Res[i]);
  return 0;
}