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
vector <int> am[11];
int a[200003];
int main(){
  int n,m,cnt=0;
  cin>>n>>m;
  for (int i=0;i<n;i++){
  	cin>>a[i];
    am[a[i]].push_back(i);
  }
  for (int j=0;j<11;j++)
  	for (int i=0;i<am[j].size();i++){
  	  cnt+=(n-1-am[j][i])-(am[j].size()-1-i);
	}
  cout<<cnt;
  return 0;
}