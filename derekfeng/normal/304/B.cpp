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
string s,t;
const int pi=3;
int getnum(string s,int p){
  int rid=0;
  while (s[p]!=':' && p<s.size()){
    rid=rid*10+s[p]-'0';
    p++;
  }
  return rid;
}
int a[2045],c[6];
int main(){
  cin>>s>>t;
  int ans=0;
  int k=getnum(s,0);
  int z=getnum(s,5);
  int x=getnum(s,8);
  int y=getnum(t,0);
  int n=getnum(t,5);
  int m=getnum(t,8),shu1=0,shu2=0;
  if (k>y){c[3]=k;c[4]=z;c[5]=x;c[0]=y;c[1]=n;c[2]=m;}
  else{if (y>k){c[0]=k;c[1]=z;c[2]=x;c[3]=y;c[4]=n;c[5]=m;}
       else{if (z>n){c[3]=k;c[4]=z;c[5]=x;c[0]=y;c[1]=n;c[2]=m;}
            else{if (n>z){c[0]=k;c[1]=z;c[2]=x;c[3]=y;c[4]=n;c[5]=m;}
            	 else{if (x>m){c[3]=k;c[4]=z;c[5]=x;c[0]=y;c[1]=n;c[2]=m;}
            	      else{c[0]=k;c[1]=z;c[2]=x;c[3]=y;c[4]=n;c[5]=m;}
                 }
            }
       }
  }
  a[1900]=365;
  for (int i=1901;i<2039;i++){
    if (i % 4 == 0)a[i]=366;
    else a[i]=365;
  }
  int b[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
  for (int i=1;i<=13;i++)
    b[i]+=b[i-1];
  for (int i=c[0]+1;i<c[3];i++)
    ans+=a[i];
  if (c[0]!=c[3])ans+=b[c[4]-1]+c[5];
  if (c[3]%4==0 && c[3]!=1900 && c[4]>2) ans++;
  if (c[0]!=c[3])ans+=a[c[0]]-b[c[1]-1]-c[2];
  if (c[2]>2 && a[c[0]]==366 && c[3] != c[0]) ans--;
  if (c[0]==c[3]){
    shu1+=b[c[1]-1]+c[2];
    if (c[1]>2 && c[0]%4==0) shu1++;
    shu2+=b[c[4]-1]+c[5];
    if (c[4]>2 && c[3]%4==0) shu2++;
    ans=shu2-shu1;
  }
  cout<<ans;
  return 0;
}