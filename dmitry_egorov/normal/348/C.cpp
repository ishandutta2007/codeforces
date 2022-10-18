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
const int sz = 503;
vi S[maxn];
vi E[maxn];
int Id[maxn], eid;
ll Coef[maxn/sz+10];
ll Sum[maxn/sz+10];               
ll A[maxn];
int D[maxn][maxn/sz+10];
int n, m, q;

int main()
{
  int i, j, x, v, k, tmp;
  ll res, sum;
  char c;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  memset(Id,-1,sizeof(Id));
  scanf("%d%d%d", &n, &m, &q);  
  for (i=0; i<n; i++)
    scanf("%d", &x), A[i]=x;
  for (i=0; i<m; i++)
  {
    sum=0;
    for (scanf("%d", &tmp); tmp>0; tmp--)
      scanf("%d", &x), x--, S[i].pb(x), E[x].pb(i), sum+=A[x];
    sort(S[i].begin(),S[i].end());
    //cerr<<sum<<endl;
    if ((int)S[i].size()>=sz)
      Id[i]=eid, Sum[eid]=sum, eid++;
  }
  for (i=0; i<n; i++)
  {
    sort(E[i].begin(),E[i].end());
    for (j=0; j<(int)E[i].size(); j++)
    {
      tmp=Id[E[i][j]];
      if (tmp!=-1)
        for (k=0; k<(int)E[i].size(); k++)
          D[E[i][k]][tmp]++;
    }
  }
  /*for (i=0; i<m; i++, cerr<<endl)
    for (j=0; j<m; j++)
      cerr<<D[i][j]<<" ";  */
  while (q>0)
  {
    //cerr<<"query"<<endl;
    q--, scanf(" %c", &c);
    if (c=='?')
    {
      scanf("%d", &v), v--;
      res=0;
      if (Id[v]!=-1)
        res=Sum[Id[v]];// cerr<<res<<endl;
      else
        for (i=0; i<(int)S[v].size(); i++)
          res+=A[S[v][i]];
      for (i=0; i<eid; i++)
        res+=Coef[i]*D[v][i];// cerr<<i<<" "<<Coef[i]<<endl;
      printf("%I64d\n", res);
      continue;
    }
    scanf("%d%d", &v, &x), v--;
    if (Id[v]!=-1)
    {
      Coef[Id[v]]+=x;
      //Sum[v]+=x*1ll*((int)S[v].size());
      continue;
    }
    for (i=0; i<eid; i++)
      Sum[i]+=x*1ll*D[v][i];
    for (i=0; i<(int)S[v].size(); i++)
      A[S[v][i]]+=x;
  }
  TIMESTAMP(end);
  return 0;
}