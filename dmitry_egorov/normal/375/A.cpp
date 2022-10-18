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

int A[4]={1,6,8,9};
bool u[10];
char s[1123123];
char t[1123123];                      

int main()
{
  int i;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  gets(s);
  int len=strlen(s), ptr=len-1, r=0, p=1;
  for (i=0; i<len; i++)
  {
    int d=s[i]-'0';
    if ((d==1 || d==6 || d==8 || d==9) && (!u[d]))
    {
      u[d]=1;
      continue;
    }
    r+=d*p, p*=10, p%=7, t[ptr--]=s[i];
  }
  assert(ptr==3);
  do
  {
    //cerr<<p<<" "<<r<<endl;
    if (((A[0]*1000+A[1]*100+A[2]*10+A[3])*p+r)%7==0)
    {
      for (i=0; i<4; i++)
        t[i]=A[i]+'0';
      //cerr<<"???"<<endl;
      break;
    }
  }
  while (next_permutation(A,A+4));
  puts(t);
  TIMESTAMP(end);
  return 0;
}