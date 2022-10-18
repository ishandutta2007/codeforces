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

int A[4100], n, S[4100];
             
int main()
{
  int i, tmp;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d", &n);
  for (i=0; i<2*n; i++)
    scanf("%d.%d", &tmp, &A[i]);
  sort(A,A+2*n);
  for (i=0; i<2*n; i++)
    S[i+1]=S[i]+A[i];
  int res=inf;
  for (i=0; i<=n; i++)
    if (i==0 || A[i-1]==0)
      res=min(res,abs(S[i+n]-S[i]-1000*(n-i)+(S[2*n]-S[i+n])));
  printf("%d.%03d\n", res/1000, res%1000); 
  TIMESTAMP(end);
  return 0;
}