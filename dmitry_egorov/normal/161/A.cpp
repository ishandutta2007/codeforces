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

pair <int, int> A[110000], B[110000];
vector <pair <int, int> > Res;

int main()
{
  int n, m, x, y, i, j, tmp;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d%d%d", &n, &m, &x, &y);
  for (i=0; i<n; i++)
    scanf("%d", &tmp), A[i]=mp(tmp,i);
  for (i=0; i<m; i++)
    scanf("%d", &tmp), B[i]=mp(tmp,i);
  sort(A,A+n), sort(B,B+m), i=0, j=0;
  while (i<n && j<m)
  {
    if (A[i].first-x<=B[j].first && A[i].first+y>=B[j].first)
    {
      //cerr<<i<<" "<<j<<endl;
      Res.pb(mp(A[i].second,B[j].second)), i++, j++;
      continue;
    }
    if (A[i].first-x>B[j].first)
    {      
      j++;
      continue;
    }
    if (A[i].first+y<B[j].first)
      i++;
  }
  printf("%d\n", Res.size());
  for (i=0; i<(int)Res.size(); i++)
    printf("%d %d\n", Res[i].first+1, Res[i].second+1);
  return 0;
}