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

int Cnt[30], n;

bool solve (int a)
{
  int sz=0, i;
  for (i=0; i<26; i++)
    sz+=(Cnt[i]+a-1)/a;
  return sz<=n;
}

char s[1100];
       
int main()
{
  int i, j, len, l, r;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  gets(s), len=strlen(s);  
  scanf("%d", &n);
  for (i=0; i<len; i++)
    Cnt[(int)(s[i]-'a')]++;
  l=0, r=1100;
  if (!solve(r))
  {
    puts("-1");
    return 0;
  }
  while (r-l>1)
    solve((l+r)/2)?(r=(l+r)/2):(l=(l+r)/2);
  memset(s,0,sizeof(s));
  len=0;
  for (i=0; i<26; i++)
    for (j=0; j<(Cnt[i]+r-1)/r; j++)
      s[len]=(char)('a'+i), len++;
  while (len<n)
    s[len]='a', len++;
  printf("%d\n%s\n", r, s);
  TIMESTAMP(end);
  return 0;
}