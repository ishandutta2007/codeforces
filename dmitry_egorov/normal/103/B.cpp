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

bool A[110][110];
int S, Prev[110], St[110];
int cnt, n, m;

void dfs (int v)
{
  cnt++;
  for (int i=1; i<=n; i++)
    if (A[v][i] && v!=i && Prev[i]!=v)
    {
       if (Prev[i]==-1)
         Prev[i]=v, St[i]=St[v]+1, dfs(i);
       else
       {
         int t1=i, t2=v;
         while (St[t1]>St[t2])
           t1=Prev[t1];
         while (St[t1]<St[t2])
           t2=Prev[t2];
         while (t1!=t2)
           t1=Prev[t1], t2=Prev[t2];
         S=1+St[i]-2*St[t1]+St[v];
       }
    }
}

int main()
{
  int i, v1, v2;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &m);
  memset(Prev,-1,sizeof(Prev));
  Prev[1]=0;
  if (n!=m)
  {
    puts("NO");
    return 0;
  }
  for (i=0; i<m; i++)
    scanf("%d%d", &v1, &v2), A[v1][v2]=1, A[v2][v1]=1;
  dfs(1);
  //cerr<<S<<" "<<cnt<<endl;
  if (S>=2 && cnt==n)
    puts("FHTAGN!");
  else
    puts("NO");
  return 0;
}