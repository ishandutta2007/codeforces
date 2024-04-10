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

int Y[3100][3100], C[3100][3100];
int ep=1, Sz[310000];
int dx[8]={-1,-1,-1,0,1,1, 1, 0};
int dy[8]={-1, 0, 1,1,1,0,-1,-1};
int Nx[8], Ny[8];
int c, pc;
int n, m, q;
                    
void dfs (int x, int y)
{
 // cerr<<"dfs  "<<x<<" "<<y<<"     "<<c<<" "<<pc<<endl;
  C[x][y]=c;
  int nx, ny, i;
  for (i=0; i<8; i++)
  {             
    nx=x+dx[i], ny=y+dy[i];
    if (ny<0)
      ny=m-1;
    if (ny==m)
      ny=0;
    if (C[nx][ny]==pc)
    {
      Y[nx][ny]=Y[x][y]+dy[i];
      dfs(nx,ny);
    }
  }
}

void merge (int xf, int yf, int xs, int ys)
{
  int i;
  //cerr<<"merge"<<endl;
  if (Sz[C[xf][yf]]>Sz[C[xs][ys]])
    swap(xf,xs), swap(yf,ys);
  Sz[C[xs][ys]]+=Sz[C[xf][yf]];
  for (i=0; i<3; i++)
    if ((ys+i)%m==(yf+1)%m)
    {
      Y[xf][yf]=Y[xs][ys]+i-1;
      break;
    }
  c=C[xs][ys], pc=C[xf][yf];
  dfs(xf,yf);
}

int main()
{
  int i, j, x, y, res=0;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d%d%d", &n, &m, &q);
  if (m==1)
  {
    puts("0");
    return 0;
  }
  while (q>0)
  {
    scanf("%d%d", &x, &y), q--, y--;

  /*  printf("%d %d\n\n", x, y);
     for (i=0; i<=n+1; i++, printf("\n"))
      for (j=0; j<m; j++)
        printf("%3d ", C[i][j]);
    printf("\n\n");
     for (i=0; i<=n+1; i++, printf("\n"))
      for (j=0; j<m; j++)
        printf("%3d ", Y[i][j]);
    printf("\n\n\n\n");   */

    for (i=0; i<8; i++)
    {
      Nx[i]=x+dx[i], Ny[i]=y+dy[i];
      if (Ny[i]<0)
        Ny[i]=m-1;
      if (Ny[i]==m)
        Ny[i]=0;
    }
    bool fl=0;
    for (i=0; i<8; i++)
      if (C[Nx[i]][Ny[i]])
        for (j=i+1; j<8; j++)
          if (C[Nx[i]][Ny[i]]==C[Nx[j]][Ny[j]])
          {
            if (Y[Nx[i]][Ny[i]]-dy[i]!=Y[Nx[j]][Ny[j]]-dy[j])
            {
             // if (x==1 && y==2)
             //   cerr<<Nx[i]<<" "<<Ny[i]<<"     "<<Nx[j]<<" "<<Ny[j]<<"         "<<Y[Nx[i]][Ny[i]]<<" "<<Y[Nx[j]][Ny[j]]<<endl;
              fl=1;
              break;
            }
          }
    if (fl)
      continue;
    res++;
  //  cout<<"  ::::    "<<x<<" "<<y<<endl;
    Sz[ep]=1, C[x][y]=ep, Y[x][y]=ep*10, ep++;
    for (i=0; i<8; i++)
      if (C[Nx[i]][Ny[i]]!=C[x][y] && C[Nx[i]][Ny[i]]!=0)
        merge(x,y,Nx[i],Ny[i]);
  }  
  printf("%d\n", res);
  TIMESTAMP(end);
  return 0;
}