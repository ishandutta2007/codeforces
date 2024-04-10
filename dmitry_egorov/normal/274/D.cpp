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

vector <vector <int> > B;
vector <vector <pair <int, int> > > A;
set <pair <int, int> > S;
int n, m, Deg[110000], Cnt[110000], Cb[110000], Val[110000];
vector <int> Res;

void inc (int col)
{
  S.erase(mp(-Deg[col],col)), Deg[col]++, S.insert(mp(-Deg[col],col));
}

void add (int str)
{
  Val[str]=A[str][Cb[str]].first;
  while (A[str][Cb[str]].first==Val[str])
    inc(A[str][Cb[str]].second), Cnt[str]++, Cb[str]++;
}

int main()
{
  int i, v, x, j;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &m);
  A.resize(n), B.resize(n);
  for (i=0; i<n; i++)
    A[i].resize(m+1), B[i].resize(m+1);
  for (i=0; i<n; i++)
    for (j=0; j<m; j++)
      scanf("%d", &x), B[i][j]=x, A[i][j]=mp(x,j);
  for (i=0; i<=m; i++)
    S.insert(mp(0,i));
  for (i=0; i<n; i++)
  {
    A[i][m]=mp(inf+100,m), sort(A[i].begin(),A[i].end());
    while (A[i][Cb[i]].first==-1)
      inc(A[i][Cb[i]].second), Cb[i]++;
    add(i);
  }
  while (S.size())
  {
    v=S.begin()->second, S.erase(S.begin());
    if (Deg[v]!=n)
    {
      printf("-1\n");
      return 0;
    }
    if (v==m)
    {
      assert((int)Res.size()==m);
      for (i=0; i<m; i++)
        printf("%d ", Res[i]+1);
      printf("\n");
      return 0;
    }
    Res.pb(v);
    for (i=0; i<n; i++)
      if (Val[i]==B[i][v])
      {
        Cnt[i]--;
        if (Cnt[i]==0)
          add(i);
      }
  }
  assert(0);
  return 0;
}