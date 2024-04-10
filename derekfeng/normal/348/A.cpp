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
#include  <list>
#include  <utility>
#include  <memory>
#include  <cstring>
#include  <fstream>
#include  <numeric>
using namespace std;
long long n;
long long a[100003];
bool check(long long r){
  long long i,sum=0;
  for (i=0;i<n;i++) if (a[i]>r) return false;
  for (i=0;i<n;i++) sum+=r-a[i];
  return (sum>=r);
}
int main(){
  long long i;
  cin>>n;
  for (i=0;i<n;i++)
    cin>>a[i];
  long long low=0,high=1000000000011;
  while (high-low>1){
  	long long mid=(low+high)/2;
  	if (check(mid)) high=mid;
  	else low=mid;
  }
  cout<<high;
  return 0;
}