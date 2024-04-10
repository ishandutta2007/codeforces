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

ll L[123123];
int V[123123], C[123123], Tp[123123];
               
int main()
{
  ll v;
  int i, n, q, it, res=-1;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d", &n);
  for (i=0; i<n; i++)
  {
    scanf("%d", &Tp[i]);
    if (Tp[i]==1)
    {
      L[i+1]=L[i]+1;
      scanf("%d", &V[i]);
      continue;
    }
    scanf("%d%d", &V[i], &C[i]); 
    L[i+1]=L[i]+V[i]*C[i];
  } 
  L[n+1]=1e18;
  for (scanf("%d", &q); q>0; q--)
  {
    scanf("%I64d", &v);
    while (true)
    {
      it=lower_bound(L,L+n+1,v)-L, it--;
      #ifdef LOCAL
      assert(L[it]<v && v<=L[it+1]);
      #endif
      if (Tp[it]==1)
      {
        res=V[it];
        break;
      }
      v=(v-L[it]-1)%V[it]+1;  
    }
    printf("%d ", res);
  }
  printf("\n");
  TIMESTAMP(end);
  return 0;
}