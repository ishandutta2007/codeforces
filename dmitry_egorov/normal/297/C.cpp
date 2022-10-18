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

set <int> S;
int Res[2][110000], n, mn, p1, p2, p3;
pair <int, int> A[110000];

void add (int id, int f)
{
  Res[0][A[id].second]=f, Res[1][A[id].second]=A[id].first-f;
  S.insert(A[id].first-f);
}

int main()
{
  int i, last, j;
  memset(Res,-1,sizeof(Res));
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d", &A[i].first), A[i].second=i;
  sort(A,A+n);
  puts("YES");
  mn=n-((n+2)/3), p1=(mn+1)/2, p3=mn-p1, p2=n-mn;
  for (i=0; i<p1; i++)
    add(i,i);
  for (i=1; i<=p3; i++)
    add(n-i,mn-p3+i-1);
  for (last=0, i=0; i<p2; i++)
  {
    while (last<A[i+p1].first && S.count(last))
      last++;
    add(i+p1,A[i+p1].first-last);
    last++;
  }
  assert((int)S.size()>=mn);
  for (i=0; i<2; i++, printf("\n"))
    for (j=0; j<n; j++)
      printf("%d ", Res[i][j]), assert(0<=Res[i][j]); 
  return 0;
}