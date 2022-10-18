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

vector <int> G[110000];
int n, m, h, t, E[110000][2];
int B[210], eb;
int F[210], ef;
int S[210], es;
set <int> :: iterator it;


void check (int v1, int v2)
{
  int i;
  if ((int)G[v1].size()<h+1 || (int)G[v2].size()<t+1)
    return;
  eb=0, ef=0, es=0;
  int f=1, s=1, nvf=G[v1][0], nvs=G[v2][0];
  if ((int)G[v1].size()>t+h+5)
  {
    set <int> u;
    u.insert(v1), u.insert(v2);
    puts("YES");
    printf("%d %d\n", v1+1, v2+1), i=0;
    while ((int)u.size()<t+1)
      u.insert(G[v2][i++]);
    int cnt=0;
    i=0;
    while (cnt<h-1)
    {
      if (!u.count(G[v1][i]))
        cnt++, printf("%d ", G[v1][i]+1); 
      i++;
    }
    printf("\n");
    for (it=u.begin(); it!=u.end(); it++)
      if ((*it)!=v1 && (*it)!=v2)
        printf("%d ", (*it)+1);
    printf("\n");
    exit(0);
  }
  if ((int)G[v2].size()>t+h+5)
  {
    set <int> u;
    u.insert(v1), u.insert(v2);
    puts("YES");
    printf("%d %d\n", v1+1, v2+1), i=0;
    while ((int)u.size()<h+1)
      u.insert(G[v1][i++]);
    for (it=u.begin(); it!=u.end(); it++)
      if ((*it)!=v1 && (*it)!=v2)
        printf("%d ", (*it)+1);

    printf("\n");

    int cnt=0;
    i=0;         
    while (cnt<t-1)
    {
      if (!u.count(G[v2][i]))
        cnt++, printf("%d ", G[v2][i]+1); 
      i++;
    }

    printf("\n");
    exit(0);
  }
  //cerr<<endl;
  while (nvf<inf || nvs<inf)
  {
    if (nvf==nvs)
      B[eb++]=nvf, nvf=G[v1][f++], nvs=G[v2][s++];
    else
      (nvf<nvs)?(F[ef++]=nvf, nvf=G[v1][f++]):(S[es++]=nvs, nvs=G[v2][s++]);
    //cerr<<nvf<<" "<<nvs<<" "<<f<<" "<<s<<endl;
  }
   //cerr<<v1<<" "<<v2<<"        "<<ef<<" "<<es<<" "<<eb<<"           "<<t<<" "<<h<<endl;

  if (ef+eb<h || es+eb<t || ef+es+eb<t+h)
    return;

    t--, h--;
  int nf=min(h,ef-1), nfb=h-nf, ns=min(t,es-1), nsb=t-ns;

  //cerr<<ef<<" "<<es<<" "<<eb<<endl;
  //cerr<<S[0]<<" "<<S[1]<<" "<<S[2]<<" "<<S[3]<<endl;
  puts("YES");
    printf("%d %d\n", v1+1, v2+1);
  for (i=0; i<nf; i++)
  {
    if (F[i]!=v2)
      printf("%d ", F[i]+1);
    else
      nf++;
  }
  for (i=0; i<nfb; i++)
    printf("%d ", B[i]+1);
  printf("\n");


  for (i=0; i<ns; i++)
  {
    if (S[i]!=v1)
    printf("%d ", S[i]+1);
    else
      ns++;
  }
  for (i=0; i<nsb; i++)
    printf("%d ", B[i+nfb]+1);
  printf("\n");


  exit(0);
}

int main()
{
  int i, v1, v2;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d%d%d", &n, &m, &h, &t), h++, t++;
  for (i=0; i<m; i++)
    scanf("%d%d", &v1, &v2), v1--, v2--, G[v1].pb(v2), G[v2].pb(v1), E[i][0]=v1, E[i][1]=v2;
  for (i=0; i<n; i++)
    sort(G[i].begin(),G[i].end()), G[i].pb(inf);
  for (i=0; i<m; i++)
  {
    if ((int)(G[E[i][0]].size()+G[E[i][1]].size())<h+t)
      continue;
    check(E[i][0],E[i][1]);
    check(E[i][1],E[i][0]);
  }
  puts("NO");
  return 0;
}