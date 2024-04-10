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

const int mod=inf+7;
           
int res, A[1100], D[20123], ND[20123];

int main()
{
  int i, j, n;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d", &A[i]);
  D[10000]=1;
  for (i=0; i<n; i++)
  {
    for (j=A[i]; j<=20000-A[i]; j++)
    {
      ND[j-A[i]]+=D[j];
      if (ND[j-A[i]]>=mod)
        ND[j-A[i]]-=mod;
      ND[j+A[i]]+=D[j];
      if (ND[j+A[i]]>=mod)
        ND[j+A[i]]-=mod;
    }
    memcpy(D,ND,sizeof(ND));
    memset(ND,0,sizeof(D));
    res+=D[10000], res%=mod;
    D[10000]++, D[10000]%=mod;
  }  
  printf("%d\n", res);
  TIMESTAMP(end);
  return 0;
}