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
#include <bits/stdc++.h>
using namespace std;
int n,l[303],r[303],k[303];
string s;
void change_nah(int a,int b,int p){
  string sc="";
  sc+=s.substr(b-p+1,p)+s.substr(a,b-a+1-p);
  for (int i=0;i<sc.size();i++) s[a+i]=sc[i];
}
int main(){
  cin>>s>>n;
  for (int i=0;i<n;i++){
    cin>>l[i]>>r[i]>>k[i];
    l[i]--;
    r[i]--;
    k[i]%=(r[i]-l[i]+1);
    change_nah(l[i],r[i],k[i]);
  }
  cout<<s;
  return 0;
}