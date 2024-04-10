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
int a[10],b[10];
int n,m;
bool found(int x){
  for (int j=0;j<m;j++)
    if (b[j]==x) return true;
  return false;
}
int main(){
  cin>>n>>m;
  for (int i=0;i<n;i++)
    cin>>a[i];
  for (int i=0;i<m;i++)
    cin>>b[i];
  for (int i=0;i<n;i++){
  	if (found(a[i]))
	  cout<<a[i]<<" ";
  }
  return 0;
}