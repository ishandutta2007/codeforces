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

int n, p, A[1100];
char s[1100];
               
bool check (int b)
{
  if (b>0 && A[b]==A[b-1]) 
    return 0;
  if (b>1 && A[b]==A[b-2]) 
    return 0;
  return 1;
}

int main()
{
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d %s", &n, &p, s);
  for (int i=0; i<n; i++)
    A[i]=s[i]-'a';
  for (int b=n-1; ; b--)
  {
    if (b<0)
    {
      puts("NO");
      return 0;
    }
    bool fl=1;
    while (fl)
    {
      A[b]++;
      if (A[b]>=p)
        break;        
      if (!check(b))
        continue;
      for (int i=b+1; ; i++)
      {
        if (i==n)
        {
          fl=0;
          break;
        }
        A[i]=0;
        while ((!check(i)) && A[i]<p)
          A[i]++;
        if (A[i]>=p)
          break;
      }
    }
    if (!fl)
      break;
  }
  for (int i=0; i<n; i++)
    s[i]=A[i]+'a';
  puts(s);  
  TIMESTAMP(end);
  return 0;
}