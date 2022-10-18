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

int Q[123123], W[123123];
                
int calc (int v)
{
  if (v%2==1)
    return (v*(v-1))/2+1;
  return (v*(v-1)/2)+v/2;
}

int main()
{
  int i, n, m;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  //for (i=1; i<=6; i++)
  //  cerr<<i<<" "<<calc(i)<<endl;
  scanf("%d%d", &n, &m);
  for (i=0; i<m; i++)
    scanf("%d%d", &Q[i], &W[i]);
  sort(W,W+m); 
  reverse(W,W+m);
  int cnt=1;
  while (calc(cnt+1)<=n)
    cnt++;
  cnt=min(cnt,m);
  ll res=0;
  for (i=0; i<cnt; i++)
    res+=W[i];
  printf("%I64d\n", res);
  TIMESTAMP(end);
  return 0;
}