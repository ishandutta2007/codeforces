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

const int inf = 1e9;
const double eps = 1e-9;
const double INF = inf;
const double EPS = eps;

int A[110000];
int Tree[(1<<17)+200];
bool Upd[(1<<18)+200];
int Diff[(1<<18)+200];

void push (int v, int l, int r)
{
  Upd[v]=0;
  if (r-l==1)
  {
    Tree[v-(1<<17)]=A[v-(1<<17)+Diff[v]];
    return;
  }
  Upd[2*v]=1, Upd[2*v+1]=1, Diff[2*v]=Diff[v], Diff[2*v+1]=Diff[v];
}

int get (int v, int l, int r, int x)
{
  //cerr<<v<<" "<<l<<" "<<r<<" "<<x<<" "<<Upd[v]<<endl;
  if (Upd[v])
    push(v,l,r);
  if (l==x && r==x+1)
  {
    return Tree[x];
  }
  if (x>=(l+r)/2)
    return get(2*v+1,(l+r)/2,r,x);
  return get(2*v,l,(l+r)/2,x);
}

void st (int v, int l, int r, int b, int diff, int len)
{ 
  if (Upd[v])
    push(v,l,r);
  if (b<=l && r<=b+len)
  {
    Upd[v]=1, Diff[v]=diff;
    return;
  }
  if (r<=b || b+len<=l)
    return;
  st(2*v,l,(l+r)/2,b,diff,len);
  st(2*v+1,(l+r)/2,r,b,diff,len);
}

int main(){
  int i, n, m, j, tp, x, y, k;
  #ifdef LOCAL
  freopen(TASKNAME"a.in","r",stdin);
  //freopen(TASKNAME"a.out","w",stdout);
  #endif
  scanf("%d%d", &n, &m);
  for (i=0; i<n; i++)
    scanf("%d", &A[i]);
  for (j=0; j<n; j++)
    scanf("%d", &Tree[j]);
  //cerr<<"!!! "<<get(1,0,(1<<17),0)<<endl;
  while (m>0)
  {
    m--;
    scanf("%d", &tp);
    if (tp==2)
    {
      scanf("%d", &k);
      printf("%d\n", get(1,0,(1<<17),k-1));
      continue;
    }
    scanf("%d%d%d", &x, &y, &k), x--, y--;
    st(1,0,(1<<17),y,x-y,k);
  }
  
  TIMESTAMP(end);
  return 0;
}