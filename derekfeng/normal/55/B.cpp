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
long long a[4],k1[3],k2[2];
char b[3];
int main(){
  long long ans;
  for (int i=0;i<4;i++)
    cin>>a[i];
  for (int j=0;j<3;j++)
    cin>>b[j];
  sort (a,a+4);
  if (b[0]=='*'){k1[0]=a[0]*a[1];k1[1]=a[2];k1[2]=a[3];}
  else{k1[0]=a[0];k1[1]=a[1];k1[2]=a[2]+a[3];}
  sort (k1,k1+3);
  if (b[1]=='*'){k2[0]=k1[0]*k1[1];k2[1]=k1[2];}
  else{k2[0]=k1[1]+k1[2];k2[1]=k1[0];}
  if (b[2]=='+'){ans=k2[0]+k2[1];}
  else{ans=k2[0]*k2[1];}
  if (b[0]=='*' && b[1]=='*' && b[2]=='+') ans=min(ans,a[0]*a[3]+a[1]*a[2]);
  if (b[0]=='*' && b[1]=='+' && b[2]=='*') ans=min(ans,(a[1]*a[2]+a[3])*a[0]);
  cout<<ans;
  return 0;
}