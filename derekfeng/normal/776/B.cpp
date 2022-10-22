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
int ans[100004];
bool prime(int x){
  for (int i=2;i*i<=x;i++)
    if (x%i==0) return false;
  return true;
}
int main(){
  int n;
  cin>>n;
  for (int i=1;i<=n;i++){
    if (prime(i+1)) ans[i]=1;
    else ans[i]=2;
  }
  if (n>=3) cout<<"2"<<endl;
  else cout<<"1"<<endl;
  for (int i=1;i<=n;i++)
    cout<<ans[i]<<" ";
  return 0;
}