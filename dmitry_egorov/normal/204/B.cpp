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

int res=inf;
map <int, pair <int, int> > M;
map <int, pair <int, int> > :: iterator it;

void add (int c, pair <int, int> p)
{
  if (M.count(c)==0)
    M[c]=p;
  else
    M[c]=mp(M[c].first+p.first,M[c].second+p.second);
}

int main()
{
  int n, a, b, i;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n; i++)
  {
    scanf("%d%d", &a, &b);
    add(a,mp(1,0));
    if (a!=b)
      add(b,mp(0,1));
  }
  n=(n+1)/2;
  for (it=M.begin(); it!=M.end(); it++)
    if (it->second.first+it->second.second>=n)
      res=min(res,max(0,n-it->second.first));
  if (res==inf)
    res=-1;
  cout<<res<<endl;
  return 0;
}