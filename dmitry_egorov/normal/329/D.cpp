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
                 
int main()
{
  int i, j;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  int n;
  scanf("%d", &n);
  if (n==5)
  {
    puts(">...v");
    puts("v.<..");
    puts("..^..");
    puts(">....");
    puts("..^.<");
    puts("1 1");
    return 0;
  } 
  if (n==3)
  {
    puts(">vv");
    puts("^<.");
    puts("^.<");
    puts("1 3");
    return 0;
  }
  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      s[i][j]='.';
  for (i=0; i<100; i++)
  {
    if (i%2==0)
    {
      for (j=0; j<33; j++)
        s[i][j]='>';
      for (j=33; j<99; j+=2)
        s[i][j]='>';
      for (j=99; j<100; j++)
        s[i][j]='v';
    }
    else
    {
      for (j=0; j<2; j++)
        s[i][j]='v';
      for (j=2; j<65; j+=2)
        s[i][j]='<';
      for (j=65; j<100; j++)
        s[i][j]='<';
    }
  }

  for (i=1; i<100; i++)
    s[i][0]='^';
  for (i=1; i<100; i++)
    s[99][i]='<';
  for (i=0; i<100; i++)
    puts(s[i]);
  puts("1 26");
  TIMESTAMP(end);
  return 0;
}