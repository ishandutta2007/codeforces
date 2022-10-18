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

int A[3];
vpii V[3];
           
int main()
{
  int i, j, k;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d", &A[0], &A[1]), A[0]*=A[0], A[1]*=A[1], A[2]=A[0]+A[1];
  for (i=1; i<=2000; i++)
    for (j=1; j<=2000; j++)
    {
      int d=i*i+j*j;
      for (k=0; k<3; k++)
        if (d==A[k])
          V[k].pb(mp(i,j));
    }
  for (i=0; i<3; i++)
    for (j=0; j<(int)V[i].size(); j++)
      for (k=0; k<(int)V[(i+1)%3].size(); k++)
      {
        int dx=V[i][j].first-V[(i+1)%3][k].first;
        int dy=V[i][j].second-V[(i+1)%3][k].second;
        if (dx*dx+dy*dy==A[(i+2)%3])
        {
          puts("YES");
          printf("0 0\n%d %d\n%d %d\n", V[i][j].first, V[i][j].second, V[(i+1)%3][k].first, V[(i+1)%3][k].second);
          return 0;
        }
      }
  puts("NO");
  TIMESTAMP(end);
  return 0;
}