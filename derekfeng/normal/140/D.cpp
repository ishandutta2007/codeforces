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
  int n;
  cin>>n;
  for (int i=0;i<n;i++)
    cin>>a[i];
  sort (a,a+n);
  int ans=0,cnt=10;
  for (int i=0;i<n;i++){
    if (cnt+a[i]>720){cout<<i<<" "<<ans;return 0;}
    else{cnt+=a[i];ans+=max(0,cnt-360);}
  }
  cout<<n<<" "<<ans;
  return 0;
}