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

vi V;
ll res=-1e18;
int A[310000];
pii B[310000];
int x, y, n;
ll S[310000];
             
int main()
{
  int i, j;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d", &A[i]), B[i]=mp(A[i],i);
  for (i=0; i<n; i++)
    S[i+1]=S[i]+max(0,A[i]); 
  sort(B,B+n), i=0;
  while (i<n)
  {
    j=i;
    while (j<n && B[j].first==B[i].first)
      j++;
    if (j-i>1)
    {
      ll s=S[B[j-1].second]-S[B[i].second+1]+2ll*B[i].first;
      if (res<s)
        res=s, y=B[j-1].second, x=B[i].second;
    }
    i=j;
  }
  for (i=0; i<x; i++)
    V.pb(i);
  for (i=x+1; i<y; i++)
    if (A[i]<0)
      V.pb(i);
  for (i=y+1; i<n; i++)
    V.pb(i);
  printf("%I64d %d\n", res, V.size());
  for (i=0; i<(int)V.size(); i++)
    printf("%d ", V[i]+1);
  printf("\n");
  TIMESTAMP(end);
  return 0;
}