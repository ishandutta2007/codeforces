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
#define mod (1000000007)

using namespace std;

int Tree[(1<<19)];
map <int,int> XtoX;
int X[210000];
pair <int,int> A[110000];

int sum (int l, int r)
{
  int res=0;
  l+=(1<<18), r+=(1<<18);
  while (l<=r)
  {
    if (l%2==1)
      res+=Tree[l], res%=mod, l++;
    if (r%2==0)
      res+=Tree[r], res%=mod, r--;
    l/=2, r/=2;
  }
  return res;
}

void add (int v, int d)
{
  v+=(1<<18);
  while (v>=1)
  {
    Tree[v]+=d, Tree[v]%=mod;
    v/=2;
  }
}

int main()
{
  int i, n, m, e;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (i=0; i<m; i++)
    scanf("%d%d", &A[i].second, &A[i].first), X[2*i]=A[i].second, X[2*i+1]=A[i].first;
  X[2*m]=0, X[2*m+1]=n;
  sort(X,X+(2*m+2));
  e=unique(X,X+(2*m+2))-X;
  for (i=0; i<e; i++)
    XtoX[X[i]]=i;
  for (i=0; i<m; i++)
    A[i].first=XtoX[A[i].first], A[i].second=XtoX[A[i].second];
  sort(A,A+m);
  add(0,1);
  for (i=0; i<m; i++)
    add(A[i].first,sum(A[i].second,A[i].first-1));
  printf("%d\n", sum(e-1,e-1));
  return 0;
}