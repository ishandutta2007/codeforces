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
int n,m;
long long a[200003];
long long x;
int main(){
  cin>>n>>m;
  for (int i=1;i<=n;i++){
    cin>>a[i];
    a[i]+=a[i-1];
  }
  int l,r;
  for (int i=1;i<=m;i++){
  	cin>>x;
    l=1;
    r=n;
    while (l<r-1){
      int mid=(l+r)/2;
      if (a[mid]>=x) r=mid;
      else l=mid;
	}
	if (a[l]>=x) r=l;
    cout<<r<<" "<<x-a[r-1]<<endl;
  }
}