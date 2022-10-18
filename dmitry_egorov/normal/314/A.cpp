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

int k, m;
ll add;
ld addd;              

bool check (ll p, ll a)
{
  ll lb=add-k;
  ld ldlb=addd-k;
  ll coef=p*(m-p-1);
  //cerr<<p<<" "<<a<<"    "<<lb<<" "<<coef<<endl; 
  if (((ld)coef) * ((ld) a) > ldlb + 3e18 )
    return 1;
  if (((ld)coef) * ((ld) a) < ldlb - 3e18 )
    return 0;

  return coef*a-lb>0;
}

int A[210000];

int main()
{
  int i, n;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d", &n, &k);
  for (i=0; i<n; i++)
    scanf("%d", &A[i]), m=n;
  int cp=0;
  for (i=0; i<n; i++)
  {
    if (check(cp,A[i]))
      printf("%d\n", i+1), m--;
    else
    {
      add+=A[i]*1ll*cp;
      addd+=A[i]*1ll*cp;
      cp++;
    }
  }  
  TIMESTAMP(end);
  return 0;
}