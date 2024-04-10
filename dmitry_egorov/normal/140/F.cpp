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
#include <assert.h>

#define MPI 3.141592653589793238462643
#define eps 1e-8
#define inf ((int)1e9)
#define pb push_back
#define mp make_pair

using namespace std;

struct point 
{
  int x, y;
}A[210000];

bool operator < (point i, point j)
{
  if (i.x!=j.x)
    return i.x<j.x;
  return i.y<j.y;
}

bool operator == (point i, point j)
{
  return (i.x==j.x) && (i.y==j.y);
}

point operator + (point i, point j)
{
  point ret;
  ret.x=i.x+j.x, ret.y=i.y+j.y;
  return ret;
}

point operator - (point i, point j)
{
  point ret;
  ret.x=i.x-j.x, ret.y=i.y-j.y;
  return ret;
}

set <pair <double, double> > S;
int n, k;

void check (point p)
{
  //cerr<<p.x<<" "<<p.y<<endl;
  int nk=0, l=0, r=n-1;
  while (l<=r)
  {
    if (A[l]+A[r]==p)
    {
      l++, r--;
      continue;
    }
    if (p<A[l]+A[r])
    {
      nk++, r--;
      continue;
    }
    nk++, l++;
  }
  if (nk<=k)
    S.insert(mp(p.x,p.y));
}

int main()
{
  set <pair <double, double> > :: iterator it;
  int i, j;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &k);
  if (n<=k)
  {
    puts("-1");
    return 0;
  }
  for (i=0; i<n; i++)
    scanf("%d%d", &A[i].x, &A[i].y);
  sort(A,A+n);
  for (i=0; i<=k; i++)
    for (j=n-k+i-1; j<n; j++)
      check(A[i]+A[j]);
  printf("%d\n", S.size());
  for (it=S.begin(); it!=S.end(); it++)
    printf("%.8lf %.8lf\n", (it->first)/2.0, (it->second)/2.0);
  return 0;
}