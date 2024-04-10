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

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
         
int N[2][1100*1100*4];
ll T[110000];
int V[110000];

int main()
{
  int x, y, n, q, a, b, c, d, bb, it;
  int i, j, k, nx, ny;
  char ch;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d", &n, &b);
  for (i=0; i<=b; i++)
    for (j=0; j<=b; j++)
      for (k=0; k<4; k++)
      {
        nx=i+dx[k], ny=j+dy[k];
        nx=max(nx,0), nx=min(nx,b);
        ny=max(ny,0), ny=min(ny,b);
        N[0][(i*(b+1)+j)*4+k]=(nx*(b+1)+ny)*4+k;
      }
  for (i=0; i<n; i++)
  {
    scanf("%d%d%d%d", &a, &bb, &c, &d);
  //  cerr<<"??   "<<i<<endl;
    assert(a!=c || bb!=d);
    int len=abs(a-c)+abs(bb-d);
    for (it=0; it<4; it++)
      if (c==a+len*dx[it] && d==bb+len*dy[it])
      {
        //cerr<<i<<"    "<<it<<"    "<<dx[it]<<" "<<dy[it]<<endl;
        for (j=0; j<=len; j++)
        {
          x=a+j*dx[it], y=bb+j*dy[it];
          int id=(x*(b+1)+y)*4;
          for (k=0; k<4; k++)
          {
            N[0][id+k]=N[0][id+it];
          }
        }
        break;
      }
  }

 /* for (i=0; i<(b+1)*(b+1); i++, printf("\n"))
    for (j=0; j<4; j++)
      printf("(%d  %d    %d)   ", N[0][4*i+j]/(4*(b+1)), (N[0][4*i+j]/4)%(b+1), N[0][4*i+j]%4);

  printf("\n\n\n");  */

  //for (i=1; i<55; i++)
  //  for (j=0; j<(b+1)*(b+1)*4; j++)
  //    N[i][j]=N[i-1][N[i-1][j]]; 
  scanf("%d", &q);
  for (i=0; i<q; i++)
  {
    scanf("%d%d %c %I64d", &x, &y, &ch, &T[i]);
    V[i]=(x*(b+1)+y)*4;
    if (ch=='L')
      V[i]++;
    if (ch=='U')
      V[i]+=2;
    if (ch=='D')
      V[i]+=3;
  }
  for (it=0; it<55; it++)
  {
    for (i=0; i<q; i++)
      if (T[i]&(1ll<<it))
        V[i]=N[0][V[i]];
    for (j=0; j<(b+1)*(b+1)*4; j++)
      N[1][j]=N[0][N[0][j]]; 
    memcpy(N[0],N[1],sizeof(N[0]));
  }
  for (i=0; i<q; i++)
    printf("%d %d\n", V[i]/(4*(b+1)), (V[i]/4)%(b+1));
  TIMESTAMP(end);
  return 0;
}