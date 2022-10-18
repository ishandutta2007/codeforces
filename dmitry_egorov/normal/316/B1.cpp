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
                         
bool D[1100];
int n, A[1100], Len[1100], Next[1100];
vi V;

int main()
{
  int i, x, len, j, t;
  bool fl;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d", &n, &x), x--;
  memset(Next,-1,sizeof(Next));
  for (i=0; i<n; i++)
  {
    scanf("%d", &A[i]), A[i]--;
    if (A[i]>=0)
      Next[A[i]]=i;
  }
  for (i=0; i<n; i++)
    if (A[i]==-1)
    {
      fl=0, t=i, len=0;
      while (t!=-1)
      {
        if (t==x)
          fl=1;
        len++, Len[t]=len, t=Next[t];
      }
      if (!fl)
        V.pb(len);
    }
  D[0]=1;
  for (i=0; i<(int)V.size(); i++)
    for (j=1100; j>=0; j--)
      if (D[j])
        D[j+V[i]]=1;
  for (i=0; i<=n; i++)
    if (D[i])
      printf("%d\n", i+Len[x]);
  TIMESTAMP(end);
  return 0;
}