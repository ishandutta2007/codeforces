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

vector <int> G[110000];
int Cnt[110000];
bool u[110000];
long double res;

void dfs (int v, int lv)
{
  Cnt[lv+1]++, u[v]=1;
  for (int i=0; i<(int)G[v].size(); i++)
    if (!u[G[v][i]])
      dfs(G[v][i],lv+1);
}

int main()
{
  int n, v1, v2, i;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n-1; i++)
    scanf("%d%d", &v1, &v2), v1--, v2--, G[v1].pb(v2), G[v2].pb(v1);
  dfs(0,0);
  for (i=n; i>0; i--)
    res+=Cnt[i]/((long double)i);
  printf("%.8lf\n", (double)res);
  return 0;
}