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
typedef pair <ll, int> pli;

//const int inf = 1e9;
const ll inf = 1e18;
const double eps = 1e-9;
const double INF = inf;
const double EPS = eps;

int n, m;
int L[110], R[110];
vector<pii> G[110000], GR[110000];    
int Tp[110000];
ll D[110000];
int s1, s2, f;
set<pli> S;
int Res[110];

void relax (int v, ll d, int tp) 
{
  if (D[v]<d)
    return;
  if (D[v]>d)
    S.erase(mp(D[v],v)), D[v]=d, Tp[v]=0, S.insert(mp(D[v],v));
  Tp[v]|=tp;
}

bool can (bool wn)
{
 // cerr<<"can  "<<wn<<endl;
  int i;
  for (i=0; i<110; i++)
    Res[i]=L[i];
  for (i=0; i<n; i++)
    D[i]=inf, Tp[i]=0;
  Tp[s1]=1, Tp[s2]=2;
  D[s1]=0, D[s2]=0;
  S.clear();
  S.insert(mp(D[s1],s1)), S.insert(mp(D[s2],s2));
  while (S.size())
  {
    int v=S.begin()->second;
    S.erase(S.begin());
    int tp=Tp[v];
  //  cerr<<v<<" "<<tp<<"   "<<D[v]<<endl;
    assert(0<tp && tp<4);
    for (i=0; i<(int)G[v].size(); i++)
      relax(G[v][i].first,D[v]+G[v][i].second,tp);
  //  cerr<<"??SDFGH"<<endl;
    for (i=0; i<(int)GR[v].size(); i++)
    {
   //   cerr<<"FG  "<<i<<"    "<<endl;
      int id=GR[v][i].second;
      int add=L[id];
      if (wn && (tp&2)!=0)
        add=R[id], Res[id]=R[id];
      if ((!wn) && (tp&1)==0)
        add=R[id], Res[id]=R[id];
   //   cerr<<"relax"<<endl;
      relax(GR[v][i].first,D[v]+add,tp);
    //  cerr<<"!!relax"<<endl;
    }
  //  cerr<<"??SDFGH"<<endl;
  }
  int tp=Tp[f];
  assert(0<tp && tp<4);
 // cerr<<tp<<endl;
  if (wn)
    return (tp==1);
  return ((tp&1)!=0);
}

int main()
{
  int i, k, v1, v2, l;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d%d", &n, &m, &k);
  scanf("%d%d%d", &s1, &s2, &f), s1--, s2--, f--;
  for (i=0; i<m; i++)
    scanf("%d%d%d", &v1, &v2, &l), v1--, v2--, G[v1].pb(mp(v2,l));
  for (i=0; i<k; i++)
    scanf("%d%d%d%d", &v1, &v2, &L[i], &R[i]), v1--, v2--, GR[v1].pb(mp(v2,i));
  if (s1==s2)
  {
    puts("DRAW");
    for (i=0; i<k; i++)
      printf("%d ", L[i]);
    return 0;
  }
  if (can(1))
  {
    puts("WIN");
    for (i=0; i<k; i++)
      printf("%d ", Res[i]);
    return 0;
  } 
  if (can(0))
  {
    puts("DRAW");
    for (i=0; i<k; i++)
      printf("%d ", Res[i]);
  }
  else
    puts("LOSE");
  TIMESTAMP(end);
  return 0;
}