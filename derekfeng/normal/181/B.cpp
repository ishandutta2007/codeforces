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
typedef pair<int,int> pii;
int n,x,y,res=0;
pii arr[3004];
set<pii> s;
int main(){
  cin>>n;
  for (int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    arr[i]=pii(a,b);
    s.insert(arr[i]);
  }
  for (int i=0;i<n;i++){
    for (int j=i+1;j<n;j++){
      x=arr[i].first+arr[j].first;
      y=arr[i].second+arr[j].second;
      if (x%2==0 && y%2==0){
      	x/=2,y/=2;
      	res+=(s.find(pii(x,y))!=s.end());
       }
    }
  }
  cout<<res;
  return 0;
}