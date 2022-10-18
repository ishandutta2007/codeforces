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

bool operator < (pair<int,int> i, pair<int,int> j)
{
  if (i.first<j.first)
    return 1;
  if (i.first>j.first)
    return 0;
  return i.second<j.second;
}

set <pair<int,int> > B;
int A[110000], n;
int R[110000];

int main()
{
  set <pair<int,int> > :: iterator it;
  int i;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d", &A[i]);
  for (i=n-1; i>=0; i--)
  {
    it=B.lower_bound(mp(A[i],i));
    if (it==B.begin())
      R[i]=-1;
    else
    {
      it--;
      R[i]=R[(*it).second]+(*it).second-i;
    }
    B.insert(mp(A[i],i));
  }
  for (i=0; i<n; i++)
    printf("%d ", R[i]);
  printf("\n");
  return 0;
}