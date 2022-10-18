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
#define inf ((long long)1e18)
#define pb push_back
#define mp make_pair

using namespace std;

long long res;
int Snm[110000], n, m;
set <pair <long long, int> > S;
long long D[110000];
int K[110000], e;
pair <long long, pair <int, int> > A[210000];
vector <pair <int, long long> > G[110000];
pair <long long, long long> p;

int SNM (int v)
{
  if (Snm[v]==v)
    return v;
  Snm[v]=SNM(Snm[v]);
  return Snm[v];
}

void join (int a, int b, long long t)
{
  a=SNM(a), b=SNM(b);
  if (a!=b)
  {
    res+=t;
    (rand()&1)?(Snm[a]=b):(Snm[b]=a);
  }
}

int main()
{
  int v1, v2, v, i, j, w, nv, x, k;
  long long lr;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (i=0; i<m; i++)
    scanf("%d%d%d", &v1, &v2, &w), v1--, v2--, G[v1].pb(mp(v2,w)), G[v2].pb(mp(v1,w));
  scanf("%d", &k);
  for (i=0; i<n; i++)
    S.insert(mp(inf,i)), Snm[i]=i, D[i]=inf, K[i]=-1;
  for (i=0; i<k; i++)
    scanf("%d", &x), x--, S.erase(mp(inf,x)), D[x]=0, K[x]=x, S.insert(mp(0,x));
  while (S.size())
  {
    p=*S.begin(), S.erase(S.begin());
    v=p.second;
    for (int i=0; i<(int)G[v].size(); i++)
    {
      nv=G[v][i].first, lr=G[v][i].second;
      if (D[nv]>D[v]+lr)
        S.erase(mp(D[nv],nv)), D[nv]=D[v]+lr, K[nv]=K[v], S.insert(mp(D[nv],nv));
    }
  }
  //for (i=0; i<n; i++)
  //  cerr<<D[i]<<" "<<K[i]<<endl;
  for (i=0; i<n; i++)
    for (j=0; j<(int)G[i].size(); j++)
    {
      v=G[i][j].first;
      //cerr<<i<<" "<<v<<" "<<D[i]+D[v]+G[i][j].second<<endl;
      if (K[i]!=K[v])
        A[e++]=mp(D[i]+D[v]+G[i][j].second,mp(K[i],K[v]));
    }
  //cerr<<e<<endl;
  sort(A,A+e);
  for (i=0; i<e; i++)
    join(A[i].second.first,A[i].second.second,A[i].first);
  printf("%I64d\n", res+D[0]);
  return 0;
}