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

pair <int, int> M[110000];
int n, k;
long double h, V[110000];
int Id[110000];

bool solve (long double t)
{
  int e=0, id;
  for (int i=0; i<n; i++)
  {
    id=M[i].second;
    if (t*V[id-1]>=((long double)(e+1))*h)
      Id[e++]=id;
  }
  return e>=k;
}

bool cmp (pair <int, int> f, pair <int, int> s)
{
  return mp(mp(f.first,V[f.second-1]),f.second)<mp(mp(s.first,V[s.second-1]),s.second);
}

int main()
{
  int i, x;
  long double l, r, m;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &k);
  cin>>h;
  for (i=0; i<n; i++)
    scanf("%d", &M[i].first), M[i].second=i+1;
  for (i=0; i<n; i++)
    scanf("%d", &x), V[i]=x;
  sort(M,M+n,cmp);
  //for (i=0; i<n; i++)
    //cerr<<M[i].second<<endl;
  l=-1.0, r=2.0*inf;
  for (i=0; i<100; i++)
    m=(r+l)/2.0, (solve(m))?(r=m):(l=m);
  solve(r);
//  cerr<<r<<endl;
  for (i=0; i<k; i++)
    printf("%d ", Id[i]);
  printf("\n");
  return 0;
}