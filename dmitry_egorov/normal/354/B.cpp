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

int D[42][(1<<20)+100];
int N[30];
char s[23][23];                 

int main()
{
  int i, j, add, n, k, x, y;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  for (i=0; i<42; i++)
    for (j=0; j<(1<<20)+100; j++)
      D[i][j]=inf;
  scanf("%d ", &n);
  for (i=0; i<n; i++)  
    gets(s[i]);// puts(s[i]);   
  /*#ifdef LOCAL
  n=20;
  srand(time(NULL));
  for (i=0; i<20; i++)
    for (j=0; j<20; j++)
      s[i][j]='a'+rand()%7;
  #endif    */
  D[0][1]=-inf;
  for (i=0; i<2*n-2; i++)
  {
    int plen=min(i+1,2*n-1-i), poff=max(0,i-n+1);
    int noff=max(0,i-n+2);
    //cerr<<i<<" "<<plen<<" "<<poff<<" "<<noff<<endl;
    for (j=1; j<(1<<plen); j++)
      if (D[i][j]==-inf)
      {
        //cerr<<"?DFGH??   "<<i<<" "<<j<<"   "<<D[i][j]<<endl;
        memset(N,0,sizeof(N));
        for (k=0; k<plen; k++)
          if (j&(1<<k))
          {
            y=poff+k, x=i-y;
            #ifdef LOCAL
            assert(0<=x && x<n && 0<=y && y<n);
            #endif
            if (x+1<n)
              N[(int)(s[x+1][y]-'a')]|=(1<<(y-noff));
            if (y+1<n)
              N[(int)(s[x][y+1]-'a')]|=(1<<(y+1-noff));
          }
        //cerr<<N[0]<<" "<<N[1]<<" "<<N[2]<<" "<<N[3]<<endl;
        for (k=0; k<26; k++)
        {
          add=0;
          if (k<2)
            (k^(i&1))?(add=1):(add=-1);
          if (N[k]!=0)
            D[i+1][N[k]]=-inf;
        }
      }
  }
  if (s[n-1][n-1]=='a')
    D[2*n-2][1]=1;
  if (s[n-1][n-1]=='b')
    D[2*n-2][1]=-1;
  if (s[n-1][n-1]!='a' && s[n-1][n-1]!='b')
    D[2*n-2][1]=0;
  int tmp;
  for (i=2*n-3; i>=0; i--)
  {
    int plen=min(i+1,2*n-1-i), poff=max(0,i-n+1);
    int noff=max(0,i-n+2);
    //cerr<<i<<" "<<plen<<" "<<poff<<" "<<noff<<endl;
    for (j=1; j<(1<<plen); j++)
      if (D[i][j]==-inf)
      {
        add=-2;
        //cerr<<"???   "<<i<<" "<<j<<"   "<<D[i][j]<<endl;
        memset(N,0,sizeof(N));
        for (k=0; k<plen; k++)
          if (j&(1<<k))
          {
            y=poff+k, x=i-y;
            if (add==-2)
            {
              add=0, tmp=s[x][y]-'a';
              if (tmp<2)
                ((i&1)^tmp)?(add=1):(add=-1);
            }
            #ifdef LOCAL
            assert(0<=x && x<n && 0<=y && y<n);
            #endif
            if (x+1<n)
              N[(int)(s[x+1][y]-'a')]|=(1<<(y-noff));
            if (y+1<n)
              N[(int)(s[x][y+1]-'a')]|=(1<<(y+1-noff));
          }
        //cerr<<N[0]<<" "<<N[1]<<" "<<N[2]<<" "<<N[3]<<endl;
        for (k=0; k<26; k++)
          if (N[k]!=0)
            D[i][j]=max(D[i][j],D[i+1][N[k]]);
        D[i][j]+=add;
        D[i][j]*=-1;
        //cerr<<"???   "<<i<<" "<<j<<"   "<<D[i][j]<<endl;
      }
  }
  if (D[0][1]==0)
    puts("DRAW");
  if (D[0][1]>0)
    puts("FIRST");
  if (D[0][1]<0)
    puts("SECOND");
  TIMESTAMP(end);
  return 0;
}