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

int dt, n, sz, res, t;
pii A[1100];

int main(){
  int i;
  #ifdef LOCAL
  freopen(TASKNAME"a.in","r",stdin);
  //freopen(TASKNAME"a.out","w",stdout);
  #endif
  
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d%d", &A[i].first, &A[i].second);
  sort(A,A+n);
  for (i=0; i<n; i++)
  {
    dt=A[i].first-t, sz=max(sz-dt,0), sz+=A[i].second, t=A[i].first, res=max(res,sz);
  } 
  printf("%d %d\n", t+sz, res);
  TIMESTAMP(end);
  return 0;
}