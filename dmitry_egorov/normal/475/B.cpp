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

int n, m, D[410][410];
char s[30];
                 
int main()
{
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d ", &n, &m);
  for (int i=0; i<n*m; i++)
    for (int j=0; j<n*m; j++)
      if (i!=j)
        D[i][j]=inf;
  scanf(" %s", s);
  for (int i=0; i<n; i++)
    for (int j=0; j<m-1; j++)
    {
      int id1=m*i+j;
      int id2=id1+1;
      (s[i]=='>')?(D[id1][id2]=1):(D[id2][id1]=1);
    }
  scanf(" %s", s);
  for (int i=0; i<m; i++)
    for (int j=0; j<n-1; j++)
    {
      int id1=m*j+i;
      int id2=id1+m;
      (s[i]=='v')?(D[id1][id2]=1):(D[id2][id1]=1);
    }
  for (int i=0; i<n*m; i++)
    for (int j=0; j<n*m; j++)
      for (int k=0; k<n*m; k++)
        D[j][k]=min(D[j][k],D[j][i]+D[i][k]);
  for (int i=0; i<n*m; i++)
    for (int j=0; j<n*m; j++)
      if (D[i][j]==inf)
      {
        puts("NO");
        return 0;
      }
  puts("YES"); 
  TIMESTAMP(end);
  return 0;
}