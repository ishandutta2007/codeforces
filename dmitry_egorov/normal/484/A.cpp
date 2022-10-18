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
                         
int main()
{
  int n;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif 
  scanf("%d", &n);
  while (n)
  {
    n--;
    ll l, r, res=-1ll;
    scanf("%I64d%I64d", &l, &r);
    for (int i=61; i>=0; i--)
    {
      if ((l>>i)==(r>>i))
        continue;
      if (r==((r>>i)<<i)+(1ll<<i)-1ll)
        res=r;
      else
        res=((l>>i)<<i)+(1ll<<i)-1ll;
      break;
    }
    if (l==r)
      res=l;
    assert(res>=0ll);
    printf("%I64d\n", res);
  }
  TIMESTAMP(end);
  return 0;
}