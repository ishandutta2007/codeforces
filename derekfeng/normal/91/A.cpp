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
  string s1,s2;
  cin>>s1>>s2;
  int ans=1,x=-1,i;
  int d[26][100004],a[26]={0};
  for (i=0;i<s1.size();i++)
    d[s1[i]-'a'][a[s1[i]-'a']++]=i;
  for (i=0;i<s2.size();i++){
    int p=s2[i]-'a',l=-1,r=a[p],u=(l+r)/2;
    if (a[p]==0){
      puts("-1");
      return 0;
	}
    while (r-l>1){
   	  if (d[p][u]<=x){
   	    l=u;
   	    u=(l+r)/2;
      }else{
	    r=u;
	    u=(l+r)/2;
      }  
    }
    if (r<a[p]) x=d[p][r];
    else{
      ans++;
      x=d[p][0];
    }
  }
  cout<<ans;
  return 0;
}