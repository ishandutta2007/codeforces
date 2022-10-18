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

pair <long long, long long> A[3];

pair <long long,long long> rot (pair <long long, long long> i)
{
  return mp(-i.second,i.first);
}

bool solve (void)
{
  pair <long long,long long> v=mp(A[1].first-A[0].first,A[1].second-A[0].second);
  long long s=v.first*A[2].first+v.second*A[2].second;
  long long k=A[2].first*A[2].first+A[2].second*A[2].second;
  if (k==0ll)
  {
    if (v.first==0ll && v.second==0ll)
      return 1;
    return 0;
  }
  if (s%k!=0ll)
    return 0;
  long long a=s/k;
  if (A[2].second==0ll)
  {
    if (a*A[2].first!=v.first)
      return 0;
    if ((v.second%A[2].first)!=0)
      return 0;
    return 1;
  }
  if (((a*A[2].first-v.first)%A[2].second)!=0)
    return 0;
  return 1;
}              

int main()
{
  int i;
  bool fl=0;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  for (i=0; i<3; i++)
    scanf("%I64d%I64d", &A[i].first, &A[i].second);
  for (i=0; i<4; i++)
    fl=(fl||solve()), A[0]=rot(A[0]);
  if (fl)
    puts("YES");
  else
    puts("NO");
  return 0;
}