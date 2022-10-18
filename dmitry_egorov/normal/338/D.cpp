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
          
ll kto (ll mod1, ll r1, ll mod2, ll r2)
{
  if (mod1<mod2)    
    return kto(mod2,r2,mod1,r1);
  ll ret=r1;
  while (ret%mod2!=r2)
    ret+=mod1;
  return ret;
}

vll V;
ll n, m, r=1, A[11000];
int len;

int main()
{
  int i, j;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  cin>>n>>m>>len;
  for (i=0; i<len; i++)
    scanf("%I64d", &A[i]);
  for (i=0; i<len; i++)
  {
    ll d=__gcd(A[i],r);
    if ((r*1.0*A[i])/((double)d)>1e13)
    {
      puts("NO");
      return 0;
    }
    r*=(A[i]/d);
  } 
  if (r>n)
  {
    puts("NO");
    return 0;
  }
  ll rr=r;
  for (i=2; i*1ll*i<=r; i++)
    if (r%i==0)
    {
      ll tmp=1;
      while (r%i==0)
        r/=i, tmp*=i;
      V.pb(tmp);
    }
  if (r>1)
    V.pb(r);
  r=rr;
  ll mod=1ll, res=0ll;
  for (i=0; i<len; i++)
    for (j=0; j<(int)V.size(); j++)
      if (mod%V[j]!=0 && A[i]%V[j]==0) 
      {
        res=kto(mod,res,V[j],(11000*V[j]-i)%V[j]);
        mod*=V[j];
      }
  res%=mod;
  if (res==0)
    res=mod;
  if (res+len-1>m)
  {
    puts("NO");
    return 0;
  }
  for (i=0; i<len; i++)
    if (A[i]!=__gcd(r,res+i))
    {
      puts("NO");
      return 0;
    }
  puts("YES");
  TIMESTAMP(end);
  return 0;
}