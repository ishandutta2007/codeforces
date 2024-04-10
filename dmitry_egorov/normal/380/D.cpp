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
const int mod = inf+7;

int deg (int v, int d)
{
  int ret=1;
  while (d>0)
  {
    if (d&1)
      ret=(ret*1ll*v)%mod;
    d/=2, v=(v*1ll*v)%mod;
  }
  return ret;
}

inline int inv (int v)
{
  return deg(v,mod-2);
}

int F[123123], e, n;
pii A[123123];

int calc (int l, int r)
{
  return (F[l+r]*1ll*inv((F[l]*1ll*F[r])%mod))%mod;
}
                         
int solve (int it, int l, int r)
{
  if (l<0 || r>=n)
    return 0;
  if (it==e)
    return calc(l,n-1-r);
  if (l<=A[it].second && A[it].second<=r)
    return 0;
  int len=A[it].first-A[it-1].first, dl, dr, coef=-1;
  if (A[it].second<l)
  {
    dl=l-A[it].second;
    dr=len-dl;
    if (dr<0)
      return 0;
    coef=calc(dl-1,dr);
  }
  else
  {
    dr=A[it].second-r;
    dl=len-dr;
    if (dl<0)
      return 0;
    coef=calc(dl,dr-1);
  }
  return (solve(it+1,l-dl,r+dr)*1ll*coef)%mod;
}

int main()
{
  int i, tmp;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d", &n);
  for (F[0]=1, i=1; i<123123; i++)
    F[i]=(F[i-1]*1ll*i)%mod;    
  for (i=0; i<n; i++)
  {
    scanf("%d", &tmp);
    if (tmp>0)
      A[e]=mp(tmp-1,i), e++;
  }
  if (e==0)
  {
    printf("%d\n", deg(2,n-1));
    return 0;
  }
  sort(A,A+e);
  if (A[0].first==0)
  {
    printf("%d\n", solve(1,A[0].second,A[0].second));
    return 0;
  }
  printf("%d\n", (int)((((solve(1,A[0].second-A[0].first,A[0].second)+solve(1,A[0].second,A[0].second+A[0].first))%mod)*1ll*deg(2,A[0].first-1))%mod));
  TIMESTAMP(end);
  return 0;
}