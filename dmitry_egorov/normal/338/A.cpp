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

#define mod (1000000009ll)

ll deg (ll v, int d)
{
  if (d==0)
    return 1ll;
  if (d&1)
    return (v*deg(v,d-1))%mod;
  return deg((v*v)%mod,d/2);
}
         
int main()
{
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif     
  int n, m, k;
  ll res;
  scanf("%d%d%d", &n, &m, &k);
  int f=n-m;
  if (f*1ll*(k-1)>=m)
  {
    cout<<m<<endl;
    return 0;
  }
  res=f*(k-1), m-=f*(k-1);
  int fg=(m%k);
  res+=fg, m-=fg, res%=mod;
  m/=k;
  //cerr<<res<<" "<<m<<endl;
  res+=k*2ll*(deg(2ll,m)+mod-1ll);
  res%=mod;
  cout<<res<<endl;
  TIMESTAMP(end);
  return 0;
}