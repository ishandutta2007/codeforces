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

const int maxn = (1<<20)+100;

int Cnt[4*maxn];
pii Val[4*maxn];
int n, m;
bool u[maxn];
int Res[maxn];

int main()
{
  int i, v, val, pos; 
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d", &n, &m);
  for (i=0; i<n; i++)
    Val[(1<<21)+(1<<20)+i]=mp(i+1,-1), Cnt[(1<<21)+(1<<20)+i]=1;
  for (i=(1<<21)-1; i>0; i--)
    Cnt[i]=Cnt[2*i]+Cnt[2*i+1];
  int b=(1<<21)+(1<<20);
  while (m)
  {
    b--, m--, scanf("%d%d", &val, &pos), val--, pos--;
    v=1;
    while (v<(1<<21))
    {
      v<<=1;
      if (Cnt[v]<=pos)
        pos-=Cnt[v], v++;
    }
    assert(Cnt[v]==1);
    pii cval=Val[v];
    Val[v]=mp(0,0);
    if (cval.second==-1)
      cval.second=val;
    if (cval.second!=val)
    {
      puts("-1");
      return 0;
    }
    while (v)
      Cnt[v]--, v>>=1;
    v=b;
    Val[v]=cval;
    while (v)
      Cnt[v]++, v>>=1;
  }
  memset(Res,-1,sizeof(Res));
  for (i=b; i<4*maxn; i++)
    if (Val[i].first && Val[i].second!=-1) 
    {
      if (u[Val[i].second])
      {
        puts("-1");
        return 0;
      }
      Res[Val[i].first-1]=Val[i].second, u[Val[i].second]=1;
    }
  int ptr=0;
  for (i=0; i<n; i++)
    if (Res[i]==-1)
    {
      while (u[ptr])
        ptr++;
      Res[i]=ptr, u[ptr]=1;
    }
  for (i=0; i<n; i++)
    printf("%d ", Res[i]+1);
  printf("\n");
  TIMESTAMP(end);
  return 0;
}