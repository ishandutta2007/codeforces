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
vector <long long> pf2;
int main(){
  long long a,b,cnt=1,ans=0;
  cin>>a>>b;
  pf2.push_back(1); 
  while (cnt<=b){
  	cnt*=2;
  	pf2.push_back(cnt);
  }
  for (long long i=0;i<pf2.size()-2;i++)
    for (long long j=i+2;j<pf2.size();j++){
      long long pk=pf2[j]-1-pf2[i];
      if (pk<=b && pk>=a) ans++;
    }
  cout<<ans;
  return 0;
}