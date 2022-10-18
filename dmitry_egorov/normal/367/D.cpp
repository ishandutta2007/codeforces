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

bool F[(1<<20)+100];
int A[123123], C[23];
int res=inf;

int main()
{
  int n, m, d, i, j, tmp, x;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d%d", &n, &m, &d);
  for (i=0; i<m; i++)
    for (scanf("%d", &tmp), j=0; j<tmp; j++)
      scanf("%d", &x), A[x-1]=i;
  int mask=0;
  for (i=0; i<n; i++)
  {
    if (C[A[i]]==0)
      mask+=(1<<A[i]);
    C[A[i]]++;
    if (i>=d-1)
    {
      //cerr<<i<<" ??? "<<mask<<endl;
      F[(1<<m)-1-mask]=1;
      C[A[i-d+1]]--;
      if (C[A[i-d+1]]==0)
        mask-=(1<<A[i-d+1]);
    }
  }  
  for (i=(1<<m)-1; i>=0; i--)
  {
  //  cerr<<i<<" "<<F[i]<<endl;
    if (!F[i])
    {
      res=min(res,__builtin_popcount(i));
      continue;
    }
    for (j=0; j<m; j++)
      if (i&(1<<j))
        F[i-(1<<j)]=1;
  }
//  cerr<<res<<endl;
  assert(res<inf && res>0);
  printf("%d\n", res);
  TIMESTAMP(end);
  return 0;
}