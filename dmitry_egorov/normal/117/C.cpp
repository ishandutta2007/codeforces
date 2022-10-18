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

int n, Prev[5100], Deg[5100][2];
bool u[5100], u2[5100];
char s[5100][5100];

void dfs (int v)
{
  //cerr<<v<<endl;
  int i, v2, v3;
  u2[v]=1;
  for (i=0; i<n; i++)
    if (!u[i] && s[v][i]=='1')
    {
      if (u2[i])
      {
        //cerr<<"!!!!"<<endl;
        v2=v, v3=Prev[v];
        //cerr<<i<<" "<<v2<<" "<<v3<<endl;
        while (s[i][v3]=='0')
          v2=Prev[v2], v3=Prev[v3];
        printf("%d %d %d\n", v3+1, v2+1, i+1);
        exit(0);
      }
      Prev[i]=v;
      dfs(i);
    }
}

int main()
{
  int i, j;
  bool fl;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d ", &n);
  for (i=0; i<n; i++)
    gets(s[i]);
  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
    {
      //cerr<<s[i][j]<<" ";
      if (s[i][j]=='1')
        Deg[i][0]++;
      if (i!=j && s[i][j]=='0')
        Deg[i][1]++;
    }
  fl=1;
  while (fl)
  {
    //cerr<<"!!!!"<<endl;
    fl=0;
    for (i=0; i<n; i++)
      if (!u[i] && (Deg[i][0]==0 || Deg[i][1]==0))
      {
        for (j=0; j<n; j++)
        {
          if (s[j][i]=='1')
            Deg[j][0]--;
          else
            Deg[j][1]--;
        }
        fl=1, u[i]=1;
        break;
      }
    //cerr<<"????"<<endl;
  }
  for (i=0; i<n; i++)
    if (!u[i])
       dfs(i);
  printf("-1\n");
  return 0;
}