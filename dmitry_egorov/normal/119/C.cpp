#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <utility>

//#define M_PI 3.141592653589793238462643
#define eps 1e-8
#define inf ((int)1e9)
#define pb push_back
#define mp make_pair

using namespace std;

struct triple
{
  int c, id;
  long long a, b;
}A[60];

bool check (triple a, triple b)
{
  if (a.c!=b.c)
    return a.c<b.c;
  return a.id<b.id;
}

long long D[55][55][110];
int Prev[55][55][110][2];

void write (int sta, int stb, int n)
{
 // cerr<<n<<endl;
  if (n!=0)
  {
    int ta=Prev[n][sta][stb][0], tb=Prev[n][sta][stb][1];
    write(ta,tb,n-1);
    printf("%d %I64d\n", A[sta].id, D[n][sta][stb]-D[n-1][ta][tb]);
  }
  else
    printf("%d %I64d\n", A[sta].id, D[0][sta][stb]);
}

int main()
{
  int n, i, j, l, t, m, sta=-1, stb=-1;
  long long k, res=-1ll, tmp;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d%I64d", &n, &m, &k);
  for (i=0; i<m; i++)
    scanf("%I64d%I64d%d", &A[i].a, &A[i].b, &A[i].c), A[i].id=i+1;
  sort(A,A+m,check);
  //for (i=0; i<m; i++)
  //  cerr<<A[i].id<<" "<<A[i].a<<" "<<A[i].b<<" "<<A[i].c<<endl;
  memset(D,-1,sizeof(D));
  for (i=0; i<m; i++)
    for (j=0; j<=A[i].b-A[i].a; j++)
      D[0][i][j]=A[i].a+((long long)j);
  for (i=1; i<n; i++)
    for (j=0; j<m; j++)
      for (l=0; l<=A[j].b-A[j].a; l++)  
      {
        for (t=0; A[t].c<A[j].c; t++)
        {
          tmp=((long long)l)+A[j].a;
          if (tmp-k>=A[t].a && tmp-k<=A[t].b)
            if (D[i][j][l]<tmp+D[i-1][t][tmp-k-A[t].a] && D[i-1][t][tmp-k-A[t].a]!=-1ll)
              D[i][j][l]=tmp+D[i-1][t][tmp-k-A[t].a], Prev[i][j][l][0]=t, Prev[i][j][l][1]=tmp-k-A[t].a;
          if (tmp%k==0 && (tmp/k)>=A[t].a && (tmp/k)<=A[t].b)
            if (D[i][j][l]<tmp+D[i-1][t][tmp/k-A[t].a] && D[i-1][t][tmp/k-A[t].a]!=-1ll)
              D[i][j][l]=tmp+D[i-1][t][tmp/k-A[t].a], Prev[i][j][l][0]=t, Prev[i][j][l][1]=tmp/k-A[t].a;
        }
        //if (D[i][j][l]!=-1)
        //  cerr<<i<<" "<<j<<" "<<l<<" "<<D[i][j][l]<<endl;
      }
  for (i=0; i<m; i++)
    for (j=0; j<=A[i].b-A[i].a; j++)
      if (res<D[n-1][i][j])
        res=D[n-1][i][j], sta=i, stb=j;
  if (res==-1ll)
  {
    puts("NO");
    return 0;
  }
  puts("YES");
  write(sta,stb,n-1);
  return 0;
}