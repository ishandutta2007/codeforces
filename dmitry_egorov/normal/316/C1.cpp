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

#define maxn 6500
#define maxm 26000

int e, V[maxm], Next[maxn], Head[maxn], C[maxm], Dest[maxm];
int n, m, A[90][90], flow, tcost, D[maxn], Prev[maxn], Preve[maxn];
//int bq, eq, Q[110000];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
set <int> S;

void adde (int v1, int v2, int v, int c)
{
  Next[e]=Head[v1], Dest[e]=v2, Head[v1]=e, V[e]=v, C[e]=c, e++;
}

void add (int v1, int v2, int v, int c)
{
  adde(v1,v2,v,c), adde(v2,v1,0,-c);
}

int main()
{
  int i, j, v, r, r2, r3, ni, nj, k;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  memset(Head,-1,sizeof(Head));
  scanf("%d%d", &n, &m);
  for (i=0; i<n; i++)
    for (j=0; j<m; j++)
      scanf("%d", &A[i][j]);
  for (i=0; i<n; i++)
    for (j=0; j<m; j++)
    {
      if ((i+j)&1)
      {
        add(i*m+j,n*m+1,1,0);
        continue;
      }
      add(n*m,i*m+j,1,0);
      for (k=0; k<4; k++)
      {
        ni=i+dx[k], nj=j+dy[k];
        if (ni>=0 && ni<n && nj>=0 && nj<m)
          add(i*m+j,ni*m+nj,1,(A[i][j]==A[ni][nj])?(0):(1));
      }
    }  
  //cerr<<flow<<" "<<tcost<<endl;
  for (r=Head[n*m]; r!=-1; r=Next[r])
    for (r2=Head[Dest[r]]; r2!=-1; r2=Next[r2])
      if (C[r2]==0 && V[r2]>0)
      {
        V[r^1]++, V[r]--, V[r2^1]++, V[r2]--, flow++;
        //cerr<<Dest[r]<<" ???  "<<Dest[r2]<<endl;
        for (r3=Head[Dest[r2]]; r3!=-1; r3=Next[r3])
          if (Dest[r3]==n*m+1)
            V[r3]--, V[r3^1]++;
        break;
      }
  //cerr<<flow<<" "<<tcost<<endl;
  for (r=Head[n*m]; r!=-1; r=Next[r])
    if (V[r]>0)
      for (r2=Head[Dest[r]]; r2!=-1; r2=Next[r2])
        if (C[r2]==1 && V[r2]>0)
        {
          bool fl=0;
          for (r3=Head[Dest[r2]]; r3!=-1; r3=Next[r3])
            if (Dest[r3]==n*m+1 && V[r3]>0)
            {
              V[r3]--, V[r3^1]++, fl=1;
              break;
            }
          if (fl)
          {
            V[r^1]++, V[r]--, V[r2^1]++, V[r2]--, flow++, tcost++;
            break;
          }
        }
  //cerr<<flow<<" "<<tcost<<endl;
  const int mask = (1<<15)-1;

  while (2*flow<n*m)
  {
    for (i=0; i<n*m+2; i++)
      D[i]=10000;
    S.clear(), D[n*m]=0, S.insert(n*m);
    while (S.size())
    {
      v=*S.begin(), S.erase(S.begin());
      if (D[v&mask]!=(v>>15))
        continue;
      v&=mask;
      for (r=Head[v]; r!=-1; r=Next[r])
        if (V[r] && D[Dest[r]]>D[v]+C[r])
          D[Dest[r]]=D[v]+C[r], Prev[Dest[r]]=v, Preve[Dest[r]]=r, S.insert((D[Dest[r]]<<15)+Dest[r]);
    }
    assert(D[n*m+1]<10000), flow++, tcost+=D[n*m+1], v=n*m+1;
    while (v!=n*m)
      V[Preve[v]]--, V[Preve[v]^1]++, v=Prev[v];
  }
  //cerr<<flow<<" "<<tcost<<endl;
  printf("%d\n", tcost);
  TIMESTAMP(end);
  return 0;
}