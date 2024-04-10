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

int LCA[1123123][22], n;
int d1=1, d2=1;
int Lv[1123123], res;

int lca (int v1, int v2)
{
  if (Lv[v1]<Lv[v2])
    swap(v1,v2);
  int dl=Lv[v1]-Lv[v2];
  for (int i=0; (1<<i)<=dl; i++)
    if (dl&(1<<i))
      dl-=(1<<i), v1=LCA[v1][i];
  if (v1==v2)
    return v1;
  for (int i=21; i>=0; i--)
    if (LCA[v1][i]!=LCA[v2][i])
      v1=LCA[v1][i], v2=LCA[v2][i];
  return LCA[v1][0];
}

void check (int v1, int v2)
{
  if (v1==v2)
    return;
  int v=lca(v1,v2);
  if (res<Lv[v1]+Lv[v2]-2*Lv[v])
    res=Lv[v1]+Lv[v2]-2*Lv[v], d1=v1, d2=v2;
}

void add (int p, int v)
{
  Lv[v]=Lv[p]+1;
  LCA[v][0]=p;
  for (int i=1; i<22; i++)
    LCA[v][i]=LCA[LCA[v][i-1]][i-1];
  check(d1,v);
  check(d2,v);
}
              
int main()
{
  int q;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d", &q);
  add(1,2), add(1,3), add(1,4);
  int n=4;
  while (q>0)
  {
    q--;
    int v;
    scanf("%d", &v);
    n++, add(v,n);
    n++, add(v,n);
    printf("%d\n", res);
  } 
  TIMESTAMP(end);
  return 0;
}