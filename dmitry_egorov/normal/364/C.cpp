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

bool u[8123];
vi Pr;
int n, r, ep;
int e, ne, Res[61232];

bool check ()
{
  int i;
  for (i=0; i<ep; i++)
  {
    int cnt=0;
    for (int j=e-n; j<e; j++)
      if (Res[j]%Pr[i]==0)
        cnt++;
    if (cnt!=0 && 2*cnt<n)
      return 0;
  }
  return 1;
}

void solve (int _n)
{
  int i, tmp;
  n=_n, r=2*n*n;
  e=1, Res[0]=1, ep=0;
  while (e<n)
  {
    ne=e;
    for (i=0; i<e; i++)
    {
      tmp=Res[i];
      while (tmp*1ll*Pr[ep]<=r)
        tmp*=Pr[ep], Res[ne++]=tmp;
    }
    e=ne, ep++;
  }
  assert(check());
  for (i=e-n; i<e; i++)
    printf("%d ", Res[i]);
  printf("\n");
}
              
int main()
{
  int n, i, j;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  for (i=2; i<8123; i++)
   if (!u[i])  
   {
     Pr.pb(i);
     for (j=i*i; j<8123; j+=i)
       u[j]=1;
   }
  scanf("%d", &n),
  solve(n);
/*  for (int i=10; i<=5000; i++)
  {
    solve(i);
    cerr<<i<<endl;
  }   */
  TIMESTAMP(end);
  return 0;
}