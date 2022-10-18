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

int A[40], B[40];
      
int main()
{
  int n, m, i, j, k, d, res=0, t;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d", &n, &m);
  for (i=0; i<n; i++)
    for (scanf("%d", &t), j=0; j<30; j++)
      if (t&(1<<j))  
        A[j]++;
  for (i=0; i<m; i++)
    scanf("%d", &t), B[t]++;
  for (i=0; i<30; i++)
    for (j=i; j<30; j++)
    {
      if (B[i]==0)
        break;
      d=min(B[i],(A[j]<<(j-i))), res+=d, B[i]-=d;
      if (d==0)
        continue;
      //if (d)
      //  cerr<<d<<" "<<i<<" "<<B[i]<<endl;
      for (k=0; k<j-i; k++, d/=2)
        if (d&1)
          d++, A[i+k]++;
      A[j]-=d;  
    }
  printf("%d\n", res);
  TIMESTAMP(end);
  return 0;
}