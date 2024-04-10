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

char s[5][1234567];
int A[4][4], D[4], len;

void pr (int id)
{
  s[1][len]='b', s[2][len]='b', s[3][len]='b';
  s[0][len]='a', s[id][len]='a';
  int i, j;
  for (i=0; i<4; i++)
    for (j=i+1; j<4; j++)
      if (s[i][len]!=s[j][len])
        D[i]--, D[j]--, A[i][j]--, A[j][i]--;
  len++;
}

int main()
{
  int i, j, k;
  bool fl;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  for (i=0; i<3; i++)
    for (j=i+1; j<=3; j++)
      scanf("%d", &A[i][j]), A[j][i]=A[i][j];
  for (i=0; i<4; i++)
    for (j=0; j<4; j++)
      D[i]+=A[i][j];
  while (D[0]+D[1]+D[2]+D[3]>0)
  {
    for (i=0; i<4; i++)
      for (j=0; j<4; j++)
        if (A[i][j]<0)
        {
          puts("-1");
          return 0;
        }
    fl=0;
    for (i=0; i<4; i++)
      for (j=0; j<4; j++)
        if (D[i]>D[j])
        {
          for (k=0; k<4; k++)
            s[k][len]='b', D[k]--;
          s[i][len]='a', D[i]-=2;
          for (k=0; k<4; k++)
            if (i!=k)
              A[i][k]--, A[k][i]--;
          fl=1, len++;
        }
    if (fl)
      continue;
    for (i=1; i<=3; i++)
      for (j=1; j<=3; j++)
        if (A[0][i]<A[0][j])
        {
          pr(i);
          fl=1;
        }
    if (!fl)
      pr(1);
  }
  for (i=0; i<4; i++)
    for (j=0; j<4; j++)
      if (A[i][j]<0)
      {
        puts("-1");
        return 0;
      }
  printf("%d\n", len);
  for (i=0; i<4; i++)
    puts(s[i]);
  return 0;
}