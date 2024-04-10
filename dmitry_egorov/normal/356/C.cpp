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

int res=inf, sum, A[1123123], S[1123123];
          
int main()
{
  int i, n;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d", &A[i]), sum+=A[i];
  sort(A,A+n); 
  reverse(A,A+n);
  for (i=0; i<n; i++)
    S[i+1]=S[i]+A[i];
  int fr=0, nd=0, lf;
  for (i=0; i<=n; fr+=4-A[i], nd+=max(0,3-A[i]), i++)
  {
    lf=sum-S[i];
    if (lf>fr)  
      continue;
    if (nd<=lf)
      res=min(res,lf);
    if (nd>=lf && sum>=3*i)
      res=min(res,nd);
  }
  if (res==inf)
    puts("-1");
  else
    printf("%d\n", res);
  TIMESTAMP(end);
  return 0;
}