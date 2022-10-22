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
int main(){
  int a1,b1,l=0,r=0,u=0,d=0;
  string c,a,b;
  cin>>a>>b;
  a1=a[0]-b[0];
  b1=a[1]-b[1];
  cout<<max(abs(a1),abs(b1))<<endl;
  if (a1>0) l=a1;
  if (a1<0) r=a1;
  if (b1<0) u=b1;
  if (b1>0) d=b1;
  c=a;
  while (c!=b){
    if (r<0){r++;cout<<"R";c[0]++;}
    if (l){l--;cout<<"L";c[0]--;}
    if (u<0){u++;cout<<"U";c[1]++;}
    if (d){d--;cout<<"D";c[1]--;}
    cout<<endl;
  }
  return 0;
}