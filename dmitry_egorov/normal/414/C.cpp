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

const int maxn = (1<<21)+100;

int A[maxn];
ll S1[30], S2[30], res;

struct node
{
  bool rev;
  int l, r, sum, lv;
  /*void push ()
  {
    if (!rev)
      return;
    swap(l,r), swap(val,vali);
    Tr[l].rev=(!Tr[l].rev), Tr[r].rev=(!Tr[r].rev);
    rev=0;
  }
  void query (int q)
  {
    if (q==lv)
    {
      rev=(!rev);
      return;
    }
    push();

  }*/
};

node Tr[maxn];

void init (int v, int L, int R)
{
  int l=Tr[v].l, r=Tr[v].r, lv=Tr[v].lv;
  if (lv==0)
    return;
  ll val=0, vali=0;
  int M=(L+R)/2;
  init(l,L,M);
  init(r,M,R);
  int add=0;
  for (int i=L; i<M; i++)
  {
    while (add<R-M && A[M+add]<A[i])
      add++;
    val+=add;
  }
  add=0;                                
  for (int i=M; i<R; i++)
  {
    while (add<M-L && A[L+add]<A[i])
      add++;
    vali+=add;
  }
  S1[lv]+=val, S2[lv]+=vali, res+=val;
  Tr[v].sum=Tr[l].sum+Tr[r].sum+val;
  inplace_merge(A+L,A+M,A+R);
  for (int i=L; i<R-1; i++)
    assert(A[i]<=A[i+1]);
}

         
int main()
{
  int i, tmp, q, n, v;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d", &n);
  for (i=0; i<(1<<n); i++)
    scanf("%d", &A[i]);
  for (i=(1<<n)-1; i>0; i--)
    Tr[i].l=2*i, Tr[i].r=2*i+1, Tr[i].lv=Tr[2*i].lv+1;
  init(1,0,(1<<n));
  /*for (i=0; i<=n; i++)
    cerr<<i<<" "<<S1[i]<<" "<<S2[i]<<endl;
  cerr<<res<<endl;*/
  for (scanf("%d", &q); q>0; q--)
  {
    scanf("%d", &v);
    for (tmp=0; tmp<=v; tmp++) 
      res-=S1[tmp], swap(S1[tmp],S2[tmp]), res+=S1[tmp];
    printf("%I64d\n", res);
  }
  TIMESTAMP(end);
  return 0;
}