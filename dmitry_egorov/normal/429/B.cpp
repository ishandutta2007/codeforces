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

int A[1010][1010], D[4][1010][1010], res;
  
int main()
{
  int i, j, x, y, n, m, it;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d", &n, &m);
  for (i=0; i<n; i++)
    for (j=0; j<m; j++)
      scanf("%d", &A[i+1][j+1]);
  for (it=0; it<4; it++)
  {  
    int sx, dx, sy, dy;
    if (it&1)
      sx=n, dx=-1;
    else
      sx=1, dx=1;
    if (it&2)
      sy=m, dy=-1;
    else
      sy=1, dy=1;
    for (x=sx, i=0; i<n; i++, x+=dx)
      for (y=sy, j=0; j<m; j++, y+=dy)
        D[it][x][y]=A[x][y]+max(D[it][x-dx][y],D[it][x][y-dy]);
  } 
  for (i=2; i<n; i++)
    for (j=2; j<m; j++)
    {
      res=max(res,D[0][i-1][j]+D[3][i+1][j]+D[1][i][j-1]+D[2][i][j+1]);
      res=max(res,D[0][i][j-1]+D[3][i][j+1]+D[1][i+1][j]+D[2][i-1][j]);
    }
  printf("%d\n", res);
  TIMESTAMP(end);
  return 0;
}