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

int res, resl, resr, len;
int lb=-1, lbr=-10;
int Cnt[110000];
int St[110000], e;
char s[110000];
vector <pair <int, int> > V;

void add (int l, int r)
{
  while (V.size() && V.back().first>=l && V.back().second<=r)
    V.pop_back();
  V.pb(mp(l,r));
}

int main()
{
  int i, j;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  gets(s), len=strlen(s);
  for (i=1; i<=len; Cnt[i]+=Cnt[i-1], i++)
    if (s[i-1]=='[')
      Cnt[i]++;
  for (i=0; i<len; i++)
  {
    if (s[i]=='[' || s[i]=='(')
    {
      St[e++]=i;
      continue;
    }
    if (e==0 || (s[i]==']' && s[St[e-1]]!='[') || (s[i]==')' && s[St[e-1]]!='('))
    {
      e=0;
      continue;
    }
    add(St[e-1],i+1), e--;
  }
  for (i=0; i<(int)V.size(); i=j)
  {
    j=i+1;
    while (j<(int)V.size() && V[j].first==V[j-1].second)
      j++;
    if (res<Cnt[V[j-1].second]-Cnt[V[i].first])
      res=Cnt[V[j-1].second]-Cnt[V[i].first], resl=V[i].first, resr=V[j-1].second;
  }
  printf("%d\n", res);
  for (i=0; i<resr-resl; i++)
    s[i]=s[resl+i];
  s[resr-resl]=0, puts(s);
  return 0;
}