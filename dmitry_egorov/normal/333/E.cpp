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
typedef unsigned int uint;

const int inf = 1e9;
const double eps = 1e-9;
const double INF = inf;
const double EPS = eps;

int res=-1, n;
pair <int, pii> P[3100*1500];
int X[3100], Y[3100], e;
uint M[3100][110];

int main()
{
  int x, y, it, i, j;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d", &n);
  //n=3000;
  for (i=0; i<n; i++)
  {
    scanf("%d%d", &X[i], &Y[i]);
    //X[i]=i/2, Y[i]=10000-20000*(i&1);
    //X[i]=rand()%20000-10000, Y[i]=rand()%20000-10000;
  }
  for (i=0; i<n; i++)
    for (j=i+1; j<n; j++)
      P[e++]=mp((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]),mp(i,j));
  sort(P,P+e);
  reverse(P,P+e);
  int mn=(n>>5)+3;
  for (it=0; it<e; it++)
  {
    x=P[it].second.first, y=P[it].second.second;
    //cerr<<x<<" "<<y<<"     "<<P[it].first<<endl;
    for (i=0; i<mn; i++)
      if (M[x][i]&M[y][i])
        res=P[it].first;
    if (res!=-1)
      break;
    M[x][y>>5]+=(((uint)1)<<(y&31));
    M[y][x>>5]+=(((uint)1)<<(x&31));
  }
  assert(res!=-1);
  printf("%.8lf\n", (sqrt((double)res))/2.0);
  TIMESTAMP(end);
  return 0;
}