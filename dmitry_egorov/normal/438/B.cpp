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

const int maxn = 110000;

ll res, cval;
int Snm[maxn], Sz[maxn];

int SNM (int v)
{
  if (Snm[v]==v)
    return v;
  Snm[v]=SNM(Snm[v]);
  return Snm[v];
}

void join (int a, int b)
{
  a=SNM(a), b=SNM(b);
  if (a==b)
    return;
  if (Sz[a]>Sz[b])
    swap(a,b);
  res+=cval*1ll*Sz[a]*1ll*Sz[b];
  Sz[b]+=Sz[a], Snm[a]=b;
}
        
pii A[maxn];
int Val[maxn];
vi G[maxn];
bool u[maxn];

int main()
{
  int i, j, n, m, v1, v2;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d", &n, &m);
  for (i=0; i<n; i++)
    scanf("%d", &A[i].first), A[i].second=i, Val[i]=A[i].first, Snm[i]=i, Sz[i]=1;
  sort(A,A+n), reverse(A,A+n);  
  for (i=0; i<m; i++)
    scanf("%d%d", &v1, &v2), v1--, v2--, G[v1].pb(v2), G[v2].pb(v1);
  for (i=0; i<n; i++)
  {
    int v=A[i].second;
    u[v]=1, cval=Val[v];
    for (j=0; j<(int)G[v].size(); j++)
    {
      int nv=G[v][j];
      if (u[nv])
        join(v,nv);
    }
  }
  res*=2ll;
  ld ans=res;
  ans/=n*1ll*(n-1);
  printf("%.8lf\n", (double)ans);
  TIMESTAMP(end);
  return 0;
}