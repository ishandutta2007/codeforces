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

map<int,int> M;

int getId (int v)
{
  if (M.count(v)!=0)
    return M[v];
  int tmp=M.size();
  M[v]=tmp;
  return tmp;
}

int P[7123*17], Lf[7123*17], Rt[7123*17];
int Lv[7123], L[7123], R[7123], V[7123], e;
int Gl[7123], Gr[7123];         
int u[7123], uit=1;
int n;

int main()
{
  int i, q, tmp, tp, v, lv;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d", &n, &q);
  for (tmp=1, i=1; ; i++)
  {
    Lf[i]=tmp, Rt[i]=tmp, P[tmp++]=i;
    if (__builtin_popcount(i)==1)
      Rt[i]=tmp, P[tmp++]=i;
    if (tmp>=7123*17-5)
      break;
  }  
  for ( ; q>0; q--)
  {
    scanf("%d", &tp);
    if (tp==1)
    {
      scanf("%d%d%d%d", &Lv[e], &L[e], &R[e], &tmp), V[e]=getId(tmp), e++;
      continue;
    }
    scanf("%d%d", &lv, &v);
    //cerr<<lv<<" "<<v<<endl;
    for (i=1; i<lv; i++)
      Gl[i]=-1, Gr[i]=-1;
    Gl[lv]=v, Gr[lv]=v;
    for (i=lv+1; i<=n; i++)
      Gl[i]=Lf[Gl[i-1]], Gr[i]=Rt[Gr[i-1]];
    for (i=0; i<e; i++)
      if (!(Gl[Lv[i]]>R[i] || Gr[Lv[i]]<L[i]))
        u[V[i]]=uit;
    int res=0;
    for (i=0; i<e; i++)
      if (u[i]==uit)
        res++;
    uit++;
    printf("%d\n", res);  
  }
  TIMESTAMP(end);
  return 0;
}