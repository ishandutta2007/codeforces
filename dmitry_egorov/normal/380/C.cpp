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
typedef pair<int,pii> node;

const int inf = 1e9;
const double eps = 1e-9;
const double INF = inf;
const double EPS = eps;

node merge (const node& a, const node& b)
{
  int add=min(a.second.first,b.second.second);
  node res=mp(a.first+b.first+add,mp(a.second.first+b.second.first-add,a.second.second+b.second.second-add));
  return res;
}

node A[(1<<21)+100];
char s[1123123];
int len;

int main()
{
  node lp, rp;
  int i, l, r, q;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  gets(s), len=strlen(s);
  for (i=0; i<len; i++)
  {
    if (s[i]=='(')
      A[i+(1<<20)]=mp(0,mp(1,0));
    else
      A[i+(1<<20)]=mp(0,mp(0,1));
  }
  for (i=(1<<20)-1; i>0; i--)
    A[i]=merge(A[i<<1],A[(i<<1)+1]);
  for (scanf("%d", &q); q>0; q--)
  {
    scanf("%d%d", &l, &r), l+=(1<<20)-1, r+=(1<<20);
    lp=mp(0,mp(0,0)), rp=mp(0,mp(0,0));
    while (l<r)
    {
      if (l&1)
        lp=merge(lp,A[l]), l++;
      if (r&1)
        r--, rp=merge(A[r],rp);
      l>>=1, r>>=1;
    }
    printf("%d\n", merge(lp,rp).first<<1);
  }
  TIMESTAMP(end);
  return 0;
}