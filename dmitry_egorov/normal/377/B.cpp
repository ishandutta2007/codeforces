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

const int maxn = 123123;             
pii A[maxn];
pair<pii,int> St[maxn];
set<pii> S;
int B[maxn], C[maxn], Res[maxn], RRes[maxn];
int n, m, s;

bool solve (int t)
{
  //cerr<<"solve="<<t<<endl;
  int cur=0, pos=0;
  int sum=0;
  S.clear();
  while (cur*t<m)
  {
    //cerr<<cur<<endl;
    while (pos<n && St[pos].first.first>=A[cur*t].first)
      S.insert(mp(St[pos].first.second,St[pos].second)), pos++;
    if (!S.size())
      return 0;
    sum+=S.begin()->first;
    Res[cur]=S.begin()->second;
    S.erase(S.begin());
    if (sum>s)
      return 0;
    cur++;
  }
  return 1;
}

int main()
{
  int i;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d%d", &n, &m, &s);
  for (i=0; i<m; i++)
    scanf("%d", &A[i].first), A[i].second=i;
  for (i=0; i<n; i++)
    scanf("%d", &B[i]);
  for (i=0; i<n; i++)
    scanf("%d", &C[i]);
  for (i=0; i<n; i++)
    St[i]=mp(mp(B[i],C[i]),i);
  sort(A,A+m);
  sort(St,St+n);
  reverse(St,St+n);
  reverse(A,A+m);
  int l=0, r=m;
  if (!solve(r))
  {
    puts("NO");
    return 0;
  } 
  while (r-l>1)
    (solve((l+r)/2))?(r=(l+r)/2):(l=(l+r)/2);
  puts("YES");
  assert(solve(r));
  for (i=0; i<m; i++)
    RRes[A[i].second]=Res[i/r];
  for (i=0; i<m; i++)
    printf("%d ", RRes[i]+1);
  printf("\n");
  TIMESTAMP(end);
  return 0;
}