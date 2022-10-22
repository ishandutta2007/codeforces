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
int n;
int a[1003];
int main(){
  cin>>n;
  for (int i=0;i<n;i++)
    cin>>a[i];
  sort (a,a+n);
  if (n % 2 > 0)
    cout<<a[n/2];
  else cout<<a[n/2-1];
  return 0;
}