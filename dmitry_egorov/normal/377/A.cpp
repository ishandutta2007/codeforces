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

char s[510][510];
vi G[510*510];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int n, m;
set<pii> S;
int Deg[510*510];
bool u[510][510];

void dfs (int x, int y)
{
  u[x][y]=1;
  for (int i=0; i<4; i++)
  {
    int nx=x+dx[i];
    int ny=y+dy[i];
    if (s[nx][ny]=='.' && (!u[nx][ny]))
      dfs(nx,ny), G[x*(m+1)+y].pb(nx*(m+1)+ny), G[nx*(m+1)+ny].pb(x*(m+1)+y);
  }
}
                      
int main()
{
  int i, cnt, j;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d%d ", &n, &m, &cnt);
  for (i=1; i<=n; i++)
    gets(s[i]+1);
  bool fl=1;
  for (i=1; i<=n && fl; i++)
    for (j=1; j<=m; j++)
      if (s[i][j]=='.')
      {
        dfs(i,j);
        fl=1;
        break;
      }
  for (i=0; i<(n+1)*(m+1); i++)
    if (G[i].size())
      Deg[i]=G[i].size(), S.insert(mp(Deg[i],i));
  while (cnt)
  {
    cnt--;
    int v=S.begin()->second;
    S.erase(S.begin());
    assert(Deg[v]==1);
    for (i=0; i<(int)G[v].size(); i++)
    {
      int nv=G[v][i];
      if (Deg[nv]==0)
        continue;
      S.erase(mp(Deg[nv],nv)), Deg[nv]--, S.insert(mp(Deg[nv],nv));
    }
    Deg[v]=0;
    s[v/(m+1)][v%(m+1)]='X';
  }
  for (i=1; i<=n; i++)
    puts(s[i]+1);
  TIMESTAMP(end);
  return 0;
}