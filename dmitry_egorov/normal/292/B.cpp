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

const int inf = 1e9;
const double eps = 1e-9;
const double INF = inf;
const double EPS = eps;

vector <int> G[110000];

int main(){
  int n, m, v1, v2, i, mn=inf, mx=-inf;
  #ifdef LOCAL
  freopen(TASKNAME"a.in","r",stdin);
  //freopen(TASKNAME"a.out","w",stdout);
  #endif
  scanf("%d%d", &n, &m);
  for (i=0; i<m; i++)
    scanf("%d%d", &v1, &v2), v1--, v2--, G[v1].pb(v2), G[v2].pb(v1);
  for (i=0; i<n; i++)
    mn=min(mn,(int)G[i].size()), mx=max(mx,(int)G[i].size());
  if (m==n-1 && mn==1 && mx==2)
  {
    puts("bus topology");
    return 0;
  }
  if (m==n && mn==2 && mx==2)
  {
    puts("ring topology");
    return 0;
  }
  if (m==n-1 && mn==1 && mx==n-1)
  {
    puts("star topology");
    return 0;
  }
  puts("unknown topology");
  TIMESTAMP(end);
  return 0;
}