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
typedef pair<ld,int> pldi;

const int inf = 1e9;
const ld eps = 1e-8;
const double INF = inf;
const double EPS = eps;

bool cmp (const pldi& a, const pldi& b)
{
  if (fabs(a.first-b.first)>eps)
    return a.first<b.first;
  return a.second>b.second;
}

pldi Ev[22123*4*20*5];
int e;

void add2 (ld l, ld r)
{
  assert(r-l<M_PI);
  Ev[e++]=mp(l,1);
  Ev[e++]=mp(r,-1);
}

void add (ld mid, ld diff)
{
  ld l=mid-diff, r=mid+diff;
  while (l<-M_PI)
    l+=2.0*M_PI;
  while (r>M_PI)
    r-=2.0*M_PI;
  if (-eps<r-l && r-l<M_PI)
    add2(l,r);
  else
    add2(-M_PI,r), add2(l,M_PI);
}

ld d;

void read ()
{
  //cerr<<"read"<<endl;
  ld x, y, r;
  double _x, _y, _r;
  scanf("%lf%lf%lf", &_x, &_y, &_r);
  x=_x, y=_y, r=_r;
  ld mid=atan2(y,x);
  ld dist2=x*x+y*y;
  ld dist=sqrt(dist2);
  int tmp=max(0,(int)((dist-r)/d-3.0));
  ld cd=tmp*d, diff;
  while (cd+d<dist+r+eps)
  {
    cd+=d;
    //cerr<<cd<<endl;
    if (cd<dist-r-eps)
      continue;
    if (cd<dist-r+eps)
    {
      add(mid,0.0);
      continue;
    }
    if (cd<dist+r-eps)
    {
      diff=acos((cd*cd+dist2-r*r)/(2.0*cd*dist));
      add(mid,diff);
      continue;
    }
    add(mid,0.0);
  }
}
            
int main()
{
  int i, n;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  cin>>n>>d;
  for (i=0; i<n; i++)
    read();
  sort(Ev,Ev+e,cmp);
  int res=0, cur=0;
  for (i=0; i<e; i++)
    cur+=Ev[i].second, res=max(res,cur);
  printf("%d\n", res);
  TIMESTAMP(end);
  return 0;
}