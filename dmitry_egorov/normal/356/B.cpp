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

int A[26], B[26];
ll res;
char s[1123123], l[1123123];
                  
int main()
{
  int i, j, lens, lenl;
  ll n,  m;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%I64d%I64d ", &n, &m);
  gets(s), lens=strlen(s), gets(l), lenl=strlen(l);
  int d=__gcd(lens,lenl);
  for (i=0; i<d; i++)
  {
    memset(B,0,sizeof(B));
    memset(A,0,sizeof(A));
    for (j=i; j<lens; j+=d)
      A[(int)(s[j]-'a')]++;
    for (j=i; j<lenl; j+=d)
      B[(int)(l[j]-'a')]++;
    for (j=0; j<26; j++)
      res+=A[j]*1ll*B[j];
  }
  printf("%I64d\n", n*1ll*lens-res*(n/(lenl/d))); 
  TIMESTAMP(end);
  return 0;
}