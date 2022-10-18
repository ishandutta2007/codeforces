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

int D[3100][3], res=inf;
bool u[3100];
vector <pair <int, int> > G[3100];

void dfs (int v)
{
  int nv, tp;
  D[v][0]=0; 
  int dif1=0, dif2=0;
  u[v]=1;
  for (int i=0; i<(int)G[v].size(); i++)
  {
    nv=G[v][i].first, tp=G[v][i].second;
    if (u[nv])
      continue;
    dfs(nv);
    D[v][0]+=tp+D[nv][0];
    dif1=min(dif1,D[nv][1]+(1-tp)-(D[nv][0]+tp));
    dif2=min(dif2,min((D[nv][2]+tp)-(D[nv][0]+tp),D[nv][1]-(D[nv][0]+tp)));
//    cerr<<"!!! "<<v<<" "<<D[v][0]<<endl;
  }
  D[v][1]=D[v][0]+dif1, D[v][2]=D[v][0]+dif2;
  //cerr<<v<<"    "<<D[v][0]<<" "<<D[v][1]<<" "<<D[v][2]<<endl;
}

void solve (int v)
{
  memset(u,0,sizeof(u));
  dfs(v);
  //cerr<<D[v][0]<<" "<<D[v][1]<<" "<<D[v][2]<<endl;
  res=min(res,D[v][0]), res=min(res,D[v][1]), res=min(res,D[v][2]);
}

int main()
{
  int n, i, v1, v2;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  if (n==1)
  {
    puts("0");
    return 0;
  }
  for (i=0; i<n-1; i++)
    scanf("%d%d", &v1, &v2), v1--, v2--, G[v1].pb(mp(v2,0)), G[v2].pb(mp(v1,1));
  //solve(1);
  for (i=0; i<n; i++)
    solve(i);
  printf("%d\n", res);
  return 0;
}