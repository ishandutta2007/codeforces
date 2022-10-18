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

int A[5100], M[5100], n, m;
int Tp[5100], L[5100], R[5100], X[5100];
          
int main()
{
  int i, j;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d", &n, &m);
  for (i=0; i<n; i++)
    M[i]=inf;
  for (i=0; i<m; i++)
  {
    scanf("%d%d%d%d", &Tp[i], &L[i], &R[i], &X[i]), L[i]--, R[i]--;
    if (Tp[i]==1)
      for (j=L[i]; j<=R[i]; j++)
        A[j]+=X[i];
    else
      for (j=L[i]; j<=R[i]; j++)
        M[j]=min(M[j],X[i]-A[j]); 
  }
  memcpy(A,M,sizeof(A));
  //for (i=0; i<n; i++)
  //  cerr<<A[i]<<" "<<M[i]<<endl;
  for (i=0; i<m; i++)
  {
    if (Tp[i]==1)
      for (j=L[i]; j<=R[i]; j++)
        A[j]+=X[i];
    else
    {
      int mx=-inf-10;
      for (j=L[i]; j<=R[i]; j++)
        mx=max(mx,A[j]);
      if (mx!=X[i])
      {
        puts("NO");
        return 0;
      }
    }
  }
  puts("YES");
  for (i=0; i<n; i++)
    printf("%d ", M[i]);
  TIMESTAMP(end);
  return 0;
}