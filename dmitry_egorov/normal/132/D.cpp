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

char s[2][1100000];
int l, add;
int D[2][1100000][2];
vector <pair <char, int> > Res;

int main()
{
  int i, j, nj;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  gets(s[0]+1);
  l=strlen(s[0]+1), l++;
  //cerr<<l<<" "<<s[0][1]<<s[0][2]<<s[0][3]<<s[0][4]<<endl;
  while (s[0][l-1]=='0')
    l--, add++;
  //cerr<<l<<endl;
  for (s[1][l-1]='1', i=0; i<l-1; i++)
    (s[0][i]=='0')?(s[1][i]='1'):(s[1][i]='0');
  for (i=l-1, D[0][i][0]=1, D[1][i][0]=1, i--; i>=0; i--)
    for (j=0; j<2; j++)
    {
      if (s[j][i]=='1')
      {
        D[j][i][0]=1+D[j][i+1][0], D[j][i][1]=j;
        continue;
      }
      if (D[j][i+1][0]<=1+D[1-j][i+1][0])
        D[j][i][0]=D[j][i+1][0], D[j][i][1]=j;
      else
        D[j][i][0]=1+D[1-j][i+1][0], D[j][i][1]=1-j;
    }
  for (i=0, j=0; i<l; j=nj, i++)
  {
    nj=D[j][i][1];
    if (D[j][i][0]!=D[nj][i+1][0])
    {
      if (j==0)
        Res.pb(mp('+',add+l-1-i));
      else
        Res.pb(mp('-',add+l-1-i));
    }
  }
  printf("%d\n", Res.size());
  for (i=0; i<(int)Res.size(); i++)
    printf("%c2^%d\n", Res[i].first, Res[i].second);
  return 0;
}