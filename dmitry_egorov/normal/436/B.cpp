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

int Res[2100];
char s[2100][2100];
     
int main()
{
  int n, m, k, i, j;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d%d ", &n, &m, &k);  
  for (i=0; i<n; i++)
  {
    scanf(" %s", s[i]);
    for (j=0; j<m; j++)
    {
      if (s[i][j]=='.' || s[i][j]=='D')
        continue;
      if (s[i][j]=='U')
      {
        if ((i&1)==0)
          Res[j]++;
        continue;
      }
      int y=j;  
      (s[i][j]=='R')?(y+=i):(y-=i);
      if (0<=y && y<m)
        Res[y]++;
    }
  }
  for (i=0; i<m; i++)
    printf("%d ", Res[i]);
  printf("\n");
  TIMESTAMP(end);
  return 0;
}