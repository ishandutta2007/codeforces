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

int res=2*inf+10;
int A[110000], S[110000];                       

int main()
{
  int n, l, r, ql, qr, t, i;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d%d%d%d", &n, &l, &r, &ql, &qr);
  for (i=0; i<n; i++)
    scanf("%d", &A[i]);
  for (i=0; i<n; i++)
    S[i+1]=S[i]+A[i];
  int sum=S[n];
  for (i=0; i<=n; i++)
  {
    t=inf;
    if (i==0)
      t=qr*(n-1);
    if (i==n)
      t=ql*(n-1);
    if (i!=0 && i!=n)
    {
      t=max(0,i-(n-i))*ql+max(0,n-2*i-1)*qr;
      t=min(t,max(0,i-(n-i)-1)*ql+max(0,n-2*i)*qr);
    }
    res=min(res,S[i]*l+(sum-S[i])*r+t);
  }
  printf("%d\n", res);  
  TIMESTAMP(end);
  return 0;
}