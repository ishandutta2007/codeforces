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

int len[2], A[2][1123123], C[1123123][3][3];
char s[2][1123123];
long long res;
bool u[100][100];


int main()
{
  int i, l=0, r=0, j, k;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  for (i=0; i<2; i++)
    for (gets(s[i]), len[i]=strlen(s[i]), j=0; j<len[i]; j++)
    {
      if (s[i][j]=='R')
        A[i][j]=1;
      if (s[i][j]=='B')
        A[i][j]=2;
    }
  /*u[0][0]=1;
  int ii, jj;
  for (i=0; i<len[0]; i++, cerr<<endl)
    for (j=0; j<len[1]; j++)
    {
      if (u[i][j])
        for (k=0; k<3; k++)
        {
          (A[0][i]==k)?(ii=i+1):(ii=i);
          (A[1][j]==k)?(jj=j+1):(jj=j);
          u[ii][jj]=1;
        }
    } */
  for (i=0; i<len[0]-1; i++)
  {
    for (j=0; j<3; j++)
      for (k=0; k<3; k++)
        C[i+1][j][k]=C[i][j][k];
    C[i+1][A[0][i]][A[0][i+1]]++;
  }   
  while (r<len[0]-1 && A[0][r]!=A[1][0])
    r++;
  for (i=0; i<len[1]; i++)
  {
    res+=r-l+1;
    if (i>0 && A[1][i]!=A[1][i-1])
      res-=C[r][A[1][i]][A[1][i-1]]-C[l][A[1][i]][A[1][i-1]];
    if (i!=len[1]-1)
    {
      if (A[1][i]==A[0][l])
        l++;
      if (l>=len[0])
        break;
      r=min(r+1,len[0]-1);
      while (r<len[0]-1 && A[0][r]!=A[1][i+1])
        r++;
    }
  }
  printf("%I64d\n", res);
  return 0;
}