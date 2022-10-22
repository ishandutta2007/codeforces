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
vector <int> v;
vector <int> ans;
bool check(int n){
  for (int i=0;i<v.size();i++)
    if (v[i]==n) return true;
  return false;
}
int main(){
  int n,num=0,cnt=0;
  string s;
  cin>>n>>s;
  for (int i=0;i<n;i++)
    if (s[i]=='x')
      v.push_back(i);
  int j=0;
  while (j<n){
  	if (check(j)){
  	  int ki=j,num=0;
  	  while (ki<n){
  	  	if (check(ki)){ki++;num++;}
  	  	else break;
  	  }
  	  ans.push_back(num);
  	  j=ki;
    }
    else j++;
  }
  for (int i=0;i<ans.size();i++){
    ans[i]=max(ans[i]-2,0);
    cnt += ans[i];
  }
  cout<<cnt;
  return 0;
}