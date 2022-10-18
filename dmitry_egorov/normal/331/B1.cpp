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
                         
int P[310000], R[310000];
int A[(1<<20)+100], n;

void add (int v, int d)
{
  v+=(1<<19);
  while (v)
    A[v]+=d, v>>=1;
}

int sum (int l, int r)
{
  l+=(1<<19), r+=(1<<19);
  int ret=0;
  while (l<r)
  {
    if (l&1)
      ret+=A[l], l--;
    if (r&1) 
      r--, ret+=A[r];
    l>>=1, r>>=1;
  }
  return ret;
}

void recalc (int v, int w)
{
  if (v>0 && P[v-1]>P[v])
    add(v-1,w);
  if (v<n-1 && P[v]>P[v+1])  
    add(v,w);
}

int main()
{
  int i, q, x, y, tp;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d", &R[i]), R[i]--, P[R[i]]=i;
  for (i=0; i<n-1; i++)
    if (P[i]>P[i+1])
      add(i,1);
  scanf("%d", &q);
  while (q>0)  
  {

   /* printf("QQQQ\n\n\n");
    for (i=0; i<n; i++)
      printf("%d ", R[i]+1);
    printf("\n\n");
    for (i=0; i<n; i++)
      printf("%d ", P[i]+1);
    printf("\n\n\n"); */

    q--, scanf("%d%d%d", &tp, &x, &y), x--, y--;
    if (tp==1)
    {
      int ret=0;
      for (i=x; i<y; i++)
        if (P[i]>P[i+1])
          ret++;
      printf("%d\n", ret+1);
      //printf("%d\n", sum(x,y)+1);
      continue;
    }
    x=R[x], y=R[y];
    if (x>y)
      swap(x,y);
    recalc(x,-1);
    recalc(y,-1);
    if (x+1==y && P[x]>P[y])
      add(x,1);
    swap(P[x],P[y]), R[P[x]]=x, R[P[y]]=y;
    recalc(x,1);
    recalc(y,1);
    if (x>y)
      swap(x,y);
    if (x+1==y && P[x]>P[y])
      add(x,-1);

  }
  TIMESTAMP(end);
  return 0;
}