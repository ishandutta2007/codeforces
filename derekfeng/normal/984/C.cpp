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
long long cnt(long long x,long long y)
{
	if (x%y==0) return y;
	else return cnt(y,x%y);
}
long long n,x,y,z,bigst;
int main(){
  cin>>n;
  for (long long i=0;i<n;i++){
    scanf("%I64d%I64d%I64d",&x,&y,&z);
    bigst=cnt(x,y);
    y/=bigst;
    bigst=z;
    while (y!=1){
      bigst=cnt(y,bigst);
      y/=bigst;
      if (bigst==1) break;
    }
    if (y==1)puts("Finite");
    else puts("Infinite");
  }
  return 0;
}