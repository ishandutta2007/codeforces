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
          
int deg (int v, int d)
{
  if (d==0)
    return 1;
  if (d&1)
    return (v*1ll*deg(v,d-1))%mod;
  return deg((v*1ll*v)%mod,d/2);
}

int C[2010][2010];
int F[2010];
bool In[2010];
int A[2010];

int main()
{
  int i, a=0, b=0, n, j;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  for (i=0; i<2010; i++)
    for (C[i][0]=1, j=1; j<=i; j++)
    {
      C[i][j]=C[i-1][j-1]+C[i-1][j];
      if (C[i][j]>=mod)
        C[i][j]-=mod;
    }       
  for (F[0]=1, i=1; i<2010; i++)
    F[i]=(F[i-1]*1ll*i)%mod;
  scanf("%d", &n);
  for (i=1; i<=n; i++)
  {
    scanf("%d", &A[i]);  
    (A[i]==-1)?(a++):(In[A[i]]=1);
  }
  for (i=1; i<=n; i++)
    if (A[i]==-1 && (!In[i]))
      b++;
  a-=b;
  //cerr<<"!!! "<<a<<" "<<b<<endl;
  ll res=0;
  for (i=0; i<=b; i++)
  {
    ll add=(F[a+b-i]*1ll*C[b][i])%mod;
    //cerr<<i<<" "<<add<<endl;
    if ((i&1)==0)
      res+=add, res%=mod;
    else
      res+=mod-add, res%=mod;
  }
  printf("%d\n", (int)res);
  TIMESTAMP(end);
  return 0;
}