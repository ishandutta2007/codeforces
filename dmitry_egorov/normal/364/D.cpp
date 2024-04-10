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
typedef pair <ll, int> pli;
typedef vector<pli> vpli;

const int inf = 1e9;
const double eps = 1e-9;
const double INF = inf;
const double EPS = eps;

double st=clock();
int n;
ll A[1123123];
bool u[1123123];
vi Pr;
int Id[1123123][2];
vpli D;
ll Del[123123], gm;
int Val[123123];
int e;

void gen (int v, ll p)
{
  if (v==(int)D.size())
  {
    //cerr<<"p="<<p<<endl;
    (p<=gm/p)?(Id[p][0]=e):(Id[gm/p][1]=e);
    Val[e]=0, Del[e++]=p;
    return;
  }
  for (int i=0; i<=D[v].second; i++, p*=D[v].first)
    gen(v+1,p);
}

ll check ()
{
  int i, cnt, j;
  ll m=A[((rand()<<12)+rand())%n], om=m;
  gm=m;
  D.clear();
  for (i=0; Pr[i]*1ll*Pr[i]<=m; i++)
    if (m%Pr[i]==0)
    {
      cnt=0;
      while (m%Pr[i]==0)
        m/=Pr[i], cnt++;
      D.pb(mp(Pr[i],cnt));
    }
  if (m>1)
    D.pb(mp(m,1));
  m=om;
  e=0;
  gen(0,1);

  ll d;
  int dd, inv;
  for (i=0; i<n; i++)
  {
    d=__gcd(m,A[i]);
    if (d<=m/d)
      inv=0, dd=d;
    else
      dd=m/d, inv=1;
    //cerr<<"???   "<<d<<"   "<<dd<<" "<<inv<<"     "<<Id[dd][inv]<<"    "<<Del[Id[dd][inv]]<<endl;
    Val[Id[dd][inv]]++;
  }
  //cerr<<"m="<<om<<"   "<<n<<endl;
//  for (i=0; i<e; i++)
//    cerr<<Del[i]<<" "<<Val[i]<<endl;
//  cerr<<endl;
  ll ret=0;
  int sum;
  for (i=e-1; i>=0; i--)
  {
    if (ret>=Del[i])
      continue;
    sum=0;
    for (j=i; j<e; j++)
      if (Del[j]%Del[i]==0)
        sum+=Val[j];
    if (sum*2>=n)
      ret=Del[i];
  }
  assert(ret>=1);
  return ret;
}

int main()
{
  int i, j;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  srand(time(NULL));
  for (i=2; i<1123123; i++)
    if (!u[i])
    {  
      Pr.pb(i);
      if (i<2000)
        for (j=i*i; j<1123123; j+=i)
          u[j]=1;
    }
  //cerr<<clock()<<endl;
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%I64d", &A[i]);
  ll res=1;
  int it=0;
  while ((clock()-st)/CLOCKS_PER_SEC<3.0 && it<20) 
    res=max(res,check()), it++;
  #ifdef LOCAL
  cerr<<it<<endl;
  #endif
  printf("%I64d\n", res);
  TIMESTAMP(end);
  return 0;
}