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

bool u[123123];
char Tp[123123];
vector<pair<char,int> > Ev[123123];
int Id[123123], P[(1<<18)+100], st, n, m;
bool g[123123]; 

bool get (int l, int r)
{
  int ret=0;
  l+=(1<<17), r+=(1<<17);
  while (l<r)
  {
    if (l&1)
      ret=max(ret,P[l]), l++;
    if (r&1)
      r--, ret=max(ret,P[r]);
    l>>=1, r>>=1;
  }
  return (ret>0);
}

int main()
{
  int i, j, res=0;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d", &n, &m);  
  for (i=0; i<m; i++)
  {
    scanf(" %c%d", &Tp[i], &Id[i]), Id[i]--;
    if (u[Id[i]]==0 && Tp[i]=='-')
        st++, u[Id[i]]=1;
    u[Id[i]]=1;
    Ev[Id[i]].pb(mp(Tp[i],i));
  }
  for (P[(1<<17)]=st, i=0; i<m; i++)
  {
    (Tp[i]=='-')?(st--):(st++);
    assert(st>=0);
   // cerr<<i<<" "<<st<<endl;
    P[(1<<17)+i+1]=st;
  }
  for (i=(1<<17)-1; i>0; i--) 
    P[i]=max(P[2*i],P[2*i+1]);
  for (i=0; i<n; i++)
  { 
   // cerr<<i<<endl;
    if (!Ev[i].size())
    {
      res++;
      g[i]=1;
      continue;
    }
    bool good=1;
    if (Ev[i][0].first=='+' && get(0,Ev[i][0].second+1))
      good=0;
    if (Ev[i].back().first=='-' && get(Ev[i].back().second+1,m+1))
      good=0;
    //cerr<<"?? "<<endl;
    for (j=1; j<(int)Ev[i].size(); j++)
      if (Ev[i][j].first=='+' && get(Ev[i][j-1].second+1,Ev[i][j].second+1))
        good=0;
    if (good)
      res++, g[i]=1; 
  }
  printf("%d\n", res);
  for (i=0; i<n; i++)
    if (g[i])
      printf("%d ", i+1);
  printf("\n");
  TIMESTAMP(end);
  return 0;
}