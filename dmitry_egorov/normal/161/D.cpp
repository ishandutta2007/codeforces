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

int D[50100][510];
int n, k;
long long res;
bool u[51000];
vector <int> G[51000];

void dfs (int v)
{
  int i, j, nv;
  u[v]=1, D[v][0]++;
  for (i=0; i<(int)G[v].size(); i++)
    if (!u[G[v][i]])
    {
      nv=G[v][i], dfs(nv);
      for (j=0; j<k; j++)
        res+=(((long long)D[v][j])*((long long)D[nv][k-j-1]));
      for (j=0; j<k; j++)
        D[v][j+1]+=D[nv][j];
    }
}

int main()
{
  int x, y, i;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &k);
  for (i=0; i<n-1; i++)
    scanf("%d%d", &x, &y), x--, y--, G[x].pb(y), G[y].pb(x);
  dfs(0);
  printf("%I64d\n", res);
  return 0;
}