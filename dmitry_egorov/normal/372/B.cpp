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

char s[60];
int n, m, q, F[60][60];
int A[43][43][43][43];
 
int main()
{
  int x, y, i, j;
  int a, b, c, d;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d%d ", &n, &m, &q);
  for (i=0; i<n; i++)
  {
    gets(s);
    for (j=0; j<m; j++)
      if (s[j]=='1')
        F[i+1][j+1]=1;
  }  
  for (i=1; i<=n; i++)
    for (j=1; j<=m; j++)
      F[i][j]+=F[i-1][j]+F[i][j-1]-F[i-1][j-1];
  for (x=n; x>=1; x--)
    for (y=m; y>=1; y--)
    {
      for (i=x; i<=n; i++)
        for (j=y; j<=m; j++)
        {
          if (F[i][j]-F[x-1][j]-F[i][y-1]+F[x-1][y-1]==0)
            A[x][y][i][j]=1;
          A[x][y][i][j]+=A[x][y][i-1][j]+A[x][y][i][j-1]-A[x][y][i-1][j-1];
        }
      for (i=x; i<=n; i++)
        for (j=y; j<=m; j++)
          A[x][y][i][j]+=A[x+1][y][i][j]+A[x][y+1][i][j]-A[x+1][y+1][i][j];
    }
  while (q)
  {
    q--, scanf("%d%d%d%d", &a, &b, &c, &d);
    //cerr<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    printf("%d\n", A[a][b][c][d]);
  }
  TIMESTAMP(end);
  return 0;
}