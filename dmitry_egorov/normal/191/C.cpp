#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <string>
#include <ctime>
#include <stack>

#define sqr(x) ((x)*(x))
#define sz(a) (int)a.size()
#define pb push_back
#define mp make_pair
#define zero(a) memset (a, 0, sizeof(a))



#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


const int inf = (int)1e9;

vector <int> G[110000];
bool u[110000];
int n, LCA[20][110000], L[110000], A[110000][2];
int W[110000];

void dfs (int v)
{
  u[v]=1;
  for (int i=0; i<(int)G[v].size(); i++)
    if (!u[G[v][i]])
    { 
      LCA[0][G[v][i]]=v, L[G[v][i]]=L[v]+1;
      dfs(G[v][i]);
    }
}

int lca (int v1, int v2)
{
  int i;
  if (L[v1]<L[v2])
    swap(v1,v2);
  for (i=19; i>=0; i--)
    if ((L[v1]-L[v2])&(1<<i))
      v1=LCA[i][v1];
  if (v1==v2)
    return v1;
  for (i=19; i>=0; i--)
    if (LCA[i][v1]!=LCA[i][v2])
      v1=LCA[i][v1], v2=LCA[i][v2];
  return LCA[0][v1];
}

void dfs2 (int v)
{
  u[v]=1;
  for (int i=0; i<(int)G[v].size(); i++)
    if (!u[G[v][i]])
    { 
      dfs2(G[v][i]);
      W[v]+=W[G[v][i]];
    }
}

int main (void)
{
  int i, v1, v2, j, q;
  #ifdef LOCAL
    freopen (".in", "r", stdin);
    freopen (".out", "w", stdout);
  #endif                              
  scanf("%d", &n);
  for (i=0; i<n-1; i++)
    scanf("%d%d", &v1, &v2), v1--, v2--, G[v1].pb(v2), G[v2].pb(v1), A[i][0]=v1, A[i][1]=v2;
  dfs(0);
  cerr<<"!!!"<<endl;
  for (i=1; i<20; i++)
    for (j=0; j<n; j++)
      LCA[i][j]=LCA[i-1][LCA[i-1][j]];

  //cerr<<"!!!"<<endl;
  scanf("%d", &q);
  while (q>0)
  {
  //  cerr<<q<<endl;
    q--, scanf("%d%d", &v1, &v2), v1--, v2--;
    W[v1]++, W[v2]++, W[lca(v1,v2)]-=2;
  }
//  cerr<<"!!!"<<endl;
  memset(u,0,sizeof(u));
  dfs2(0);
  for (i=0; i<n-1; i++)
    printf("%d ", W[((L[A[i][0]]<L[A[i][1]])?(A[i][1]):(A[i][0]))]);
  printf("\n");
  return 0;
}