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

int n, res, A[212123];
       
int main()
{
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif 
  scanf("%d", &n);
  for (int i=0; i<n; i++)
    scanf("%d", &A[i]);
  sort(A,A+n);
  n=unique(A,A+n)-A;

  
  /*n=200000;
  for (int i=0; i<n; i++)
    A[i]=i+1;
  A[n-1]=1000000;*/
  

  for (int i=0; i<n; i++)
  {
    int t=A[i], c=i+1;
    while (c<n)
    {
      while (t<=A[c])  
        t+=A[i];
      c=lower_bound(A+c,A+n,t)-A;
      //cerr<<i<<" "<<c<<" "<<t<<" "<<A[c-1]<<endl;
      res=max(res,A[c-1]-t+A[i]);
    }
  }
  cout<<res<<endl;
  TIMESTAMP(end);
  return 0;
}