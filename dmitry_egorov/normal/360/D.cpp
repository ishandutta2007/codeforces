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

int p, A[110000], n;

int deg (int v, int d)
{
  if (d==0)
    return 1;
  if (d&1)
    return (v*1ll*deg(v,d-1))%p;
  return deg((v*1ll*v)%p,d>>1);
}
     
pii Div[40];
int e, fi;

int test (int a)
{
//  cerr<<a<<"     "<<e<<endl;
  assert(0<a && a<p);
  int ret=p-1;
  for (int i=0; i<e; i++)
    while (ret%Div[i].first==0 && deg(a,ret/Div[i].first)==1)
      ret/=Div[i].first;
 // cerr<<a<<" "<<ret<<endl;
  return (p-1)/ret;
}

int Q[123123], eq, W[123123];
bool u[123123];

void gen (int v, int pr)
{
  //cerr<<v<<" "<<pr<<endl;
  int i;
  if (v==e)
  {
    assert(0<pr && pr<p);
    assert((p-1)%pr==0);
    int rt=(p-1)/pr;
    W[eq]=rt;
    //cerr<<"SDFGH  "<<e<<endl;
    for (i=0; i<e; i++)
      if (rt%Div[i].first==0)
        W[eq]/=Div[i].first, W[eq]*=Div[i].first-1;
    Q[eq++]=pr;
    return;
  }
  for (i=0; i<=Div[v].second; i++, pr*=Div[v].first)
    gen(v+1,pr);
}

int main()
{
  int i, m, b, j;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d%d", &n, &m, &p);
  for (i=0; i<n; i++)
    scanf("%d", &A[i]); 
  int tb=p-1;
 // cerr<<"???"<<endl;
  for (i=0; i<m; i++)
    scanf("%d", &b), tb=__gcd(b,tb);
  for (i=0; i<n; i++)
    A[i]=deg(A[i]%p,tb);
//  cerr<<"???"<<endl;
  sort(A,A+n);
  n=unique(A,A+n)-A;
  int tmp=p-1;
  for (i=2; i*i<=tmp; i++)
    if (tmp%i==0)
    {
      int cnt=0;
      while (tmp%i==0)
        tmp/=i, cnt++;
      Div[e++]=mp(i,cnt);
    }
//  cerr<<"???"<<endl;
  if (tmp>1)
    Div[e++]=mp(tmp,1);
  for (i=0; i<n; i++)
    A[i]=test(A[i]);
  sort(A,A+n);
  n=unique(A,A+n)-A;
 // cerr<<"???"<<endl;
  gen(0,1);
/*  for (i=0; i<n; i++)
    cerr<<i<<"  A  "<<A[i]<<endl;
  for (i=0; i<eq; i++)      
    cerr<<i<<"  Q  "<<Q[i]<<"   "<<W[i]<<endl;   */
  for (i=0; i<n; i++)
    for (j=0; j<eq; j++)
      if (Q[j]%A[i]==0)
        u[j]=1;
  int res=0;
 // cerr<<"???"<<endl;
  for (i=0; i<eq; i++)
  {
  //  cerr<<"RRR  "<<i<<" "<<u[i]<<endl;
    if (u[i])
      res+=W[i];
  }
  printf("%d\n", res);
  TIMESTAMP(end);
  return 0;
}