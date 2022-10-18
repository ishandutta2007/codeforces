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

map <int, vector <int> > M;
vector <int> V;
map <int, vector <int> > :: iterator it;
int Res[110000], ct, cx;

int main()
{
  int n, m, i, j, x, t;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (i=0; i<n; )
  {
    for (M.clear(), j=0; j<m && i<n; j++, i++)
      scanf("%d%d", &t, &x), ct=max(ct,t), M[x].pb(i);
    for (it=M.begin(); it!=M.end(); it++)
    {                     
      V=it->second, ct+=it->first-cx, cx=it->first;
      for (j=0; j<(int)V.size(); j++)
        Res[V[j]]=ct;
      ct+=1+((int)V.size())/2;
    }
    ct+=cx, cx=0;
  }
  for (i=0; i<n; i++)
    printf("%d ", Res[i]);
  printf("\n");
  return 0;
}