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

long long fd (long long a)
{
  while (a>=10ll)
    a/=10ll;
  return a;
}

long long solve (long long r)
{
  if (r<10)
    return r;
  long long res=0, d=1;
  while ((unsigned long long)r>=(unsigned long long)(d*10ll))
    d*=10ll;
  res=solve(d-1);
  while (r%10ll!=0ll)
  {
    if (fd(r)==r%10ll)
      res++;
    r--;
  }
  for (long long i=1; i<=9; i++)
    res+=max(0ll,min(d/10ll,r/10ll-i*(d/10ll)));
  return res;
}

int main()
{
  long long l, r;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  cin>>l>>r;
  cout<<solve(r)-solve(l-1)<<endl;
  return 0;
}