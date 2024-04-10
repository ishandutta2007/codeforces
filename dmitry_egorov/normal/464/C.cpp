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

const int mod = inf+7;

pii operator + (const pii& a, const pii& b)
{
  return mp((a.first*1ll*b.second+b.first)%mod,(a.second*1ll*b.second)%mod);
}
               
pii Z[123123][10];
char s[213123], str[123123];
int Val[123123];
vi V[123123];

int main()
{
  int n;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%s", str);
  for (int i=0; i<10; i++)
    Z[0][i]=mp(i,10);
  scanf("%d ", &n);
  for (int t=n-1; t>=0; t--)
  {
    scanf("%s", s);
    Val[t]=s[0]-'0';
    int len=strlen(s);
    for (int i=3; i<len; i++)
      V[t].pb(s[i]-'0');
  }
  for (int t=0; t<n; t++)
  {
    for (int i=0; i<10; i++)
      Z[t+1][i]=Z[t][i];
    int z=Val[t];
    Z[t+1][z]=mp(0,1);
    for (int i=(int)V[t].size()-1; i>=0; i--)
      Z[t+1][z]=Z[t][V[t][i]]+Z[t+1][z];
  }
  int len=strlen(str);  
  pii ans=Z[n][str[len-1]-'0'];
  for (int i=len-2; i>=0; i--)
    ans=Z[n][str[i]-'0']+ans;
  printf("%d\n", ans.first);
  TIMESTAMP(end);
  return 0;
}