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

int main()
{

  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  long long k, b, n, t, a=1ll;
  cin>>k>>b>>n>>t;
  while (a*k+b<=t)
    n--, a*=k, a+=b;
  cout<<max(0ll,n)<<endl;
  return 0;
}