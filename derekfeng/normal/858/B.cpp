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
int a[103];
int b[103];
int n,m;
vector <int> d;
int main(){
  cin>>n>>m;
  int num=0,biggest=n;
  for (int i=0;i<m;i++)
    cin>>a[i]>>b[i];
  for (int i=0;i<m;i++)
    biggest=max(a[i],biggest);
  for (int i=1;i<=biggest;i++){
  	for (int j=0;j<m;j++)
  	  if ((a[j]+i-1) / i == b[j])
	    num++;
	if (num == m) d.push_back(i);
	num=0;
  }
  int chin=0;
  for (int i=1;i<d.size();i++)
    if ((d[i] + n - 1) / d[i] != (d[i-1] + n - 1) / d[i-1])
      chin++;
  if (chin==0) cout<<(n + d[0] - 1) / d[0];
  else cout<<"-1";
  return 0;
}