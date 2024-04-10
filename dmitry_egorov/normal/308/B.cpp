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

const int mil = 1123123;

char s[11*mil];
int E[mil], e, FN[mil], N[mil], R[mil], res, n, r, c;
             
int main()
{
  int i, j, k, len, b=-1;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d%d ", &n, &r, &c), c++;
  gets(s), len=strlen(s)+1, s[len-1]=' ', E[0]=-1;  
  for (e=0, i=0; i<len; i++)
    if (s[i]==' ')
      e++, E[e]=i;// cerr<<e<<" "<<i<<endl;
  assert(e==n);
  for (i=0, j=0; i<=n; i++)
  {
    while (j<e && E[j+1]<=E[i]+c)
      j++;
    N[i]=j, FN[i]=j;
    //cerr<<i<<" "<<j<<endl;
  }
  for (i=0; i<n; i++)
    R[i]=i;
  for (i=0; i<20; i++)
  {
    if (r&(1<<i))
      for (k=0; k<n; k++)
        R[k]=N[R[k]];
    for (k=0; k<n; k++)
      N[k]=N[N[k]];
  }
  for (i=0; i<n; i++)
    if (res<R[i]-i)
      res=R[i]-i, b=i;
  //cerr<<res<<" !!! "<<b<<endl;
  if (b==-1)
    return 0;
  assert(FN[n]==n);
  for (i=0; i<r; i++)
  {
    if (FN[b]==b)
      break;
    printf("%s\n", string(s+E[b]+1,s+E[FN[b]]).c_str()), b=FN[b];
  }
  TIMESTAMP(end);
  return 0;
}