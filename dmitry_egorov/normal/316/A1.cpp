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

char s[110000];
bool u[20];
          
int main()
{
  int i, cnt=0, t=0, mul=1, n;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  gets(s), n=strlen(s);
  if (s[0]=='?')
    mul=9;
  for (i=0; i<n; i++)
  {
    if (s[i]=='?' && i>0)
      cnt++;
    if ('A'<=s[i] && s[i]<='J')
      u[s[i]-'A']=1;
  }    
  for (i=0; i<10; i++)
    if (u[i])
      t++;
  if ('A'<=s[0] && s[0]<='J')
  {
    t--, mul*=9;
    while (t>0)
      t--, mul*=9-t;
  }
  else
  {
    while (t>0)
      t--, mul*=10-t;
  }
  printf("%d", mul);
  for (i=0; i<cnt; i++)
    printf("0");
  printf("\n");
  TIMESTAMP(end);
  return 0;
}