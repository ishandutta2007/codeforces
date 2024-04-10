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

int res, resl, resr;

void upd (int ccnt, int l, int r)
{
  //cerr<<"upd  "<<ccnt<<" "<<l<<" "<<r<<endl;
  if (res>=ccnt)
    return;
  res=ccnt, resl=l, resr=r;
}

int Tr[(1<<20)+100], P[(1<<20)+100], Ph[(1<<20)+100];// Lb[(1<<20)+100];
vi G[310000];
vpii D[310000];
int L[123123], R[123123], V[123123], n;
    
void push (int v)
{
  assert(v<(1<<19));
  Ph[v<<1]+=Ph[v], Tr[v<<1]+=Ph[v];
  Ph[(v<<1)+1]+=Ph[v], Tr[(v<<1)+1]+=Ph[v];
  Ph[v]=0;
}

void add (int v, int L, int R, int l, int r, int d)
{
  if (l<=L && R<=r)
  {
    Ph[v]+=d, Tr[v]+=d;
    return;
  }
  if (R<=l || r<=L)
    return;
  push(v);
  assert(v<(1<<19));
  add(v<<1,L,(L+R)/2,l,r,d);
  add((v<<1)+1,(L+R)/2,R,l,r,d);
  if (Tr[v<<1]>=Tr[(v<<1)+1])
    Tr[v]=Tr[v<<1], P[v]=P[v<<1];
  else
    Tr[v]=Tr[(v<<1)+1], P[v]=P[(v<<1)+1];
}

int main()
{
  int i, l, v, r, j;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d", &n);
  for (i=0; i<(1<<19); i++)
    P[i+(1<<19)]=i;
  for (i=(1<<19)-1; i>0; i--)
    P[i]=P[i<<1];
  for (i=0; i<n; i++)
  {
    scanf("%d%d%d", &l, &v, &r);
    L[i]=l, V[i]=v, R[i]=r;
    G[v].pb(l);
    D[r+1].pb(mp(v,l));
  }
  for (i=0; i<310000; i++)
  {
    //cerr<<i<<endl;
    if (D[i].size())
      for (j=0; j<(int)D[i].size(); j++)
        add(1,0,1<<19,D[i][j].second,D[i][j].first+1,-1);
    //cerr<<"??"<<endl;
    if (G[i].size())
    {
      for (j=0; j<(int)G[i].size(); j++)
        add(1,0,1<<19,G[i][j],i+1,1);
      upd(Tr[1],P[1],i);
    }
  }
  printf("%d\n", res);
  int cnt=0;
  for (i=0; i<n; i++)
    if (L[i]<=resl && resr<=R[i] && resl<=V[i] && V[i]<=resr)
      cnt++, printf("%d ", i+1);
  printf("\n");
  //cerr<<cnt<<" "<<res<<" "<<resl<<" "<<resr<<endl;
  assert(cnt==res); 
  TIMESTAMP(end);
  return 0;
}