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

typedef double ld;
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

int eq, neq, Q[310], NQ[310], V[310], NV[310];
pii X[310], NX[310];
ld ds, Res[310];
int n, mx, x;
int A[310][310];
                 
inline int eval (int f, const pii& p)
{
  return A[f][x]*p.first+A[f][x+1]*p.second;
}

inline ld len (const pii& p)
{
  return p.second/((double)(p.first+p.second));
}

inline ld norm (const pii& p)
{
  return p.first+p.second;
}

int main()
{
  int i, j, it, pv, nv;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d", &n, &mx);
  for (i=0; i<n; i++)
    for (j=0; j<=mx; j++)
      scanf("%d", &A[i][j]);
  for (x=0; x<mx; x++)
  {
    Res[0]+=((ld)A[0][x]+(ld)A[0][x+1])/2.0;
    eq=1, Q[0]=0, X[0]=mp(1,0), X[1]=mp(0,1); 
    V[0]=eval(0,X[0]), V[1]=eval(0,X[1]);
    for (it=1; it<n; it++)
    {
      //cerr<<"IT="<<it<<endl;
      pv=eval(it,X[0]);
      for (i=0; i<eq; pv=nv, i++)
      {
        nv=eval(it,X[i+1]);
        if (pv>=V[i] && nv>=V[i+1])
        {
          NX[neq]=X[i], NV[neq]=pv, NQ[neq]=it;
          neq++;
          Res[it]+=((pv-V[i])/norm(X[i])+(nv-V[i+1])/norm(X[i+1]))*0.5*(len(X[i+1])-len(X[i]));
          continue;
        }
        if (pv<=V[i] && nv<=V[i+1])
        {
          NX[neq]=X[i], NV[neq]=V[i], NQ[neq]=Q[i];
          neq++;
          continue;
        }
        NX[neq]=X[i], NX[neq+1]=mp(abs(A[Q[i]][x+1]-A[it][x+1]),abs(A[Q[i]][x]-A[it][x]));
        //pv=eval(it,X[i]);
        //cerr<<pv<<" "<<nv<<"    "<<V[i]<<" "<<V[i+1]<<"     "<<len(X[i])<<" "<<len(NX[neq+1])<<" "<<len(X[i+1])<<"     "<<NX[neq+1].first<<" "<<NX[neq+1].second<<endl;
        if (V[i]>pv)
          NQ[neq]=Q[i], NQ[neq+1]=it, NV[neq]=V[i], Res[it]+=((nv-V[i+1])/norm(X[i+1]))*0.5*(len(X[i+1])-len(NX[neq+1]));
        else
          NQ[neq]=it, NQ[neq+1]=Q[i], NV[neq]=pv, Res[it]+=((pv-V[i])/norm(X[i]))*0.5*(len(NX[neq+1])-len(X[i]));
        NV[neq+1]=eval(it,NX[neq+1]);
        neq+=2; 
      }
      NX[neq]=mp(0,1);
      NV[neq]=eval(NQ[neq-1],NX[neq]);
      eq=neq, neq=0;
      memcpy(X,NX,sizeof(X[0])*(eq+1));
      memcpy(V,NV,sizeof(V[0])*(eq+1));
      memcpy(Q,NQ,sizeof(Q[0])*eq);
    }
  }
  for (i=0; i<n; i++)
    printf("%.6lf\n", (double)Res[i]); 
  TIMESTAMP(end);
  return 0;
}