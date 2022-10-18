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

const int maxn = 123123;

int n, m; 
pii Ev[maxn];
vpii D, ND;
int curx;

int main()
{
  int i, x, y, nit, it=0;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d", &n, &m);
  assert(m>=1);
  for (i=0; i<m; i++)
    scanf("%d%d", &x, &y), x--, y--, Ev[i]=mp(x,y);
  sort(Ev,Ev+m);
  if (Ev[0].first)
    D.pb(mp(0,n-1));
  else
  {
    D.pb(mp(0,Ev[it].second-1));
    while (it<m && Ev[it].first==0)
      it++;
  } 
  for ( ; it<m; D.swap(ND), ND.clear(), it=nit)
  {
    if (!D.size())
    {
      puts("-1");
      return 0;
    }
    if (curx+1<Ev[it].first)
    {
      curx=Ev[it].first-1;
      ND.pb(mp(D[0].first,n-1));
      D.swap(ND), ND.clear();
    }
    nit=it+1;
    while (nit<m && Ev[nit].first==Ev[it].first)
      nit++;
    int cur=0;
    for (i=it; cur<(int)D.size() && i<nit; i++)
    {
      int y=Ev[i].second;
      if (D[cur].first>y)
        continue;
      if (D[cur].first==y)
      {
        D[cur].first=y+1;
        if (D[cur].first>D[cur].second)
          cur++;
        continue;
      }
      ND.pb(mp(D[cur].first,y-1));
      while (cur<(int)D.size() && D[cur].second<=y)
        cur++;
      if (cur<(int)D.size())
        D[cur].first=max(D[cur].first,y+1);
    }
    if (cur<(int)D.size())
      ND.pb(mp(D[cur].first,n-1));
    curx=Ev[it].first;
  }
  if (curx<n-1 && D.size())
  {
    printf("%d\n", 2*n-2);
    return 0;
  }
  if (D.size() && D.back().second==n-1)
    printf("%d\n", 2*n-2);
  else
    puts("-1");
  TIMESTAMP(end);
  return 0;
}