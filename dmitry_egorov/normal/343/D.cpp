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

vi G[510000];
pii Q[510000];
int eq, n, q, ct;
bool u[510000];
int L[510000], R[510000];
int Tr[(1<<20)+10];
int Res[510000];

void dfs1 (int v)
{
  L[v]=ct, u[v]=1, ct++;
  for (int i=0; i<(int)G[v].size(); i++)
    if (!u[G[v][i]])
      dfs1(G[v][i]);
  R[v]=ct-1;
}

set<int> S;
set <int> :: iterator it;
          
void dfs2 (int v)
{
  u[v]=1;
  int ps=lower_bound(Q,Q+eq,mp(v,-inf))-Q;
  int ops=ps, id;
  while (Q[ps].first==v && Q[ps].second<0)
  {
    //cerr<<v<<"   ins   "<<-Q[ps].second<<endl;
    S.insert(-Q[ps].second), ps++;
  }
  while (Q[ps].first==v)
  {
    id=Q[ps].second;
    it=S.lower_bound(id), it--;
    //cerr<<"   ans    "<<v<<"     "<<id<<"       "<<(*it)<<"    "<<Res[id]<<endl;
    ((*it)>Res[id])?(Res[id]=1):(Res[id]=0);
    ps++;
  }
  for (int i=0; i<(int)G[v].size(); i++)
    if (!u[G[v][i]])
      dfs2(G[v][i]);
  while (Q[ops].first==v && Q[ops].second<0)
  {
    //cerr<<v<<"   ers   "<<-Q[ops].second<<endl;
    S.erase(-Q[ops].second), ops++;
  }
}

int main()
{
  int i, v1, v2, v, q, tp, l, r;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d", &n);
  for (i=0; i<n-1; i++)
    scanf("%d%d", &v1, &v2), v1--, v2--, G[v1].pb(v2), G[v2].pb(v1);  
  dfs1(0);
  scanf("%d", &q);
  memset(Res,-1,sizeof(Res));
  for (i=1; i<=q; i++)
  {
    scanf("%d%d", &tp, &v), v--;
    if (tp==2)
    {
      v=L[v]+(1<<19);
      while (v>0)
        Tr[v]=max(Tr[v],i), v>>=1;
      continue;
    }
    (tp==1)?(Q[eq++]=mp(v,-i)):(Q[eq++]=mp(v,i));
    if (tp==3)
    {
      l=L[v]+(1<<19), r=R[v]+(1<<19);
      //cerr<<"??   "<<v<<"  "<<L[v]<<" "<<R[v]<<endl;
      while (l<=r)
      {
        //cerr<<l<<" "<<r<<endl;
        if (l&1)
          Res[i]=max(Res[i],Tr[l]), l++;
        if ((r&1)!=1)
          Res[i]=max(Res[i],Tr[r]), r--;
        l>>=1, r>>=1;
      }
      //cerr<<"!!!!!!???"<<endl;
    }
  }
  sort(Q,Q+eq), Q[eq]=mp(-1,-inf);
  memset(u,0,sizeof(u));
  S.insert(-inf);
  dfs2(0);
  assert((int)S.size()==1 && (*S.begin())==-inf);
  for (i=0; i<510000; i++)
    if (Res[i]!=-1)
      printf("%d\n", Res[i]);
  TIMESTAMP(end);
  return 0;
}