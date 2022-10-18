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

const int inf = 1e9;
const double eps = 1e-9;
const double INF = inf;
const double EPS = eps;

vi G[110000];
int n, m, d;
bool A[110000];
int D[110000];
int res;
bool u[110000];

void dfsf (int v)
{
  u[v]=1, D[v]=-inf;
  if (A[v])
    D[v]=0; 
  for (int i=0; i<(int)G[v].size(); i++)
    if (!u[G[v][i]])
      dfsf(G[v][i]), D[v]=max(D[v],D[G[v][i]]+1);
  //cerr<<v<<" "<<D[v]<<endl;   
}

void dfss (int v, int h)
{
  u[v]=1;
  if (A[v])   
    h=max(h,0);
  int d1=-inf, d2=-inf;
  int v1=-1;
  int i;
  for (i=0; i<(int)G[v].size(); i++)
    if (!u[G[v][i]])
    {
      if (D[G[v][i]]>=d1)
      {
        d2=d1;
        d1=D[G[v][i]], v1=G[v][i];
        continue;
      }
      if (D[G[v][i]]>=d2)
        d2=D[G[v][i]];
    }
  for (i=0; i<(int)G[v].size(); i++)
    if (!u[G[v][i]]) 
    {
      if (G[v][i]!=v1)
      {
        if (h+1<=d && d1+2<=d && D[G[v][i]]<=d)
          res++;
        dfss(G[v][i],max(h+1,d1+2));
      }
      else
      {
        if (h+1<=d && d2+2<=d && D[G[v][i]]<=d)
          res++;
        dfss(G[v][i],max(h+1,d2+2));
      }
    }
}
         
int main()
{
  int i, v, v1, v2;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d%d", &n, &m, &d);
  for (i=0; i<m; i++)
    scanf("%d", &v), A[v-1]=1;
  for (i=0; i<n-1; i++)
    scanf("%d%d", &v1, &v2), v1--, v2--, G[v1].pb(v2), G[v2].pb(v1);
  dfsf(0);
  if (D[0]<=d)
    res++;
  memset(u,0,sizeof(u));
  dfss(0,-inf);
  cout<<res<<endl; 
  TIMESTAMP(end);
  return 0;
}