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

int A[110000], e=1, St[110000], B[110000], id;
ll D[110000];
pll P[110000];
                         
bool cmp (int a, int b, int c)
{
  ld x=(D[c]-D[b])*1.0*(B[a]-B[b]);
  ld y=(D[b]-D[a])*1.0*(B[b]-B[c]);
 // cout<<x<<" ???  "<<y<<"     "<<x-y<<endl;
  if (x-y<-4e18)
    return 1;
  if (x-y>4e18)
    return 0;
  return (D[c]-D[b])*1ll*(B[a]-B[b])-(D[b]-D[a])*1ll*(B[b]-B[c])<=0ll;
}

int main()
{
  int i, n;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d", &A[i]);
  for (i=0; i<n; i++)
    scanf("%d", &B[i]);
  for (i=1; i<n; i++)
  {
    id=min(id,e-1);
    while (id<e-1 && A[i]*1ll*(B[St[id]]-B[St[id+1]])>D[St[id+1]]-D[St[id]])
      id++;
  //  cout<<id<<endl;
    D[i]=D[St[id]]+A[i]*1ll*B[St[id]];
  //  printf("%d %I64d    %I64d\n", i, D[i], D[4]+A[i]*1ll*B[4]);
    while (e>1 && cmp(St[e-2],St[e-1],i))  
      e--;
    St[e++]=i;
 //   printf("ST     %d\n", e);
 //   for (int j=0; j<e; j++)
 //     printf("%d ", St[j]);
 //   printf("\n");
  }
  printf("%I64d\n", D[n-1]);  
  TIMESTAMP(end);
  return 0;
}