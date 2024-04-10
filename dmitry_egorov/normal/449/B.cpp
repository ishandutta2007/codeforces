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

const int maxn = 123123;

vpii G[maxn];
pii R[maxn];
ll D[maxn];
int ptr, n, m, e, res;
set<pair<ll,int> > S;

void add (int v, ll d)
{
  if (D[v]<=d)
   return;
  S.erase(mp(D[v],v)), D[v]=d, S.insert(mp(d,v));
}
              
bool addr (ll mx)
{
  if (ptr<e && R[ptr].first<mx)
  {
    int v=R[ptr].second, d=R[ptr].first;
    if (D[v]>d)
      add(v,d);
    else
      res++;
    ptr++;
    return 1;
  }
  return 0;
}

int main()
{
  int i, u, v, x;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d%d", &n, &m, &e);
  for (i=0; i<m; i++)
    scanf("%d%d%d", &u, &v, &x), u--, v--, G[u].pb(mp(v,x)), G[v].pb(mp(u,x));
  for (i=0; i<e; i++)
    scanf("%d%d", &R[i].second, &R[i].first), R[i].second--;
  sort(R,R+e);
  for (i=0; i<n; i++)
    D[i]=inf*1ll*inf;
  add(0,0);
  while (S.size() || ptr<e)
  {
    if (!S.size())
    {
      if (!addr(inf*1ll*inf))
        break;
      continue;
    }
    if (addr(S.begin()->first))
      continue;
    v=S.begin()->second;
    ll d=S.begin()->first;
    S.erase(S.begin());
    for (i=0; i<(int)G[v].size(); i++)
      add(G[v][i].first,d+G[v][i].second);
  }
  cout<<res<<endl;
  TIMESTAMP(end);    
  return 0;
}