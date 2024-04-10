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

ll res;
int A[(1<<19)+100];
int B[(1<<18)+100];
int n, m, d, cnt;              

int main()
{
  int a, b, t, lt=0, i, j;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d%d", &n, &m, &d);
  //n=150000, m=300, d=5000;
  //int ct=0;
  for (int it=0; it<m; lt=t, it++)
  {
    //cerr<<it<<endl;
    scanf("%d%d%d", &a, &b, &t);

   /* ct+=rand()%1000;
    a=(rand()+1)%n;
    b=rand();
    t=ct; */


    res+=b;  
    //cerr<<"???"<<endl;
    for (i=0; i<(1<<18); i++)
      A[i]=inf;
   // cerr<<"???"<<endl;
    memcpy(B,A+(1<<18),sizeof(B));
    //cerr<<"???"<<endl;
    if (lt!=t && i>0)
    {
      int diff=min((ll)n,(t-lt)*1ll*d);
      for (j=1; j<=n; j++)
      {
        //cerr<<"???  "<<j<<endl;
        int v=B[j];
        int l=max(0,j-diff);
        int r=min(1<<18,j+diff+1);
        l+=(1<<18), r+=(1<<18);
        while (l<r)
        {
          //cnt++;
          if (l&1)
            A[l]=min(A[l],v), l++;
          if (r&1)
            r--, A[r]=min(A[r],v);
          r>>=1, l>>=1;
        }
      }
    }
    //cerr<<"???"<<endl;
    for (i=1; i<(1<<18); i++)
    {
      A[i<<1]=min(A[i<<1],A[i]);
      A[(i<<1)|1]=min(A[(i<<1)|1],A[i]);
    }
    //cerr<<"???"<<endl;
    for (i=0; i<(1<<18); i++)
      A[i+(1<<18)]+=abs(i-a);
    //cerr<<"???"<<endl;
  }
  //cerr<<cnt<<" "<<n*m*18*2<<endl;
  int sub=inf;
  for (i=0; i<(1<<18); i++)
    sub=min(sub,A[i+(1<<18)]);
  printf("%I64d\n", res-sub);  
  TIMESTAMP(end);
  return 0;
}