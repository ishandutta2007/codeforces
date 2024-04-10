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

int Res[210000];
vector <pair<int, int> > G[210000], I[210000];
int Deg[210000];
set <pair <int, int> > S;
bool u[210000];

int main()
{
  int n, m, v, v1, v2, nv, c, i;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (i=0; i<m; i++)
    scanf("%d%d%d", &v1, &v2, &v), v1--, v2--, Deg[v1]+=v, Deg[v2]+=v, G[v1].pb(mp(v2,v)), G[v2].pb(mp(v1,v)), I[v1].pb(mp(i,0)), I[v2].pb(mp(i,1));
  for (i=1; i<n-1; i++)
    Deg[i]/=2, S.insert(mp(Deg[i],i));
  S.insert(mp(0,0)), S.insert(mp(Deg[n-1],n-1));
  while (S.size())
  {
   // cerr<<S.begin()->first<<"        "<<S.begin()->second<<endl;
    assert(S.begin()->first==0);
    v=S.begin()->second, S.erase(S.begin()), u[v]=1;
    for (i=0; i<(int)G[v].size(); i++)
    {
      nv=G[v][i].first, c=G[v][i].second;
      if (!u[nv])
        S.erase(mp(Deg[nv],nv)), Deg[nv]-=c, S.insert(mp(Deg[nv],nv)), Res[I[v][i].first]=I[v][i].second;
    }
  }
  for (i=0; i<m; i++)
    printf("%d\n", Res[i]);
  return 0;
}