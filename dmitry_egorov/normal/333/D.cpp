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
     
int res=0, A[1100][1100];
vi V[1100];
pii P[1100*1100];
bool M[1100][1100];
int ep;

bool cmp (const pii& a, const pii& b)
{
  return A[a.first][a.second]>A[b.first][b.second];
}

int main()
{
  int n, m, i, j, a, b, x, y;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d", &n, &m);
  //n=1000, m=1000;
  for (i=0; i<n; i++)
    for (j=0; j<m; j++)
    {
      scanf("%d", &A[i][j]);
      //A[i][j]=rand()*1000+rand();
      P[ep++]=mp(i,j);
    }
  sort(P,P+ep,cmp);
  for (int it=0; it<ep; it++)
  {
    x=P[it].first, y=P[it].second;
   // cerr<<x<<" "<<y<<"    "<<A[x][y]<<endl;
    if (res>=A[x][y])
      break;
    for (i=0; i<(int)V[x].size(); i++)
    { 
      a=y, b=V[x][i];
      if (a>b)
        swap(a,b);
      if (M[a][b])
      {
        res=A[x][y];
        break;
      }
      M[a][b]=1;
    }
    V[x].pb(y);
  }
  printf("%d\n", res);
  TIMESTAMP(end);
  return 0;
}