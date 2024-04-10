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
long long a[100003];
int main(){
  long long n,num=0,ans1=0,ans2=0;
  cin>>n;
  for (long long i=0;i<n;i++){
    cin>>a[i];
    num+=a[i];
  }
  long long sml=num/n,bg=sml;
  if (num%n!=0) bg++;
  for (long long i=0;i<n;i++){
    if (a[i]<sml) ans1+=sml-a[i];
    if (a[i]>bg) ans2+=a[i]-bg;
  }
  cout<<max(ans1,ans2);
  return 0;
}