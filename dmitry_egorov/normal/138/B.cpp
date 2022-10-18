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

char resf[110000], ress[110000], s[110000];
int len, A[12], B[12], C[12], res, ef, es;

void add (int f, int s)
{
  resf[ef++]=(char)(f+'0'), ress[es++]=(char)(s+'0');
}

void addf (int f)
{
  resf[ef++]=(char)(f+'0');
}

void adds (int s)
{
  ress[es++]=(char)(s+'0');
}

void madd (int f, int s, int num)
{
  while (num>0)
    add(f,s), num--;
}

int main()
{
  int i, j, cnt, d, cn;
  bool flf, fls;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  gets(s), len=strlen(s);
  for (i=0; i<len; i++)
    A[(int)(s[i]-'0')]++;
  for (i=1; i<=9; i++)
    madd(i,i,A[i]);
  madd(0,0,A[0]), res=A[0];
  for (i=1; i<=5; i++)
  {    
    memcpy(B,A,sizeof(A));
    memcpy(C,A,sizeof(A));

    if (B[i]==0 || C[10-i]==0) 
      continue;
    B[i]--, C[10-i]--, flf=0, fls=0;
    for (cnt=1, j=0; j<=9; j++)
      cnt+=min(B[j],C[9-j]);
    cn=min(B[0]-min(B[0],C[9]),C[0]-min(C[0],B[9])), cnt+=cn;
    if (cnt<=res)
      continue;
    res=cnt, ef=0, es=0;
    for (j=1; j<=9; j++)
    {
      while (B[j]>min(B[j],C[9-j]))
        addf(j), B[j]--;
      while (C[j]>min(C[j],B[9-j]))
        adds(j), C[j]--;
    }
    while (B[0]>cn+C[9])
      addf(0), B[0]--;
    while (C[0]>cn+B[9])
      adds(0), C[0]--;
    for (j=0; j<=9; j++)
      d=min(C[j],B[9-j]), madd(9-j,j,d), C[j]-=d, B[9-j]-=d;
    add(i,10-i);
    madd(0,0,B[0]);
  }
  printf("%s\n%s\n", resf, ress);
  return 0;
}