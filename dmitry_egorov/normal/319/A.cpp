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

#define mod (1000000007)

ll Deg[210], res;
char s[110];
int A[110], n, T[2];
                         
int main()
{
  int i;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  gets(s), n=strlen(s);  
  for (i=0; i<n; i++)
    A[i]=(int)(s[i]-'0');
  for (Deg[0]=1, i=1; i<210; i++)
    Deg[i]=(Deg[i-1]*2ll)%mod;
  for (i=0; i<n; i++)
  {
    if (A[i]==1)
    {
      res+=Deg[2*(n-i-1)+i];
      res%=mod;
    }
    T[A[i]]++;
  }
  printf("%d\n", (int)(res%mod));
  TIMESTAMP(end);
  return 0;
}