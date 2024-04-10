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

int n, m;
bool F[110000];
vector <pair <int, int> > G[110000];
vector <int> R[110000];
int D[110000];
set <pair <int, int> > S;

int main()
{
  int i, j, v, v1, v2, t, cnt;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (i=0; i<m; i++)
    scanf("%d%d%d", &v1, &v2, &t), v1--, v2--, G[v1].pb(mp(v2,t)), G[v2].pb(mp(v1,t));
  for (i=0; i<n; sort(R[i].begin(),R[i].end()), i++)
    for (scanf("%d", &cnt), j=0; j<cnt; j++)
      scanf("%d", &t), R[i].pb(t);
  for (S.insert(mp(0,0)), i=1; i<n; i++)
    D[i]=2*inf;
  while (S.size())
  {
    v=S.begin()->second, S.erase(S.begin());
    if (!F[v])
    {
      if (v==n-1)
      {
        if (D[n-1]==2*inf)
          D[n-1]=-1;
        printf("%d\n", D[n-1]);
        return 0;
      }
      for (i=0; i<(int)R[v].size(); i++)
        if (R[v][i]==D[v])
          D[v]++;
    }
    for (i=0; i<(int)G[v].size(); i++)
      if (D[G[v][i].first]>D[v]+G[v][i].second)
        S.erase(mp(D[G[v][i].first],G[v][i].first)), D[G[v][i].first]=D[v]+G[v][i].second, S.insert(mp(D[G[v][i].first],G[v][i].first));
  }
  puts("-1");
  return 0;
}