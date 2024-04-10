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

int n, m;
ll A[110000], B[110000];
    
bool solve (ll d)
{
  int e=0;
  ll b, df;
  for (int i=0; i<n && e<m; i++)
  {
    b=B[e], df=abs(b-A[i]);
    if (df>d)
      continue;
    while (e<m && min(df+B[e]-b,abs(B[e]-A[i])+B[e]-b)<=d)
      e++;
  }
  return e==m;
}

int main()
{
  int i;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d", &n, &m);
  for (i=0; i<n; i++)
    scanf("%I64d", &A[i]);
  for (i=0; i<m; i++)
    scanf("%I64d", &B[i]);  
  ll l=-1, r=1e12;
  while (r-l>1)
    solve((l+r)/2)?(r=(l+r)/2):(l=(l+r)/2);
  printf("%I64d\n", r);
  TIMESTAMP(end);
  return 0;
}