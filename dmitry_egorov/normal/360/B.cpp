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

int n, m, D[2100], A[2100];
                         
int solve (int r)
{
  int i, j, ret=n-1;
  for (i=1; i<n; i++)
  {
    D[i]=i;
    for (j=i-1; j>=0; j--)
      if ((abs(A[i]-A[j])+i-j-1)/(i-j)<=r)
        D[i]=min(D[i],D[j]+i-j-1);
    ret=min(ret,D[i]+n-i-1);
   // cerr<<"???  "<<i<<"     "<<D[i]<<"     "<<ret<<endl;
  }
//  cerr<<r<<"    "<<ret<<endl;
  return ret;
}

int main()
{
  int i;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d", &n, &m);
  if (m>=n-1)
  {
    puts("0");
    return 0;
  }
  for (i=0; i<n; i++)
  {
    scanf("%d", &A[i]);
    assert(-inf<=A[i] && A[i]<=inf);
  }
  int l=-1, r=2*inf+10;
  while (r-l>1)
  {
    int mid=(((ll)l)+((ll)r))/2ll;
    (solve(mid)<=m)?(r=mid):(l=mid);
  }
  printf("%d\n", r);
  TIMESTAMP(end);
  return 0;
}