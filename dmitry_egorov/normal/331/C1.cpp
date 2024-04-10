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
typedef pair <ll, int> pli;

const int inf = 1e9;
const double eps = 1e-9;
const double INF = inf;
const double EPS = eps;

ll Deg[20];
/*ll D[10][20][10], N[10][20][10];        

void calc (int mn, int deg, int a)
{
  assert(deg>=1);
  if (D[mn][deg][a]!=-1)
    continue;
  if (deg==1)
  {
    D[mn][deg][a]=0;
    int tmp=10-a;
  }
} */

map<pli,pli> M; 

pli solve (ll n, int y)
{
  ll nn=n;
  if (M.count(mp(n,y))!=0)
    return M[mp(n,y)];
  //cerr<<n<<" "<<y<<endl;
  int i;
  ll res=0;
  if (n>=10)
  {
    int it=0;
    while (n>=Deg[it+1])
      it++;
    while (n>=Deg[it])
    {
      //cerr<<"YYY  "<<n<<" "<<Deg[it]<<endl;
      ll m=n%Deg[it];
      if (m==0)
      {
        n-=max((int)(n/Deg[it]),y), res++;
        continue;
      }
      pli ret=solve(m,max(y,(int)(n/Deg[it])));
      res+=ret.first;
      //cerr<<n<<"  JJJ   "<<m<<" "<<ret.second<<endl;
      n-=m, n+=ret.second;
    }               
    pli ret=solve(n,y);
    res+=ret.first, n=ret.second;
  }
  else
  {
  
    while (n>0)
    {
      int md=y, tmp;
      for (i=0; Deg[i]<=n; i++)
      {
        tmp=(n/Deg[i])%10;
        if (md<=tmp)
          md=tmp;
      }
      //assert(md>0 && id!=-1);
      //cerr<<"???   "<<n<<" "<<md<<endl;
      n-=md, res++;
    } 

  }
  //cerr<<"end  "<<nn<<"   "<<y<<endl;
  M[mp(nn,y)]=mp(res,n);
  return mp(res,n);
}

int main()
{
  int i;
  ll n, res=0;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  for (Deg[0]=1, i=1; i<20; i++)
    Deg[i]=Deg[i-1]*10;
  scanf("%I64d", &n);
  if (n==Deg[18])
    n--, res++;
  res+=solve(n,0).first;
  printf("%I64d\n", res); 
  TIMESTAMP(end);
  return 0;
}