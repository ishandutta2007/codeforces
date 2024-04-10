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

int A[(1<<19)+100][2], F[(1<<19)+100], Len[(1<<19)+100], SumF[(1<<19)+100], P[(1<<19)+100];

void merge (int v)
{
  //cerr<<v<<endl;
  assert(P[v]==0);
  assert(Len[v]>=2);
  A[v][0]=(A[2*v][0]+A[2*v+1][0]*1ll*F[Len[v]/2+1]+A[2*v+1][1]*1ll*F[Len[v]/2])%inf; 
  A[v][1]=(A[2*v][1]+A[2*v+1][0]*1ll*F[Len[v]/2]+A[2*v+1][1]*1ll*F[Len[v]/2-1])%inf;
}

void push (int v)
{
  if (P[v]==0)
    return;
  //cerr<<v<<"  ???? "<<P[v]<<endl;
  //cerr<<SumF[Len[v]+1]<<"  "<<SumF[Len[v]]<<endl;
  A[v][0]=(A[v][0]+P[v]*1ll*SumF[Len[v]+1])%inf;
  A[v][1]=(A[v][1]+P[v]*1ll*SumF[Len[v]])%inf;
  if (v<(1<<18))
    P[2*v]=(P[2*v]+P[v])%inf, P[2*v+1]=(P[2*v+1]+P[v])%inf;
  P[v]=0;
}

void st (int v, int l, int r, int p, int d)
{
  //cerr<<"st  "<<v<<" "<<l<<" "<<r<<" "<<p<<"    "<<Len[v]<<endl;
  push(v);
  if (r-l==1)
  {
    A[v][0]=d, A[v][1]=0;
    return;
  }
  (p<(l+r)/2)?(st(2*v,l,(l+r)/2,p,d)):(st(2*v+1,(l+r)/2,r,p,d));
  merge(v);
}

void sum (int v, int l, int r, int L, int R, pii& ret)
{
  //cerr<<v<<"  sum"<<endl;
  push(v);
  if (L<=l && r<=R)
  {
    ret=mp(A[v][0],A[v][1]);
    return;
  }
  if (R<=l || r<=L)
  {
    ret=mp(0,0);
    return;
  }
  pii ret2;
  sum(2*v,l,(l+r)/2,L,R,ret);
  sum(2*v+1,(l+r)/2,r,L,R,ret2);

  int len=(l+r)/2-max(l,L);
  /*if (R-max<=len)
  {
    ret=ret1;
    return;
  } */
  if (len<=0)
  {
    ret=ret2;
    return;
  }       

  ret.first=(ret.first+ret2.first*1ll*F[len+1]+ret2.second*1ll*F[len])%inf;
  ret.second=(ret.second+ret2.first*1ll*F[len]+ret2.second*1ll*F[len-1])%inf;
}

void add (int v, int l, int r, int L, int R, int d)
{
  if (L<=l && r<=R)
  {
    //cerr<<v<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<"    "<<d<<"       "<<SumF[r-L+2]-SumF[l-L+2]<<endl;
    /*A[v][0]=(A[v][0]+d*1ll*(SumF[r-L+2]-SumF[l-L+2]+inf))%inf;
    A[v][1]=(A[v][1]+d*1ll*(SumF[r-L+1]-SumF[l-L+1]+inf))%inf;
    if (v<(1<<18))
      P[2*v][0]+=*/
    P[v]=(P[v]+d)%inf;
    push(v);
    return;
  }
  push(v);
  if (R<=l || r<=L)
    return;

  add(2*v,l,(l+r)/2,L,R,d);
  add(2*v+1,(l+r)/2,r,L,R,d);
  merge(v);
}

int main()
{
  int i, l, r ,tmp, tp, n, m, p;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d", &n, &m);
  for (F[0]=0, F[1]=1, i=2; i<(1<<19)+100; i++)
    F[i]=(F[i-1]+F[i-2])%inf;
  for (i=1; i<(1<<19)+100; i++)
    SumF[i]=(SumF[i-1]+F[i-1])%inf;
  for (i=(1<<19)-1; i>=(1<<18); i--)
    Len[i]=1;
  for (i=(1<<18)-1; i>0; i--)
    Len[i]=2*Len[2*i];

  //for (i=0; i<20; i++)
  //  cerr<<SumF[i]<<endl;

  for (i=0; i<n; i++)
    scanf("%d", &tmp), st(1,0,(1<<18),i,tmp);

  //for (i=0; i<(1<<19); i++)
  //  if (A[i][0]+A[i][1])
  //    cerr<<i<<"  ??  "<<A[i][0]<<" "<<A[i][1]<<endl;



  for (i=0; i<m; i++)
  {
    scanf("%d", &tp);
    if (tp==1)
    {
      scanf("%d%d", &p, &tmp), st(1,0,(1<<18),p-1,tmp);
      continue;
    }
    if (tp==2)
    {
      scanf("%d%d", &l, &r), l--;
      pii res;
      sum(1,0,(1<<18),l,r,res);
      printf("%d\n", (res.first)%inf);
      continue;
    }
    scanf("%d%d%d", &l, &r, &tmp), l--, add(1,0,(1<<18),l,r,tmp);
  }
  TIMESTAMP(end);
  return 0;
}