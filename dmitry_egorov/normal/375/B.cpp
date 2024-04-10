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

int A[5100][5100], res;
char s[5100];
                       
int main()
{
  int i, j, n, m;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d ", &n, &m);
  for (i=0; i<n; i++)
  {
    gets(s);
    int l=m-1;
    for (j=m-1; j>=0; j--)
    {
      if (s[j]=='0')
        l=j-1;
      else
        A[j][l]++;// cerr<<j<<" "<<l<<endl;
    }
  }
  for (i=0; i<m; i++)
    for (j=m-1; j>i; j--)
      A[i][j-1]+=A[i][j];
  for (i=0; i<m; i++)
    for (j=i; j<m; j++)
      res=max(res,A[i][j]*(j-i+1));
  printf("%d\n", res); 
  TIMESTAMP(end);
  return 0;
}