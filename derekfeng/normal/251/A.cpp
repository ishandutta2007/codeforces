#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#include <map>
#include <set>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
using namespace std;
long long a[100003];
int main()
{
  long long n,k,ans=0;
  cin>>n>>k;
  for(long long i=0;i<n;i++) 
	cin>>a[i];
  for (long long i=0;i<n-2;i++){
    long long bigst=upper_bound(a+i,a+n,a[i]+k)-a;
    bigst--;
    if(bigst-i>=2) ans+=(bigst-i)*(bigst-i-1)/2;
  }
  cout<<ans;
  return 0;
}