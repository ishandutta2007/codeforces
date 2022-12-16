#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 52
#define LL "%I64d"

char chs[MAX];
long long int ocount[MAX];
long long int number;
long long int tpow[MAX];

void clr();
long long int from(long long int a, long long int b, int mmax);
long long int oneCount(int n, int max);
int cat(int n);

int main()
{
  clr();
  long long int l,r;

  scanf(LL, &number);
  scanf(LL, &l);
  scanf(LL, &r);

  int max = 1;
  while(tpow[max] <= number)
    ++max;

  printf(LL, from(l, r, max));
  printf("\n");
  

  return 0;
}

void clr()
{
  memset(chs, -1, sizeof(chs));
  memset(ocount, -1, sizeof(ocount));

  long long int val = 1;
  for(int i=0;i<MAX;++i)
  {
    tpow[i] = val;
    val *= 2;
  }
}

long long int from(long long int a, long long int b, int mmax)
{
  if(b < a)
    return 0;

  int nmax = 1;
  long long int boundary = 2;
  while(b >= boundary)
  {
    boundary *= 2;
    ++nmax;
  }

  if(a == 1 && b == 1)
    return cat(mmax);

  if(a == 1 && b == tpow[nmax]-1)
  {
    return oneCount(nmax, mmax);
  }

  long long int out;
  if( a <= tpow[nmax-1])
  {
    out = from(a, tpow[nmax-1]-1, mmax) + cat(mmax-nmax+1) + from(1, b-tpow[nmax-1], mmax);
  }
  else {
    out = from(a-tpow[nmax-1],b-tpow[nmax-1],mmax);
    }
  return out;
}

long long int oneCount(int n, int max)
{
  if(ocount[n] != -1)
    return ocount[n];
  if(n == 1)
  {
    ocount[1] = cat(max);
    return cat(max);
  }
  long long int val = oneCount(n-1, max)*2+cat(max-n+1);
  ocount[n] = val;
  return val;
}

int cat(int n)
{
  int m = n-1;
  if(chs[m] != -1)
    return chs[m];
  long long int ncpy = number;
  for(int i=0;i<m;++i)
  {
    ncpy /= 2;
  }
  chs[m] = ncpy%2;
  return chs[m];
}