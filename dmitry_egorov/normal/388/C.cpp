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

int res1, res2;
multiset<int> S;
  
int main()
{
  int n, tmp, tmp2, i, j;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d", &n);
  for (i=0; i<n; i++)
  {
    scanf("%d", &tmp);
    for (j=0; j<tmp; j++)
    {
      scanf("%d", &tmp2);
      if (tmp%2==1 && j==tmp/2)
        S.insert(-tmp2);
      if (j<tmp/2)
        res1+=tmp2;
      if (tmp-1-j<tmp/2)
        res2+=tmp2;
    }
  }  
  bool tp=0;
  while (S.size())
  {
    if (!tp)
      res1-=*S.begin();
    else
      res2-=*S.begin();
    S.erase(S.begin());
    tp=!tp;
  }
  printf("%d %d\n", res1, res2);
  TIMESTAMP(end);
  return 0;
}