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
                         
int R[2][3100][3100];
int S[3100][3100], M[3100][3100];
bool U[110000];
vi V;

inline void add (int tp, int r, int c1, int c2)
{
  for (int i=c1; i<=c2; i++)
    R[tp][r][i]=1;
}

//int gcnt;

void check (int xl, int yl)
{
  int xr=xl, yr=yl;
  int l=0, r=3001-max(xl,yl), m;
  while (r-l>1)
  {
    m=(l+r)/2;
    ((m+1)*(m+1)==S[xl+m][yl+m]+S[xl-1][yl-1]-S[xl+m][yl-1]-S[xl-1][yl+m])?(l=m):(r=m);
  }
  int mxr=xr+l;

//  m=l+1;
//  assert((m+1)*(m+1)!=S[xl+m][yl+m]+S[xl-1][yl-1]-S[xl+m][yl-1]-S[xl-1][yl+m]);
//  m=l;
//  cerr<<xl<<" "<<xr<<" "<<m<<"     "<<S[xl+m][xr+m]+S[xl-1][yl-1]-S[xl+m][yl-1]-S[xl-1][yl+m]<<endl;
//  assert((m+1)*(m+1)==S[xl+m][yl+m]+S[xl-1][yl-1]-S[xl+m][yl-1]-S[xl-1][yl+m]);

  for ( ; ; xr++, yr++)
  {
    //int sq=(xr-xl+1)*(yr-yl+1);
  //  gcnt++;
    if (xr>mxr)
      break;
    if ((M[xr][yr]&8)==0)
      continue;
    if ((M[xl][yr]&2)==0)
      continue;
    if ((M[xr][yl]&4)==0)
      continue;
    //if (sq!=S[xr][yr]+S[xl-1][yl-1]-S[xr][yl-1]-S[xl-1][yr])
    //  break;
    //cerr<<xl<<" "<<yl<<"    "<<xr<<" "<<yr<<endl;
    //cerr<<"??  "<<endl;
    if (xr-xl+1!=R[1][yl][xr]-R[1][yl][xl-1])
      continue;
    //cerr<<"??  "<<endl;

    if (xr-xl+1!=R[1][yr+1][xr]-R[1][yr+1][xl-1])
      continue;                       
   // cerr<<"??  "<<endl;

    if (yr-yl+1!=R[0][xl][yr]-R[0][xl][yl-1])
      continue;
   // cerr<<"??  "<<endl;

    if (yr-yl+1!=R[0][xr+1][yr]-R[0][xr+1][yl-1])
      continue;
   // cerr<<"??  "<<endl;
   
    for (int x=xl; x<=xr; x++)
      for (int y=yl; y<=yr; y++)
        if (!U[M[x][y]>>4])
          U[M[x][y]>>4]=1, V.pb(M[x][y]>>4);
    printf("YES %d\n", V.size());
    sort(V.begin(),V.end());
    for (int i=0; i<(int)V.size(); i++)
      printf("%d ", V[i]+1);
    printf("\n");
    exit(0);   
  }
}

int n, X1[110000], X2[110000], Y1[110000], Y2[110000];

int main()
{
  int i, tp, x, y, j;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d", &n);
  //n=100000;
  for (i=0; i<n; i++)
  {
    scanf("%d%d%d%d", &X1[i], &Y1[i], &X2[i], &Y2[i]);
    //X1[i]=rand()%2990, X2[i]=X1[i]+1+rand()%5;  
    //Y1[i]=rand()%2990, Y2[i]=Y1[i]+1+rand()%5;  
    X1[i]++, Y1[i]++;  
    add(0,X1[i],Y1[i],Y2[i]);
    add(0,X2[i]+1,Y1[i],Y2[i]);
    add(1,Y1[i],X1[i],X2[i]);
    add(1,Y2[i]+1,X1[i],X2[i]);
    M[X1[i]][Y1[i]]|=1;
    M[X1[i]][Y2[i]]|=2;
    M[X2[i]][Y1[i]]|=4;
    M[X2[i]][Y2[i]]|=8;
    for (x=X1[i]; x<=X2[i]; x++)
      for (y=Y1[i]; y<=Y2[i]; y++)
        M[x][y]+=(i<<4), S[x][y]=1;
  }
  for (i=1; i<=3000; i++)
    for (j=1; j<=3000; j++)
      S[i][j]+=S[i-1][j]+S[i][j-1]-S[i-1][j-1];
  for (tp=0; tp<2; tp++)
    for (i=0; i<3100; i++)
      for (j=1; j<3100; j++)
        R[tp][i][j]+=R[tp][i][j-1];
  for (i=0; i<n; i++)
    check(X1[i],Y1[i]);
  puts("NO");
  //cerr<<gcnt<<endl;
  TIMESTAMP(end);
  return 0;
}