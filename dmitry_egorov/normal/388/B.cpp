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

char S[250][250];

void add (int v1, int v2)
{
  S[v1][v2]='Y', S[v2][v1]='Y';
}
                       
int main()
{
  int m, i, j, k;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d", &m);
  for (i=0; i<200; i++)
    for (j=0; j<200; j++)
      S[i][j]='N';
  for (i=0; i<=40; i++)
    add(i+2,i+3);
  add(43,1), add(0,50), add(0,51);
  for (i=0; i<50; i++)
    for (j=0; j<2; j++)
      for (k=2; k<4; k++)
        add(50+2*i+j,50+2*i+k);
  for (i=0; i<30; i++)
    if (m&(1<<i))
      add(50+2*i,2+i);
  printf("%d\n", 200);
  for (i=0; i<200; i++)
    puts(S[i]);
  TIMESTAMP(end);
  return 0;
}