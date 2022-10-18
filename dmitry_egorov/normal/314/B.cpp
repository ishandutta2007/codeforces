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

const int inf = 1e9+100;
const double eps = 1e-9;
const double INF = inf;
const double EPS = eps;

int N[110], L[2], N2[110];
char s[2][110];
                         
int main()
{
  int len=0, res=0, tmp, ce, i, j, it, b, d;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d ", &b, &d);
  for (i=0; i<2; i++)
    gets(s[i]), L[i]=strlen(s[i]);
  for (it=0; it<L[0]; it++)
  {
    ce=0, i=it, j=0;
    while (ce<11000 && j<L[1])
    {
      if (s[0][i]==s[1][j])
        j++;
      i++, ce++;
      if (i==L[0])
        i=0;
    }
    (ce==11000)?(N[it]=inf):(N[it]=ce);
  }  
  for (it=0; it<L[0]; it++)
  {
    N2[it]=0;
    for (i=0; i<9987; i++)
    {
      N2[it]=N2[it]+N[(it+N2[it])%L[0]];
      if (N2[it]>=inf)
      {
        N2[it]=inf;
        break;
      }
    }
  }
  while (len+N2[len%L[0]]<=L[0]*b)
    res+=9987, len+=N2[len%L[0]];
  while (len<=L[0]*b)
    res++, tmp=N[len%L[0]], assert(tmp), len+=tmp;
  printf("%d\n", (res-1)/d);
  TIMESTAMP(end);
  return 0;
}