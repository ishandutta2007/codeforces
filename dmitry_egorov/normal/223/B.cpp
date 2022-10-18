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

int D[2][210000], lens, lenl, P[2][210000][26];
char s[210000], l[210000];

int main()
{
  int i, j, k;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  gets(s), gets(l), lens=strlen(s), lenl=strlen(l);
  for (i=0; i<2; reverse(s,s+lens), reverse(l,l+lenl), i++)
  {
    for (j=0; j<lens; j++)
      (s[j]==l[D[i][j]])?(D[i][j+1]=D[i][j]+1):(D[i][j+1]=D[i][j]);
    for (j=0; j<lenl; P[i][j+1][(int)(l[j]-'a')]=j+1, j++)
      for (k=0; k<26; k++)
        P[i][j+1][k]=P[i][j][k];
  }
  for (i=0; i<lens; i++)
    if (P[0][D[0][i+1]][(int)(s[i]-'a')]+P[1][D[1][lens-i]][(int)(s[i]-'a')]<=lenl)
    {
      puts("No");
      return 0;
    }
  puts("Yes");
  return 0;
}