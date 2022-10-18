#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <iostream>

#define pb push_back
#define mp make_pair
#define TASKNAME ""

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("[" #x "] Time = %.3lfs\n",clock()*1.0/CLOCKS_PER_SEC)

#ifdef linux
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif

#define sz(x) ((int)(x).size())

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<pii> vpii;

const int inf = 1e9;
const double eps = 1e-9;
const double INF = inf;
const double EPS = eps;

vi G[2100], P[2100];
vpii B;
int Tin[2100], Tout[2100], t;
int col[2100], e, sz[2100];
int res, Sum[2100];
bool u[2100];
int n, m;

void dfs1 (int v, int par=-1)
{ 
  t++, Tin[v]=t, Tout[v]=t, u[v]=1;
  for (int i=0; i<(int)G[v].size(); i++)
    if (G[v][i]!=-1 && G[v][i]!=par) 
    {
      if (!u[G[v][i]])
      {
        dfs1(G[v][i],v);
        if (Tin[v]<Tout[G[v][i]])
        {
          B.pb(mp(v,G[v][i]));
          G[G[v][i]][P[v][i]]=-1;
          G[v][i]=-1;
        }
        else
          Tout[v]=min(Tout[v],Tout[G[v][i]]);
      }
      else
        Tout[v]=min(Tout[v],Tout[G[v][i]]);
    }
  //cerr<<v<<" "<<t<<" "<<Tin[v]<<" "<<Tout[v]<<endl;
}

void dfs2 (int v)
{
  col[v]=e, sz[e]++;
  for (int i=0; i<(int)G[v].size(); i++)
    if (G[v][i]!=-1 && col[G[v][i]]==-1)
      dfs2(G[v][i]);
}

vi S[2100];
bool D[2100];
int root=-1;      

void dfs3 (int v)
{
  int lf=n-sz[v];
  Sum[v]=sz[v], u[v]=1;
  for (int i=0; i<(int)G[v].size(); i++)
    if (!u[G[v][i]])
      dfs3(G[v][i]), lf-=Sum[G[v][i]], Sum[v]+=Sum[G[v][i]], S[v].pb(Sum[G[v][i]]);
  assert((lf==0)^(v!=0));
  if (lf)
    S[v].pb(lf);
  sort(S[v].begin(),S[v].end());
  if (2*S[v].back()<=n)
    root=v;
}

void dfs4 (int v)
{
  u[v]=1;
  Sum[v]=sz[v];
  for (int i=0; i<(int)G[v].size(); i++)
    if (!u[G[v][i]])
      dfs4(G[v][i]), Sum[v]+=Sum[G[v][i]], res+=sz[v]*Sum[G[v][i]];
}

int main()
{
  int i, j, k, v1, v2;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d", &n, &m);
  for (i=0; i<m; i++)
    scanf("%d%d", &v1, &v2), v1--, v2--, P[v1].pb(G[v2].size()), P[v2].pb(G[v1].size()), G[v1].pb(v2), G[v2].pb(v1);
  dfs1(0);
  memset(col,-1,sizeof(col));  
  for (i=0; i<n; i++)
    if (col[i]==-1)
      dfs2(i), res+=sz[e]*sz[e], e++;
  if (e==1)
  {
    printf("%d\n", res);
    TIMESTAMP(end);
    return 0;
  }
  for (i=0; i<n; i++)
    G[i].clear(), P[i].clear();
  assert((int)B.size()==e-1);
  for (i=0; i<(int)B.size(); i++)
    G[col[B[i].first]].pb(col[B[i].second]), G[col[B[i].second]].pb(col[B[i].first]);
  memset(u,0,sizeof(u));
  dfs3(0);
  assert(root!=-1);
  int add=0;
  for (i=root; i<=root; i++)
  {
    memset(D,0,sizeof(D));
    D[0]=1;
    int ts=0;
    for (j=0; j<(int)S[i].size(); ts+=S[i][j], j++)
      for (k=ts; k>=0; k--)
        if (D[k])
          D[k+S[i][j]]=1;
    assert(ts==n-sz[i]);
    int ans=0;
    for (j=0; j<=ts; j++)
      if (D[j])
        ans=max(ans,j*(n-sz[i]-j));
    add=max(add,ans);   
  }
  res+=add;
  memset(u,0,sizeof(u));
  dfs4(root);
  printf("%d\n", res);
  TIMESTAMP(end);
  return 0;
}