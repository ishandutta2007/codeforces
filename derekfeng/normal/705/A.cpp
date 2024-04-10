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
#include <list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
#include <bits/stdc++.h>
using namespace std;
string s[2]={"I hate ","I love "};
int main(){
  int n;
  cin>>n;
  for (int i=0;i<n;i++){
    cout<<s[i%2];
    if (i==n-1)cout<<"it";
    else cout<<"that ";
  }
  return 0;
}