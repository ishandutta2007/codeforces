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

int D[(1<<20)+100], ND[(1<<20)+100];
char Tp[30];
int n, A[300], T[30];
              
int main()
{
  int i, j;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d", &n);
  for (i=0; i<n; i++)  
    scanf("%d", &A[i]);
  sort(A,A+n);
  reverse(A,A+n);
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf(" %c%d", &Tp[i], &T[i]), T[i]--;

  /*n=20;
  for (i=0; i<n; i++)
  {
    A[i]=20-i;
    Tp[i]='b';
    T[i]=i%2;
  }
  Tp[3]='p';
  Tp[8]='p'; */   

  reverse(Tp,Tp+n);
  reverse(T,T+n);



  for (int it=0; it<n; it++)
  {
    /*cerr<<"it="<<it<<endl;
    for (i=0; i<(1<<n); i++)
      cerr<<D[i]<<endl;*/
    for (i=0; i<(1<<n); i++)
      ND[i]=inf;
    if (Tp[it]=='p')
    {
      if (T[it]==0)
      {
        for (i=1; i<(1<<n); i++)
          for (j=0; ; j++)
            if (i&(1<<j))
            {
              ND[i]=D[i-(1<<j)]+A[j];
              break;
            }
      }
      else
      {
        for (i=1; i<(1<<n); i++)
          for (j=0; ; j++)
            if (i&(1<<j))
            {
              ND[i]=D[i-(1<<j)]-A[j];
              break;
            }
      }
    }
    else
    {
      if (T[it]==0)
        for (i=0; i<(1<<n); i++)
        {
          ND[i]=D[i];
          if (ND[i]==inf)
            ND[i]=-inf;
          for (j=0; j<n; j++)
            if (i&(1<<j))
              ND[i]=max(ND[i],D[i-(1<<j)]);
          if (ND[i]==-inf)
            ND[i]=inf;

        }
      else
        for (i=0; i<(1<<n); i++)
        {
          ND[i]=D[i];
          for (j=0; j<n; j++)
            if (i&(1<<j))
              ND[i]=min(ND[i],D[i-(1<<j)]);
        } 
    }
    memcpy(D,ND,sizeof(D));
  }
   // cerr<<"it="<<n<<endl;
  //  for (i=0; i<(1<<n); i++)
   //   cerr<<D[i]<<endl;

  assert(D[(1<<n)-1]!=inf);
  printf("%d\n", D[(1<<n)-1]);
  TIMESTAMP(end);
  return 0;
}