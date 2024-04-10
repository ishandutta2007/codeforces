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
                         

char s[110][110];
int n;

int main()
{
  int i, j;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d ", &n);
  for (i=0; i<n; i++)
    gets(s[i]);
  int cnt=0;
  for (i=0; i<n; i++)
  {
    int fl=0;
    for (j=0; j<n; j++)
      if (s[i][j]=='.')
        fl=1;
    cnt+=fl;
  }
  if (cnt==n)
  {
    for (i=0; i<n; i++)
      for (j=0; j<n; j++)
        if (s[i][j]=='.')
        {
          printf("%d %d\n", i+1, j+1);
          break;
        }
    return 0;
  }
  cnt=0;


  for (i=0; i<n; i++)
  {
    int fl=0;
    for (j=0; j<n; j++)
      if (s[j][i]=='.')
        fl=1;
    cnt+=fl;
  }

  if (cnt==n)
  {
    for (i=0; i<n; i++)
      for (j=0; j<n; j++)
        if (s[j][i]=='.')
        {
          printf("%d %d\n", j+1, i+1);
          break;
        }
    return 0;
  }


  puts("-1");
  TIMESTAMP(end);
  return 0;
}