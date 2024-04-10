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
           
ll tmpl, res, D[600][600];
int Cnt[2], n;

int main()
{
  int i, j, tmp;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d", &tmp), Cnt[tmp-1]++;
  for (D[0][0]=1, i=0; i<Cnt[0]; i++)  
  {
    for (j=0; j<=i; j++)
      D[i+1][j+1]=D[i][j];
    if (i==0)
      continue;
    for (j=0; j<=i; j++)
      D[i+1][j]+=D[i-1][j]*i, D[i+1][j]%=mod;
  }    
  //cerr<<Cnt[0]<<" ???  "<<Cnt[1]<<endl;
  for (i=0; i<=Cnt[0]; i++)
    res+=D[Cnt[0]][i], res%=mod;// cerr<<D[Cnt[0]][i]<<endl;
  for (i=0; i<Cnt[1]; i++)
    res*=n-i, res%=mod;
  cout<<res<<endl;
  TIMESTAMP(end);
  return 0;
}