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

pii Res[4];
ld res;
pii C[4];
int n, m;

void go (int v, ld c)
{
  if (res>c+(4-v)*sqrt((ld)(n*n+m*m)))
    return;
  if (v==4)
  {
    for (int i=0; i<4; i++)
      for (int j=i+1; j<4; j++)
        if (C[i]==C[j])
          return;
    if (res<c)
      res=c, memcpy(Res,C,sizeof(Res));
    return;
  }
  int sx=0, sy=0, dx=1, dy=1, y, j;
  if (v&1)
    sx=n, sy=m, dx=-1, dy=-1;
  for (int i=0; 0<=sx && sx<=n && i<10; i++, sx+=dx) 
  for (y=sy, j=0; 0<=y && y<=m && j<10; j++, y+=dy) 
  {
    ld nc=c;
    C[v]=mp(sx,y);
    if (v)
    {
      pii tmp=mp(C[v].first-C[v-1].first,C[v].second-C[v-1].second);
      nc+=sqrt(tmp.first*tmp.first+tmp.second*tmp.second);
    }
    go(v+1,nc);
  }
}
              
void solve (int _n, int _m)
{
  n=_n, m=_m;
  go(0,0.0);
}

int main()
{
  int nn, mm;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif 
  scanf("%d%d", &nn, &mm);
  solve(max(nn,mm),min(nn,mm));  
  if (nn<mm)
    for (int i=0; i<4; i++)
      swap(Res[i].first,Res[i].second);
  for (int i=0; i<4; i++)
    printf("%d %d\n", Res[i].first, Res[i].second);
  TIMESTAMP(end);
  return 0;
}