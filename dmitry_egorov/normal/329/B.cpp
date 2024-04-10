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
                         
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
char s[1100][1100];
int D[1100][1100];
bool C[1100][1100];
int W[1100][1100];
int Q[1100*1100][2];
int bq, eq=1;
int n, m, sx, sy, mx, my;

int main()
{
  int i, j, x, y, nx, ny;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d ", &n, &m);
  for (i=0; i<n; i++)
    gets(s[i]);
  for (i=0; i<n; i++)
    for (j=0; j<m; j++)
    {
      if (s[i][j]=='T')
        continue;
      C[i+1][j+1]=1;
      if (s[i][j]=='S')
        mx=i+1, my=j+1;
      if (s[i][j]=='E')
        sx=i+1, sy=j+1;
      if ('0'<=s[i][j] && s[i][j]<='9')
        W[i+1][j+1]=(int)(s[i][j]-'0');
    }  
  //cerr<<sx<<" "<<sy<<"      "<<mx<<" "<<my<<endl;
  Q[0][0]=sx, Q[0][1]=sy;
  memset(D,-1,sizeof(D));
  D[sx][sy]=0;
  while (bq<eq)
  {
    x=Q[bq][0], y=Q[bq][1], bq++;
    for (i=0; i<4; i++)
    {
      nx=x+dx[i], ny=y+dy[i];
      if (C[nx][ny] && D[nx][ny]==-1)
        D[nx][ny]=D[x][y]+1, Q[eq][0]=nx, Q[eq][1]=ny, eq++;
        
    }
  }
  int res=0;
  for (i=1; i<=n; i++)
  {
    for (j=1; j<=m; j++)
    {
      //cerr<<D[i][j]<<" ";
      if (D[i][j]!=-1 && D[i][j]<=D[mx][my])
        res+=W[i][j];
    }
    //cerr<<endl;
  }
  printf("%d\n", res);
  TIMESTAMP(end);
  return 0;
}