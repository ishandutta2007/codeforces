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

int Res[310000];
set <int> S;
set <int> :: iterator it;
                     
int main()
{
  int n, m, x, i, l, r;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d", &n, &m);
  for (i=0; i<n; i++)
    S.insert(i);
  while (m>0)
  {
    m--;
    scanf("%d%d%d", &l, &r, &x), l--, r--, x--;  
    it=S.lower_bound(l);
    while (it!=S.end() && (*it)<=r)
      Res[*it]=x, S.erase(it), it=S.lower_bound(l);
    S.insert(x);
  }
  for (i=0; i<n; i++)
  {
    if (Res[i]==i)
      Res[i]=-1;
    printf("%d ", Res[i]+1);
  }
  printf("\n");
  TIMESTAMP(end);
  return 0;
}