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
typedef pair <ll, ll> pli;
typedef vector<pii> vpii;

const int inf = 1e9;
const double eps = 1e-9;
const double INF = inf;
const double EPS = eps;

pli operator + (const pli& a, const pli& b)
{
  return mp(a.first+b.first,max(a.second,b.second));
}

pli A[(1<<18)+100];
                     
ll sum (int l, int r)
{
  l+=(1<<17), r+=(1<<17);
  ll res=0;
 // cerr<<l<<"  :::  "<<r<<endl;
  while (l<r)
  {
    //cerr<<r-1<<" "<<A[r-1].first<<endl;
    if (l&1)
      res+=A[l].first, l++;
    if (r&1)
      r--, res+=A[r].first;
    l>>=1, r>>=1;
  }
  return res;
}

void mod (int v, int L, int R, int l, int r, int x)
{
  if (R<=l || r<=L || A[v].second<x)
    return;
  if (R-L==1)
  {
    #ifdef LOCAL
    assert(A[v].second==A[v].first && A[v].second>=x);
    #endif
    //cerr<<"?? "<<L<<" "<<x<<" "<<A[v].first<<"    "<<v<<endl;
    A[v].second%=x;
    A[v].first=A[v].second;
    return;
  }
  mod(v<<1,L,(L+R)>>1,l,r,x);
  mod((v<<1)|1,(L+R)>>1,R,l,r,x);
  A[v]=A[v<<1]+A[(v<<1)|1];
}

int main()
{
  int n, m, l, r, i, x, v, tp;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d", &n, &m);
  for (i=0; i<n; i++)
    scanf("%d", &v), A[i+(1<<17)]=mp(v,v);
  for (i=(1<<17)-1; i>0; i--)
    A[i]=A[2*i]+A[2*i+1];
  while (m) 
  {
    m--;
    scanf("%d", &tp);
    if (tp==1)
    {
      scanf("%d%d", &l, &r), l--;
      printf(LLD"\n", sum(l,r));
      continue;
    }
    if (tp==2)
    {
      scanf("%d%d%d", &l, &r, &x), l--;
      mod(1,0,(1<<17),l,r,x);      
      continue;
    }
    assert(tp==3);
    scanf("%d%d", &v, &x), v+=(1<<17)-1, A[v]=mp(x,x), v>>=1;
    while (v)
      A[v]=A[2*v]+A[2*v+1], v>>=1;
  }
  TIMESTAMP(end);
  return 0;
}