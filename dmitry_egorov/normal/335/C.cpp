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

int G[110][110][3][3];
bool U[110][210];
bool F[110][3];

int solve (int l, int r, int m1, int m2)
{
  if (l>r)
    return 0;
  if (G[l][r][m1][m2]!=-1)
    return G[l][r][m1][m2];
  memset(U[r-l],0,sizeof(U[r-l]));
  int m3;
  for (int x=l; x<=r; x++)
    for (int y=0; y<2; y++)
    {
      if (F[x][0] || F[x][1])
        continue;
      if ((x!=l && F[x-1][y^1]) || (x==l && m1==(y^1)+1))
        continue;
      if ((x!=r && F[x+1][y^1]) || (x==r && m2==(y^1)+1))
        continue;
      m3=y+1;
      U[r-l][solve(l,x-1,m1,m3)^solve(x+1,r,m3,m2)]=1;
    }
  int tmp=0;
  while (U[r-l][tmp])
    tmp++;
  G[l][r][m1][m2]=tmp;
  return tmp;
}
         
int main()
{
  int n, m, i, x, y;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d", &n, &m);
  for (i=0; i<m; i++)
    scanf("%d%d", &x, &y), y--, F[x][y]=1;
  memset(G,-1,sizeof(G));  
  (solve(1,n,0,0)==0)?(puts("LOSE")):(puts("WIN"));
  TIMESTAMP(end);
  return 0;
}