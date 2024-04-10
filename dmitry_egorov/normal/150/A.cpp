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

bool A[1234567];
vector <long long> V;

int main()
{
  long long n;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%I64d", &n);
  for (long long i=1; i*i<=n; i++)
    if (n%i==0)
    {
      V.pb(i);
      if (i*i!=n)
        V.pb(n/i);
    }
  sort(V.begin(),V.end());
  for (int i=0; i<(int)V.size(); i++)
  {
    bool fl=0, fl2=0;
    for (int j=1; j<i; j++)
      if (V[i]%V[j]==0)
      {
        fl=1;
        if (A[j]==0)
          fl2=1;
      }
    if ((!fl) || fl2)
      A[i]=1;
  }
  if (A[(int)V.size()-1]==0)
  {
    puts("2");
    return 0;
  }
  puts("1");
  for (int i=1; i<(int)V.size()-1; i++)
    if (n%V[i]==0 && A[i]==0)
    {
      printf("%I64d\n", V[i]);
      return 0;
    }
  puts("0");
  return 0;
}