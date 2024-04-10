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
int n;
int a[54];
bool flag[1003];
vector <int> don;
int main(){
  cin>>n;
  for (int i=0;i<n;i++)
    cin>>a[i];
  for (int i=n-1;i>=0;i--)
    if (flag[a[i]]!=true){
      don.push_back(a[i]);
      flag[a[i]]=true;
    }
  cout<<don.size()<<endl;
  for (int i=don.size()-1;i>=0;i--)
    cout<<don[i]<<" ";
  return 0;
}