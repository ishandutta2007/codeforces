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

string tp="RGBYW";

int conv (char c)
{
  for (int i=0; i<5; i++)
    if (c==tp[i])
      return i;
  assert(0);
}
     
bool conv (int msk, int v)
{
  return (msk&(1<<v))!=0;
}

bool match (int msk, int v1, int v2)
{
  bool c1=conv(msk,v1);
  bool c2=conv(msk,v2);
  return (c1!=c2) || (v1!=v2 && c1 && c2);
}

int C[10][10];

int main()
{
  int i, j, k, l, v, n;
  char c;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d", &n);
  for (i=0; i<n; i++)
  {
    scanf(" %c%d", &c, &v), v--;
    C[conv(c)][v]++;
  }  
  int res=inf;
  for (int msk1=0; msk1<32; msk1++)
  for (int msk2=0; msk2<32; msk2++)
  {
    bool fl=0;
    for (i=0; i<5; i++)
      for (j=0; j<5; j++)
        if (C[i][j])
          for (k=0; k<5; k++)
            for (l=0; l<5; l++)
              if (C[k][l] && (i!=k || j!=l))
              {
                if ((!match(msk1,i,k)) && (!match(msk2,j,l)))
                  fl=1;
              }
    if (!fl)
    {
     // cerr<<msk1<<" "<<msk2<<endl;
      res=min(res,__builtin_popcount((msk1<<5)|msk2));
    }
  }
  assert(res<inf);
  cout<<res<<endl;
  TIMESTAMP(end);
  return 0;
}