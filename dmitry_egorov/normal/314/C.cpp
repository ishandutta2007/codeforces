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

#define mod (1000000007)

ll A[(1<<21)+100], sum=1ll, res;       

ll get (int v)
{
  int ret=0;
  v+=(1<<20);
  while (v>0)
  {
    ret+=A[v], ret%=mod, v/=2;
    //if (A[v])
   //   cerr<<"!!!!"<<v<<endl;
  }
  return ret;
}

void add (int r, int d)
{
  int l=(1<<20);
  r+=(1<<20);
  while (l<r)
  {
    if ((r&1)==1)
      r--, A[r]+=d, A[r]%=mod;// cerr<<"!!!  "<<r<<"           "<<(1<<20)<<endl;
    l/=2, r/=2;
  }
}

int main()
{
  int n, tmp, i;
  ll coef;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d", &n);  
  for (i=0; i<n; i++)
  {
    scanf("%d", &tmp);
    ll a=get(tmp);
    //cerr<<a<<endl;
    coef=(sum+a)%mod, A[tmp+(1<<20)]+=mod-coef, A[tmp+(1<<20)]%=mod;
    coef*=tmp, coef%=mod, sum+=coef, sum%=mod, add(tmp,(mod-coef)%mod);
  }
  printf("%d\n", (int)((sum+mod-1)%mod));
  TIMESTAMP(end);
  return 0;
}