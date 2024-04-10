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

int A[80], e;
                  
int main()
{
  ll n;
  int i, cnt=0, res=0;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  cin>>n;
  ll m=n;
  while (n)  
    A[e++]=n%3, n/=3;
  for (cnt=0, i=e; i>=0; i--)
  {
    bool fl=0;
    for (int j=0; j<i; j++)
      if (A[j])
        fl=1;
    if (fl)
      res=max(res,cnt+A[i]+1);
    cnt+=A[i];
  }
  while (m%3==0)
    m/=3;
  cout<<max((ll)res,(m+2ll)/3ll)<<endl;
  TIMESTAMP(end);
  return 0;
}