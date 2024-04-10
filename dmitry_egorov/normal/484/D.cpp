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

const ll inf = 1e18;
const double eps = 1e-9;
const double INF = inf;
const double EPS = eps;

const int maxn = (1<<20)+123;

ll T[2][2*maxn], res;
int X[maxn], x, n, A[maxn]; 

ll get (int id, int l, int r)
{
  l+=(1<<20), r+=(1<<20);
  ll ret=-inf;
  while (l<r)
  {
    if (l&1)
      ret=max(ret,T[id][l]), l++;
    if (r&1)
      r--, ret=max(ret,T[id][r]);
    l>>=1, r>>=1;
  }
  return ret;
}
 
void relax (int id, int v, ll val)
{
  v+=(1<<20);
  while (v && T[id][v]<val)
    T[id][v]=val, v>>=1;
}

int main()
{

  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif 
  scanf("%d", &n);
  for (int i=0; i<n; i++)
    scanf("%d", &A[i]), X[i]=A[i];
  sort(X,X+n);
  x=unique(X,X+n)-X;
  for (int i=0; i<n; i++)
    A[i]=lower_bound(X,X+x,A[i])-X;
  for (int i=0; i<(1<<21); i++)
    T[0][i]=-inf, T[1][i]=-inf;
  for (int i=0; i<n; i++)
  {
    ll v1=X[A[i]]+get(0,0,A[i]), v2=get(1,A[i]+1,x)-X[A[i]];
    ll pres=res;
    res=max(res,max(v1,v2));
    relax(0,A[i],pres-X[A[i]]);
    relax(1,A[i],pres+X[A[i]]);
  }
  cout<<res<<endl;
  TIMESTAMP(end);
  return 0;
}