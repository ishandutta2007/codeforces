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
long long n,h,low,high,mid,mx,a,b;
void midsearch(){
  while (high-low>1){
    mid=(high+low)/2;
    mx=mid*(mid+1)/2;
    if (h<mid){
      a=(mid-h+1)/2;
      b=(mid-h)/2+1;
      mx-=a*b;
    }
    if (mx>=n) high=mid;
    else low=mid;
  }
}
int main(){
  cin>>n>>h;
  low=0;
  high=2e9;
  midsearch();
  cout<<high<<endl;
  return 0;
}