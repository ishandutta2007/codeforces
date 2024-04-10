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

const int magic = 450;
const int maxn = 210000;

int V[magic], TA[maxn], Add[maxn], A[maxn], NtoO[maxn], OtoN[maxn];
vi G[maxn], NG[maxn];
int Lv[maxn], t, Val[maxn], Tout[maxn], Llv[maxn];
bool u[maxn];

void dfs (int v)
{
  //cerr<<"??  "<<v<<" "<<Lv[v]<<endl;
  u[v]=1, OtoN[v]=t, NtoO[t]=v, t++;
  for (int i=0; i<(int)G[v].size(); i++)
    if (!u[G[v][i]]) 
      Lv[G[v][i]]=Lv[v]+1, dfs(G[v][i]), NG[OtoN[v]].pb(OtoN[G[v][i]]);
  Tout[OtoN[v]]=t;
}
                    
int main()
{
  int tp, n, m, i, j, tmp, v1, v2, v, pv;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d", &n, &m);
  for (i=0; i<n; i++)
    scanf("%d", &TA[i]);
  for (i=0; i<n-1; i++)
    scanf("%d%d", &v1, &v2), v1--, v2--, G[v1].pb(v2), G[v2].pb(v1);
  dfs(0);  
  for (i=0; i<n; i++)
    A[i]=TA[NtoO[i]];
  while (m>0)
  {                             
    memset(V,-1,sizeof(V));
    for (int it=0; it<magic; it++, m--)
    {
      if (m==0)
        break;
      scanf("%d%d", &tp, &v), v--, pv=v, v=OtoN[v];
      if (tp==1)
      {
        scanf("%d", &tmp), V[it]=v, Val[it]=tmp, Llv[it]=Lv[pv];
        Add[v]+=tmp;
        continue;
      }
      int res=A[v];
      for (j=0; j<it; j++)
        if (V[j]!=-1 && V[j]<=v && Tout[v]<=Tout[V[j]])
        { 
          //cerr<<it<<" "<<j<<" "<<res<<"     "<<Lv[v]<<" "<<Lv[V[j]]<<"      "<<v<<" "<<V[j]<<endl;
          if ((Lv[pv]-Llv[j])&1)
            res-=Val[j];
          else
            res+=Val[j];
        }
      printf("%d\n", res);
    }                  
    for (i=0; i<n; A[i]+=Add[i], Add[i]=0, i++)
      for (j=0; j<(int)NG[i].size(); j++)
        Add[NG[i][j]]-=Add[i];
  }
  TIMESTAMP(end);
  return 0;
}