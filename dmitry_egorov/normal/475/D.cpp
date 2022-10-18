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

int Q[312123];
map<int,ll> M;
int n, q, A[123123];
int S[40], NS[40], es, nes, P[40], NP[40]; 
                  
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
  scanf("%d", &q);
  for (i=0; i<q; i++)
    scanf("%d", &Q[i]), M[Q[i]]=0;  
  for (i=n-1; i>=0; i--)
  {
    nes=1, NS[0]=A[i], NP[0]=i;
    for (j=0; j<es; j++)
    {
      int tmp=__gcd(NS[nes-1],S[j]);
      if (tmp<NS[nes-1])
        NS[nes]=tmp, NP[nes]=P[j], nes++;
    }
    es=nes;
    for (j=0; j<es; j++)
      S[j]=NS[j], P[j]=NP[j];
    P[es]=n;
    for (j=0; j<es; j++)
      if (M.count(S[j]))
        M[S[j]]+=P[j+1]-P[j];
  } 
  for (i=0; i<q; i++)
    printf("%I64d\n", M[Q[i]]);
  TIMESTAMP(end);
  return 0;
}