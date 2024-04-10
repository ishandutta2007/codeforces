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

int good, A[223123];
int ex, n;
pii X[223123];
map <int,int> MtoM, M;
int C[223123];

void add (int x, int dif)
{
  if (x<0 || x>=n)
    return;
  x=A[x]; 
  if (x==-1)
    return;
  if (C[x]==X[x].second)
    good--;
  C[x]+=dif;
  if (C[x]==X[x].second)
    good++;
}
        
bool u[223123];

int main()
{
  int i, b, p, m, x;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d%d", &n, &m, &p);
  if (1+(m-1)*1ll*p>n)
  {
    puts("0");
    return 0;
  }
  for (i=0; i<n; i++)
    scanf("%d", &A[i]);
  for (i=0; i<m; i++)
  {
    scanf("%d", &x);
    int tmp=M[x];
    M[x]=tmp+1;
  }
  for (map<int,int> :: iterator it=M.begin(); it!=M.end(); it++)
    X[ex++]=*it;
  sort(X,X+ex);
  for (i=0; i<ex; i++)
    MtoM[X[i].first]=i;
  for (i=0; i<n; i++)
  {
    if (M.count(A[i])==0)
    {
      A[i]=-1;
      continue;
    }
    A[i]=MtoM[A[i]];
  }
  //for (i=0; i<n; i++)
  //  cerr<<A[i]<<" ";
  //cerr<<endl;
  for (b=n-1; b>=n-p; b--)
  {
    for (i=b; i>=-p*m; i-=p)
    {
      add(i,1);
   //   cerr<<i<<" "<<b<<" "<<good<<"      "<<C[0]<<" "<<C[1]<<" "<<C[2]<<endl;
      if (good==ex)
      {
        assert(0<=i && i<n);
        u[i]=1;
      }
      add(i+p*(m-1),-1);
    }  
  }
  int res=0;
  for (i=0; i<n; i++)
    if (u[i])
      res++;
  printf("%d\n", res);
  for (i=0; i<n; i++)
    if (u[i])
      printf("%d ", i+1);
  printf("\n"); 
  TIMESTAMP(end);
  return 0;
}