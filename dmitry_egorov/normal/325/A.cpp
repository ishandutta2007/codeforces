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

ll s, x1, x2, Y1, y2, xm=1e10, ym=1e10, xM, yM;
              
int main()
{
  int i, n;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d", &n);
  for (i=0; i<n; i++)
  {
    cin>>x1>>Y1>>x2>>y2;  

    xm=min(xm,x1), xM=max(xM,x1);
    xm=min(xm,x2), xM=max(xM,x2);

    ym=min(ym,Y1), yM=max(yM,Y1);
    ym=min(ym,y2), yM=max(yM,y2);

    s+=(x2-x1)*(y2-Y1);
  }
  (s==(xM-xm)*(yM-ym) && (xM-xm)==(yM-ym))?(puts("YES")):(puts("NO"));
  TIMESTAMP(end);
  return 0;
}