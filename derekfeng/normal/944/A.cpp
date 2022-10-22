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
int rng(int n,int k){
  int m=n;
  while (m%k!=0){
    m--;
  }
  return m;
}
vector <int> num;
int main(){
  int n,a,b,cnt=1,ans=0;
  cin>>n>>a>>b;
  a--,b--;
  while (cnt<n){
    cnt*=2;
    num.push_back(cnt);
  }
  for (int i=0;i<num.size();i++){
  	ans++;
    if (rng(a,num[i])==rng(b,num[i])){break;}
  }
  if (num[ans-1]==n){cout<<"Final!";return 0;}
  cout<<ans;
  return 0;
}