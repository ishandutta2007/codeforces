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

ll n, Deg[20], Res[6];
int P[20][6][4];
bool u[20][6];

void calc (int v, int f)
{
  //cerr<<v<<" "<<f<<endl;
  if (v==0)
    return;
  for (int i=0; i<P[v][f][0]; i++)
    Res[i]+=Deg[v-1]*7ll;
  for (int i=0; i<P[v][f][1]; i++)
    Res[i+P[v][f][0]]+=Deg[v-1]*4ll;
  calc(P[v][f][2],P[v][f][3]);
}

void solve ()
{
  //cerr<<"Solve !!!"<<endl;
  int x, y, i, j, k, l;
  memset(P,-1,sizeof(P));
  memset(u,0,sizeof(u));
  u[0][0]=1;
  scanf("%I64d", &n);
  for (i=0; i<18; i++)
    for (j=0; j<6; j++)
      if (u[i][j])  
      {
        //cerr<<i<<" !!!  "<<j<<endl;
        for (k=0; k<=6; k++)
          for (l=0; k+l<=6; l++)
          {
            //cerr<<"??? "<<l<<" "<<k<<endl;
           // cerr<<"    "<<n<<" "<<Deg[i]<<endl;
           // cerr<<"     "<<j+7*k+4*l<<endl;
            if ((j+7*k+4*l)%10==(n/Deg[i])%10)
            {
             // cerr<<"WERTY"<<endl;
              x=i+1, y=(j+7*k+4*l)/10;
              //cerr<<x<<" "<<y<<endl;
              u[x][y]=1;
              P[x][y][0]=k;
              P[x][y][1]=l;
              P[x][y][2]=i;
              P[x][y][3]=j;
            }
            //cerr<<"WEGH"<<endl;
          }
      }
  if (!u[18][n/Deg[18]])
  {
    puts("-1");
    return;
  }
  memset(Res,0,sizeof(Res));
  calc(18,n/Deg[18]);
  for (i=0; i<6; i++)
    printf("%I64d ", Res[i]);
  printf("\n");
}
               
int main()
{
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  int tst;
  Deg[0]=1;
  for (int i=0; i<20; i++)
    Deg[i+1]=Deg[i]*10ll;
  scanf("%d", &tst);
  while (tst>0)
    solve(), tst--; 
  TIMESTAMP(end);
  return 0;
}