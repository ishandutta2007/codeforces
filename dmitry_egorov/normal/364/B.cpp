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

int res, D[1123123];
bool u[1123123];
set<pii> S;
  
int main()
{
  int n, d, i, c, j;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d", &n, &d);
  u[0]=1;
  for (i=0; i<n; i++)
  {
    scanf("%d", &c);
    for (j=1123000; j>=c; j--)
      if (u[j-c])
        u[j]=1;
  }
  S.insert(mp(0,0));
  for (i=1; i<1123000; i++)
  {
    if (i>=d+1 && u[i-d-1])
      S.erase(mp(D[i-d-1],i-d-1));
    if (!u[i])
      continue;
    //cerr<<i<<" "<<S.size()<<endl;
    if ((int)S.size()>0)
    {
      res=i;
      D[i]=S.begin()->first+1;
      S.insert(mp(D[i],i));
    }
  }
  printf("%d %d\n", res, D[res]);
  TIMESTAMP(end);
  return 0;
}