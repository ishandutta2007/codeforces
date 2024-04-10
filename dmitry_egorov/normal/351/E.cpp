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

int A[2100], n, e, B[2100], res;
int P[2100], S[2100];
   
int main()
{
  int i;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d", &A[i]), A[i]=abs(A[i]);  
  while (n>0)
  {
    int m=-1;
    for (i=0; i<n; i++)
      m=max(A[i],m);
    assert(m>=0);
    if (m==0)
      break;
    P[0]=0;
    for (i=0; i<n; i++)
      if (i)
      {
        P[i]=P[i-1];
        if (A[i-1]<m)
          P[i]++;
      }
    S[n-1]=0;
    for (i=n-1; i>=0; i--)
      if (i!=n-1)
      {
        S[i]=S[i+1];
        if (A[i+1]<m)
          S[i]++;
      }
    e=0;
    for (i=0; i<n; i++)
    {
      if (A[i]==m)
        res+=min(S[i],P[i]);
      else
        B[e++]=A[i];
    }
    for (i=0; i<e; i++)
      A[i]=B[i];
    n=e;
  }
  printf("%d\n", res);
  TIMESTAMP(end);
  return 0;
}