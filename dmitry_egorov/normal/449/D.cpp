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

inline void add (int& a, int b)
{
  a+=b;
  if (a>=mod)
    a-=mod;
}

inline void sub (int& a, int b)
{
  a-=b;
  if (a<0)
    a+=mod;
}
       
int n, W[1123123], C[(1<<20)+100];

int main()
{
  int i, j, tmp;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d", &tmp), C[tmp]++; 
  for (i=0; i<20; i++)
    for (j=0; j<(1<<20); j++)
      if (!(j&(1<<i)))
        C[j]+=C[j+(1<<i)];
  int res=0;
  for (i=1; i<1123123; i++)
    add(W[i],W[i-1]), add(W[i],W[i-1]+1);
  for (i=0; i<(1<<20); i++)
  {
    tmp=__builtin_popcount(i);
    (tmp&1)?(sub(res,W[C[i]])):(add(res,W[C[i]]));
  }
  cout<<res<<endl;
  TIMESTAMP(end);
  return 0;
}