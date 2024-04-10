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

char s[1010][110];
int D[1010], Tp[1010];
int sz;
vpii V;
int res;
bool u[1010];

int dist (int a, int b)
{
  int cnt=0;
  for (int i=0; i<sz; i++)
    cnt+=(int)(s[a][i]!=s[b][i]);
  return cnt;
}

int main()
{
  int i, n, m, w, j, num;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d%d%d", &n, &m, &num, &w), sz=n*m;
  for (i=0; i<num; i++)
  {
    for (j=0; j<n; j++)
      scanf(" %s", s[i]+(j*m));  
    //cerr<<s[i]<<endl;
  }
  for (i=0; i<num; i++)
    D[i]=sz;
  for (int it=0; it<num; it++)
  {
    int v=-1, val=inf;
    for (i=0; i<num; i++)
      if ((!u[i]) && val>D[i])
        val=D[i], v=i;
    assert(v!=inf);
    res+=D[v], V.pb(mp(v+1,Tp[v]));
    u[v]=1;
    for (i=0; i<num; i++)
    {
      if (u[i])
        continue;
      int tmp=dist(v,i)*w;
      if (tmp<D[i])
        D[i]=tmp, Tp[i]=v+1;
    }
  }
  printf("%d\n", res);
  assert((int)V.size()==num);
  for (i=0; i<(int)V.size(); i++)
    printf("%d %d\n", V[i].first, V[i].second);
  TIMESTAMP(end);
  return 0;
}