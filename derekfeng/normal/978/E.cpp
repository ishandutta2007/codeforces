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
long long oria[1003];
long long a[1003];
int main(){
  long long n,w,smal,bigg;
  cin>>n>>w;
  cin>>oria[0];
  a[0]=oria[0];
  for (int i=1;i<n;i++){
    cin>>oria[i];
    a[i]=a[i-1]+oria[i];
  }
  sort (a,a+n);
  smal=0-a[0];
  if (smal < 0) smal=0;
  bigg=w-a[n-1];
  if (bigg > w) bigg=w;
  long long ans=bigg-smal+1;
  if (ans > 0) cout<<ans;
  else cout<<"0";
  return 0;
}