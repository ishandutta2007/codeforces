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
                         
int mn=inf, n, d, A[1100000], res; 

int main()
{
  int i, j, x;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d", &n, &d);
  for (i=0; i<n; i++)
  {
    scanf("%d", &x), mn=min(mn,x); 
    if (x>=d)
      A[x+1]--, A[x-d]++;
  }
  if (mn<=d)
  {  
    printf("%d\n", mn);
    return 0;
  }
  for (i=0; i<1010000; i++)
    A[i+1]+=A[i];
  res=d;
  for (i=d+1; i<1100000; i++)
  {
    int tmp=0;
    for (j=i; j<1100000; j+=i)
      tmp+=A[j];
    if (tmp==n)
      res=i;
  }
  printf("%d\n", res);
  TIMESTAMP(end);
  return 0;
}