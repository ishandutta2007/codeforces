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

const int maxn = 1100000;

vi S, NS, G[maxn];
int D[maxn], n, m, res, Deg[maxn];
         
void add (int v)
{
  //cerr<<v<<"  add  "<<res<<endl;
  if (D[v]<=res)
    return;
  D[v]=res, NS.pb(v);
  for (int i=0; i<(int)G[v].size(); i++)
  {
    Deg[G[v][i]]--;
    if (Deg[G[v][i]]==0)
      add(G[v][i]);
  }        
}

int main()
{
  int i, v1, v2, st, en;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d", &n, &m);
  for (i=0; i<m; i++)
    scanf("%d%d", &v1, &v2), v1--, v2--, G[v2].pb(v1), Deg[v1]++;
  scanf("%d%d", &en, &st), en--, st--;
  for (i=0; i<n; i++)
    D[i]=inf;
  add(st);
  S.swap(NS);
  while (S.size())
  {
    res++;
    NS.clear();
    for (int it=0; it<(int)S.size(); it++)
    {
      //cerr<<S[it]<<" "<<D[S[it]]<<endl;
      for (i=0; i<(int)G[S[it]].size(); i++)
        add(G[S[it]][i]);
    }
    S.swap(NS);
  }
  if (D[en]==inf)
    D[en]=-1;
  printf("%d\n", D[en]);
  TIMESTAMP(end);
  return 0;
}