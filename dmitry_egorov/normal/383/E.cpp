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

char s[10];
int D[(1<<24)+100], res;
        
int main()
{
  int n, i, b, g, j;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  srand(time(NULL));
  scanf("%d ", &n);
  //n=10000;
  for (i=0; i<n; i++)
  {
    gets(s);
    //for (j=0; j<3; j++)
    //  s[j]='a'+rand()%24;
    assert(strlen(s)==3);
    int m=0;
    for (j=0; j<3; j++)
      m|=(1<<((int)(s[j]-'a')));
    assert(__builtin_popcount(m)<=3);
    D[(1<<24)-m-1]++;
  }  
  for (b=0; b<24; b++)
  {
    int f=0, t=(1<<b);
    for (g=0; g<(1<<(23-b)); f+=(1<<(b+1)), t+=(1<<(b+1)), g++)
      for (i=0; i<(1<<b); i++)
        D[f|i]+=D[t|i];
  }
  for (i=0; i<(1<<24); i++)
    res^=(n-D[i])*(n-D[i]);
  printf("%d\n", res);
  TIMESTAMP(end);
  return 0;
}