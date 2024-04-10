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

set <int> S, NS;
int A[110000], Next[110000];
    
int main()
{
  int v, p, i, res=0, n;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d", &A[i]), Next[i]=i+1;
  A[n]=inf;
  for (i=0; i<n-1; i++)
    if (A[i]>A[i+1])
      S.insert(i);
  while (S.size())
  {
    res++, NS.clear();
    while (S.size())
    {
      v=*S.begin(), S.erase(S.begin());
      p=A[v];
      while (p>A[Next[v]])
        p=A[Next[v]], Next[v]=Next[Next[v]];
      if (A[v]>A[Next[v]])
        NS.insert(v);
    }
    NS.swap(S);
    //v=0;
   // while (v<n)
  //    printf("%d ", A[v]), v=Next[v];
  //  printf("!!!\n");
  }
  printf("%d\n", res); 
  TIMESTAMP(end);
  return 0;
}