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

set <pii> S;

int n, D[(1<<17)+10];
ll A[10];
map <int, int> M;
bool u[1100000];
vi Pr;

int calc (ll v)
{
  if (M.count(v)!=0)
    return M[v];
  int ret=0;
  ll ov=v;
  for (int i=0; Pr[i]*1ll*Pr[i]<=v; i++)
    while (v%Pr[i]==0)
      v/=Pr[i], ret++;
  if (v>1)
    ret++;
  M[ov]=ret;
  return ret;
}

void add (int v, int r, bool rl, int val)
{
  //cerr<<"add   "<<v<<" "<<r<<" "<<rl<<"    "<<val<<endl;
  int mask=(v<<n)+r;
  mask<<=1;
  if (rl)
    mask++;
  if (D[mask]>=val)
    S.erase(mp(val,mask)), D[mask]=val, S.insert(mp(val,mask));
  //cerr<<"endadd"<<endl;
}
   
int main()
{
  int mask, val, i, j;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  for (i=2; i<1100000; i++)
    if (!u[i])
    {
      Pr.pb(i);
      if (i<2000)
        for (j=i*i; j<1100000; j+=i)
          u[j]=1;
    }
  //cerr<<calc(1)<<endl;
  scanf("%d", &n);
  for (i=0; i<(1<<(2*n+1)); i++)
    D[i]=inf;
  for (i=0; i<n; i++)
  {
    cin>>A[i];
    int tmp=calc(A[i]);
    add((1<<i),(1<<i),1,(tmp==1)?(1):(tmp+1));
  }
  while (S.size())
  {
    mask=S.begin()->second;
    val=S.begin()->first;
    S.erase(S.begin());
    bool rl=0;
    if (mask&1)
      rl=1;
    mask>>=1;
    int v=mask>>n;
    int r=mask&((1<<n)-1);
    //cerr<<mask<<"      "<<v<<" "<<r<<" "<<rl<<"    "<<val<<endl;
    if (v==(1<<n)-1)
    {
      cout<<val<<endl;
      return 0;
    }
    if (rl)
      add(v,r,0,val+1);
    if (!rl)
    {
      ll rv=1ll;
      ld rvd=1.0;
      for (i=0; i<n; i++)
        if (r&(1<<i))
          rv*=A[i], rvd*=A[i];
      if (rvd<1e13)
        for (i=0; i<n; i++)
          if ((v&(1<<i))==0 && A[i]%rv==0)
            add(v+(1<<i),(1<<i),1,val+calc(A[i]/rv));
    }
    if (!rl)
      for (i=(1<<n)-1-v; i!=0; i=((i-1)&((1<<n)-1-v)))
        for (j=i; j!=0; j=((j-1)&i))
          add(v+i,r+j,0,val+D[((i<<n)+j)<<1]-1);
  }
  assert(0);  
  TIMESTAMP(end);
  return 0;
}