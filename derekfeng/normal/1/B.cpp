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
  int n;
  cin >> n;
  for(int i = 0; i<n; i++){
    string s;
    cin >> s;
    int j = 0;
    while(s[j]>'9') j++;
    while(s[j]<'A'&&j<s.size()) j++;
    if(j==s.size()){
      int k = 0, c = 0, r = 0;
      while(s[k]>'9'){
        r = 26*r+(s[k]+1-'A');
        k++;
      }
    cout<<"R"<<s.substr(k)<<"C"<<r<<endl;
    }
	else{
      int k=0,r=0,e;
      string res = "";
      while(s[k]!='C') k++;
      e=k;
      k++;
      while(k<s.size()){
      r=10*r+(s[k]-'0');
      k++;
      }
      while(r>0){
        res = (char)((r-1)%26+'A')+res;
        r-=(r-1)%26+1;
        r/=26;
      }
      cout<<res<<s.substr(1,e-1)<<endl;
    }
    }
  return 0;
}