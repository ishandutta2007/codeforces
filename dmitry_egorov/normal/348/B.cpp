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

const int maxn = 110000;

int A[maxn], P[maxn], n;
ll Sum[maxn], W[maxn], D[maxn];
bool u[maxn];
vi G[maxn];

ll lcm (ll a, ll b)
{
  if (a==0 || b==0)
    return 0;
  ll d=__gcd(a,b);
  if ((a*1.0*b)/d>2e18)
    return 0;
  return (a/d)*b;
}
                      
void dfs (int v)
{
  int i, cnt=0;
  bool fl=1;
  u[v]=1, D[v]=1;
  for (int i=0; i<(int)G[v].size(); i++)
    if (!u[G[v][i]])
      cnt++, fl=0, P[G[v][i]]=v, dfs(G[v][i]), Sum[v]+=Sum[G[v][i]], D[v]=lcm(D[v],D[G[v][i]]);
  Sum[v]+=A[v];
  if (fl)
  {
    W[v]=Sum[v];
    return;
  }
  if (D[v]==0)
  {
    W[v]=0;
    return;
  }
  ll mul=1e18;
  for (i=0; i<(int)G[v].size(); i++)
    if (P[G[v][i]]==v)
      mul=min(mul,W[G[v][i]]/D[v]);
  if (mul==0)
  {
    D[v]=0;
    return;
  }
  D[v]*=cnt, W[v]=mul*D[v];
}

int main()
{
  int i, v1, v2;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d", &A[i]);
  for (i=0; i<n-1; i++)
    scanf("%d%d", &v1, &v2), v1--, v2--, G[v1].pb(v2), G[v2].pb(v1);
  dfs(0);
  cout<<Sum[0]-W[0]<<endl;  
  TIMESTAMP(end);
  return 0;
}