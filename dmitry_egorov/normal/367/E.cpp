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
const int mod = 1000000007;

int D[510][510], ND[510][510];
  
int main()
{
  int n, m, x, i, j, v;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d%d", &n, &m, &x), x--;
  if (m<n) 
  {
    puts("0");
    return 0;
  }
  D[0][0]=1;
  for (v=0; v<m; v++)
  {
    for (i=0; i<=n; i++)
      for (j=0; j<=i; j++)
      {
        if (!D[i][j])
          continue;
        //cerr<<v<<" "<<i<<" "<<j<<" "<<D[i][j]<<endl;
        if (i!=n)
        {
          ND[i+1][j]+=D[i][j];
          if (ND[i+1][j]>=mod)
            ND[i+1][j]-=mod;
          if (j<=i)
          {
            ND[i+1][j+1]+=D[i][j];
            if (ND[i+1][j+1]>=mod)
              ND[i+1][j+1]-=mod;
          }
        }
        if (v==x)
          continue;
        ND[i][j]+=D[i][j];
        if (ND[i][j]>=mod)
          ND[i][j]-=mod;
        if (j<i)
        {
          ND[i][j+1]+=D[i][j];
          if (ND[i][j+1]>=mod)
            ND[i][j+1]-=mod;
        }
      }
    for (i=0; i<=n; i++)
      for (j=0; j<=n; j++)
        D[i][j]=ND[i][j], ND[i][j]=0;
  }
  int res=D[n][n];
  while (n>1)
    res=(res*1ll*n)%mod, n--;
  printf("%d\n", res);
  TIMESTAMP(end);
  return 0;
}