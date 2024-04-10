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
                         
int n, l, t;
ll tadd;
int A[2123123];

int main()
{               
  int i, c, r;
  ld res;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d%d", &n, &l, &t), t*=2;
  for (i=0; i<n; i++)
    scanf("%d", &A[i]);
  sort(A,A+n);
  for (i=n; i<2*n; i++)
    A[i]=A[i-n]+l;
  c=t/l, r=t%l, res=((long double)c)*((long double)(n*1ll*(n-1.0))), res/=4.0;
  for (i=0; i<n; i++)
    tadd+=lower_bound(A+i+1,A+i+n,A[i]+r+1)-A-i-1;// cerr<<tadd<<" "<<A[2]<<endl;
  //cerr<<res<<" "<<tadd<<"     "<<c<<" "<<r<<endl;
  res+=((long double)tadd)/4.0;
  printf("%.8lf\n", (double)(res));   
  TIMESTAMP(end);
  return 0;
}