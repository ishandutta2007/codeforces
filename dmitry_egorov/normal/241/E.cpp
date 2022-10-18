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

set <pair <int, int> > S;
int D[1100], Deg[1100], n, m;
bool u[1100], u2[1100];
vector <int> G[1100], RG[1100];
int A[5100][2];
int e, C[5100];

void dfs (int v)
{
  u[v]=1;
  for (int i=0; i<(int)G[v].size(); i++)
    if (!u[G[v][i]])
      dfs(G[v][i]);
}

void rdfs (int v)
{
  u2[v]=1;
  for (int i=0; i<(int)RG[v].size(); i++)
    if (!u2[RG[v][i]])
      rdfs(RG[v][i]);
}

int main()
{
  int i, v1, v2, v, j;
  bool fl=0, fl2=1;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (i=0; i<m; i++)
    scanf("%d%d", &v1, &v2), v1--, v2--, G[v1].pb(v2), RG[v2].pb(v1), A[i][0]=v1, A[i][1]=v2;
  dfs(0), rdfs(n-1);
  for (i=0; i<n; i++)
    if (!u2[i])
      u[i]=0;


    for (i=0; i<n; i++)
      if (u[i])
      {
        for (j=0; j<(int)RG[i].size(); j++)
          if (u[RG[i][j]])
            Deg[i]++;
        S.insert(mp(Deg[i],i));
      }  
    while (S.size())
    {
      v=S.begin()->second, S.erase(S.begin());
      for (i=0; i<(int)G[v].size(); i++)
        if (u[G[v][i]])
        {
          S.erase(mp(Deg[G[v][i]],G[v][i]));
          D[G[v][i]]=max(D[G[v][i]],D[v]+1);
          S.insert(mp(Deg[G[v][i]]-1,G[v][i]));
        }
    }

  for (i=0; i<m; i++)
    if (u[A[i][0]] && u[A[i][1]])
      C[e++]=i;
  random_shuffle(C,C+e);
  while (fl2==1)
  {
    fl2=0;  
    for (i=0; i<e; i++)
      if (D[A[C[i]][1]]-D[A[C[i]][0]]>2)
      {
        if (A[C[i]][0]==0)
        {
          puts("No");
          return 0;
        }
        D[A[C[i]][0]]++, fl2=1;
      }
      for (i=0; i<e; i++)
        if (D[A[C[i]][1]]-D[A[C[i]][0]]<1)
          D[A[C[i]][1]]++, fl2=1;
    /*cerr<<"!!!!"<<endl;
    for (i=0; i<n; i++)
      cerr<<D[i]<<" ";//endl;
    cerr<<endl;
    for (i=0; i<m; i++)
      cerr<<A[i][0]<<" "<<A[i][1]<<" "<<L[i]<<endl;
    if (D[4]==4)
      return 0;   */
  }
  for (i=0; i<m; i++)
    if (u[A[i][0]] && u[A[i][1]] && D[A[i][1]]-D[A[i][0]]!=1 && D[A[i][1]]-D[A[i][0]]!=2)
      fl=1;
  if (fl) 
  {
    puts("No");
    return 0;
  }
  puts("Yes");
  for (i=0; i<m; i++)
  {
    if (u[A[i][0]] && u[A[i][1]])
      printf("%d\n", D[A[i][1]]-D[A[i][0]]);
    else
      puts("1");
  }
  return 0;
}