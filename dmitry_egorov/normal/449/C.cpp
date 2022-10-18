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

const int maxn = 123123;

int u[maxn];
int Res[maxn], res;
vpii P;                     

void add (int a, int b)
{
  res++;
  Res[a]=b, Res[b]=a;
}

int main()
{
  int i, n;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d", &n);
  for (i=2; i<=n; i++)
  {
    if (u[i])
      continue;
    int c=0;
    for (int j=i; j<=n; j+=i)
      if (!u[j])
        u[j]=i, c++;
    P.pb(mp(i,c));
  }  
  if (n==1)
  {
    puts("0");
    return 0;
  }
  for (i=1; i<(int)P.size(); i++)
  {
    int p=P[i].first, st=p;
    if (2*p>n)
      break;
    if (P[i].second%2==1)
      add(st,2*st), st=2*p;
    int l=-1;
    while (st<=n)
    {
      if (u[st]==p)
      {
        if (l==-1)
          l=st;
        else
          add(l,st), l=-1;
      }
      st+=p;
    }
    assert(l==-1);
  }
  int st=2, p=2;
  int l=-1;
  while (st<=n)
  {
    if (u[st]==p && Res[st]==0)
    {
      if (l==-1)
        l=st;
      else
        add(l,st), l=-1;
    }
    st+=p;
  }
  cout<<res<<endl;
  for (i=0; i<=n; i++)
    if (i<Res[i])
      printf("%d %d\n", i, Res[i]), res--;
  assert(!res);
  TIMESTAMP(end);
  return 0;
}