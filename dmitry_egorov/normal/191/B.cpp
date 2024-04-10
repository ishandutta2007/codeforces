#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <string>
#include <ctime>
#include <stack>

#define sqr(x) ((x)*(x))
#define sz(a) (int)a.size()
#define pb push_back
#define mp make_pair
#define zero(a) memset (a, 0, sizeof(a))



#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


const int inf = (int)1e9;

int res, n, k;
long long b;
pair <long long, int> A[110000];
long long S[110000];

long long calc (int id)
{
  if (id>=k-1)
    return S[k-1]+A[id].first;
  return S[k];
}

int main (void)
{
  int i;
  long long tmp;
  #ifdef LOCAL
    freopen (".in", "r", stdin);
    freopen (".out", "w", stdout);
  #endif
  scanf("%d%d%I64d", &n, &k, &b), res=n-1, n--;
  for (i=0; i<n; i++)
    scanf("%I64d", &tmp), A[i]=mp(tmp,i);                             
  sort(A,A+n);
  reverse(A,A+n);
  for (i=1; i<=n; i++)
    S[i]=S[i-1]+A[i-1].first;
//  for (i=0; i<n; i++)
//    cerr<<S[i+1]<<" "<<A[i].first<<" "<<A[i].second<<endl;
  for (i=0; i<n; i++)
    if (b<calc(i))
      res=min(res,A[i].second);
  printf("%d\n", res+1);
  return 0;
}