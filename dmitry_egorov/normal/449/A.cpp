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
  int i, n, m, k;
  ll res=0;
  /*#ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif*/
  scanf("%d%d%d", &n, &m, &k), k+=2;  
  if (n+m<k)
  {
    puts("-1");
    return 0;
  }
  for (int it=0; it<2; it++, swap(n,m))
  {
    for (i=1; i<=1231231 && i<k; i++)
      res=max(res,(n/i)*1ll*(m/(k-i)));
    for (i=1; i<=123123 && i<=n; i++)
    {
      int c=n/i;
      c=min(c,k-1);
      res=max(res,(n/c)*1ll*(m/(k-c)));
    }
  }
  cout<<res<<endl;
  TIMESTAMP(end);
  return 0;
}