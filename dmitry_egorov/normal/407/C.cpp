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
const int maxn = 100500;
const int maxk = 105;

int C[maxn][maxk];
int T[maxn][maxk];
int n, m;  

void add (int l, int r, int k)
{ 
  int it=1, fk=k;
  while (l<r && k>=0)
  {
    T[l][it]+=C[fk][k];
    if (T[l][it]>=mod)
      T[l][it]-=mod;
    T[r][it]-=C[fk+r-l-1][k];
    if (T[r][it]<0)
      T[r][it]+=mod;
    it++, l++, k--;
  }
}

int main()
{
  int l, r, i, j, k;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  for (i=0; i<maxn; i++)
    for (C[i][0]=1, j=1; j<=i && j<maxk; j++)
    {
      C[i][j]=C[i-1][j-1]+C[i-1][j];
      if (C[i][j]>=mod)
        C[i][j]-=mod;
    }
  scanf("%d%d", &n, &m);
  for (i=0; i<n; i++)
    scanf("%d", &T[i][0]);
  while (m)
  {
    m--, scanf("%d%d%d", &l, &r, &k), l--;
    add(l,r,k);
  }
  for (i=maxk-1; i>0; i--)
  {
    int s=0;
    for (j=0; j<=n; j++)
    {
      s+=T[j][i];
      if (s>=mod)
        s-=mod;
      T[j][i-1]+=s;
      if (T[j][i-1]>=mod)
        T[j][i-1]-=mod;
      if (s>=mod)
        s-=mod;
    }
    //assert(s==0);
  }
  for (i=0; i<n; i++)
    printf("%d ", T[i][0]);
  printf("\n");
  TIMESTAMP(end);
  return 0;
}