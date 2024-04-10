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
#include<list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
using namespace std;
int a[103];
int main(){
  int n,m,i;
  cin>>n>>m;
  for (int i=0;i<n;i++)
    cin>>a[i];
  sort (a,a+n);
  int cnt=0;
  for (i=n-2;i>=0;i--){
    a[i]+=a[i+1];
  }
  for (i=n-1;i>=0;i--){
    if (a[i]>=m){cout<<n-i;return 0;}
  }
}