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
#define maxp (239017ll)

using namespace std;

long long Deg[5000];
long long Hash[5000], Ht, Hz;
long long A[2100], e;
int res, ls, lt, lz;
char s[2100], t[2100], z[2100];

inline long long get(int l, int r)
{
  return (Hash[r]-Hash[max(l,0)])*Deg[4000-max(l,0)];
}

int main()
{
  int i, j;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  Deg[0]=1;
  for (i=1; i<5000; i++)
    Deg[i]=Deg[i-1]*maxp;
  gets(s);
  gets(t);
  gets(z);
  ls=strlen(s), lt=strlen(t), lz=strlen(z);
  for (i=0; i<ls; i++) 
    Hash[i+1]=Hash[i]+Deg[i]*((long long)(s[i]));
  for (i=0; i<lt; i++) 
    Ht+=Deg[i]*((long long)(t[i]));
  for (i=0; i<lz; i++) 
    Hz+=Deg[i]*((long long)(z[i]));
  Ht*=Deg[4000], Hz*=Deg[4000];  
  for (i=max(lt,lz); i<=ls; i++)
  {
    e=0;
    for (j=0; j+i<=ls; j++)
      if (get(j,j+lt)==Ht && get(j+i-lz,j+i)==Hz)
      A[e]=get(j,j+i), e++;
    sort(A,A+e);
    e=unique(A,A+e)-A;
    res+=e;
  }
  printf("%d\n", res);
  return 0;
}