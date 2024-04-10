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

inline void madd (int& a, int b)
{
  a+=b;
  if (a>=mod)
    a-=mod;
}

vi G[2100];
int D[2100][2100];
           
int main()
{
  int n, m, i, j, k;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif      
  scanf("%d%d", &n, &m);
  for (i=1; i<=n; i++)
    for (j=1; j<=i; j++)
      if (i%j==0)
        G[i].pb(j);
  D[0][1]=1;
  for (i=1; i<=m; i++)
    for (j=1; j<=n; j++)
      for (k=0; k<(int)G[j].size(); k++)
        madd(D[i][j],D[i-1][G[j][k]]);
  int res=0;
  for (i=1; i<=n; i++)
    madd(res,D[m][i]);
  printf("%d\n", res);
  TIMESTAMP(end);
  return 0;
}