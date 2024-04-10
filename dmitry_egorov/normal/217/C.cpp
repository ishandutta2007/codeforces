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

char s[1100000];
bool op[3][2][2];
bool C[1100000][2][2];

pair <pair <pair <bool, bool>, pair <bool, bool> >, int> parse (int l)
{
  pair <pair <pair <bool, bool>, pair <bool, bool> >, int> res;
  if (s[l]=='0' || s[l]=='1' || s[l]=='?')
  {
    if (s[l]=='?')
    {
      C[l][0][1]=1, C[l][1][0]=1;
      return mp(mp(mp(0,1),mp(1,1)),l+1);
    }
    (s[l]=='0')?(C[l][0][0]=1):(C[l][1][1]=1);
    return mp(((s[l]=='0')?(mp(mp(0,0),mp(1,0))):(mp(mp(1,1),mp(0,1)))),l+1);
  }
  pair <pair <pair <bool, bool>, pair <bool, bool> >, int> resf=parse(l+1), ress=parse(resf.second+1);
  int tp=-1;
  if (s[resf.second]=='&')
    tp=0;
  if (s[resf.second]=='|')
    tp=1;
  if (s[resf.second]=='^')
    tp=2;
  res.first.first.first=op[tp][resf.first.first.first][ress.first.first.first];
  res.first.first.second=op[tp][resf.first.first.second][ress.first.first.second];
  bool F[2]={resf.first.second.first,resf.first.second.second}, S[2]={ress.first.second.first,ress.first.second.second};
  bool R[2]={0,0};
  int i, j;
  //cerr<<F[0]<<" "<<F[1]<<"          "<<S[0]<<" "<<S[1]<<endl;
  for (i=0; i<2; i++)
    for (j=0; j<2; j++)
      if (F[i] && S[j])
        R[op[tp][i][j]]=1;
  res.second=ress.second+1, res.first.second=mp(R[0],R[1]);
  int p1=l+1, p2=resf.second+1;
  int k, t;
  for (i=0; i<2; i++)
    for (j=0; j<2; j++)
      for (k=0; k<2; k++)
        for (t=0; t<2; t++)
          if (C[p1][i][j] && C[p2][k][t])
/*            cerr<<i<<" "<<j<<" "<<k<<" "<<t<<"  ?  "<<op[tp][i][k]<<" "<<endl;*/C[l][op[tp][i][k]][op[tp][j][t]]=1;
  return res;
}

int main()
{
  int i, j, len;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  for (i=0; i<2; i++)
    for (j=0; j<2; j++)
      op[0][i][j]=(i&j), op[1][i][j]=(i|j), op[2][i][j]=(i^j);
  scanf("%d ", &len);
  gets(s);
  pair <pair <bool, bool>, pair <bool, bool> > res=parse(0).first;
  //cerr<<res.first.first<<" "<<res.first.second<<"          "<<res.second.first<<" "<<res.second.second<<endl;
  bool fl=1;
  if ((res.first.first || res.first.second) && (!res.second.second))
    fl=0;
  if (((!res.first.first) || (!res.first.second)) && (!res.second.first))
    fl=0;
  if (!(C[0][0][1] || C[0][1][0]))
    fl=0;
  //cerr<<C[0][0][1]<<" "<<C[0][1][0]<<endl;
  if (res.first.first!=res.first.second)
    fl=1;
  (fl)?(puts("YES")):(puts("NO"));
  return 0;
}