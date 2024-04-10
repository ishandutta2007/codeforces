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

map <string, int> Sid;
int e, ev=1, ci, len;
char s[1234567];
vector <pair <int, int> > G[1234567];
int Prev[1234567];
int Cq[210], ecq, res;

pair <int, string> parse ()
{
  pair <int, string> res;
  assert(s[ci]=='<'), ci++;
  if (s[ci]=='/')
    ci++, res.first=1;
  int j=ci;
  while (s[j]!='/' && s[j]!='>')
    j++;
  res.second=string(s+ci,s+j), ci=j;
  if (s[ci]=='/')
    ci++, res.first=2;
  assert(s[ci]=='>'), ci++;
  if (Sid.count(res.second)==0)
    Sid[res.second]=e++;
  return res;
}

void dfs (int v, int cd)
{
  if (cd==ecq)
    res++, cd--;
  for (int i=0; i<(int)G[v].size(); i++)
    dfs(G[v][i].first,cd+((int)(G[v][i].second==Cq[cd])));
}

int main()
{
  pair <int, string> tmpp;
  int cv=0, q, j;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  gets(s), len=strlen(s);
  while (ci<len)
  {
    tmpp=parse();
    if (!tmpp.first)
      G[cv].pb(mp(ev,Sid[tmpp.second])), Prev[ev]=cv, cv=ev++;
    if (tmpp.first==1)
      cv=Prev[cv];
    if (tmpp.first==2)
      G[cv].pb(mp(ev,Sid[tmpp.second])), Prev[ev++]=cv;
  }
  scanf("%d ", &q);
  while (q>0)
  {
    q--, gets(s), len=strlen(s), ecq=0, ci=0;
    while (ci<len)
    {
      j=ci;
      while (s[j]!=' ' && s[j]!=0)
        j++;
      if (Sid.count(string(s+ci,s+j))==0)
        Sid[string(s+ci,s+j)]=e++;
      Cq[ecq++]=Sid[string(s+ci,s+j)], ci=j+1;
    }
    res=0, dfs(0,0);
    printf("%d\n", res);
  }                                         
  return 0;
}