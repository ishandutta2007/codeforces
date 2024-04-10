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
bool flag;  
string s,tmp,ans;  
void dfs(string a,int req,int cnt){  
  if(flag)return;
  if(a.size()==req){
    if(cnt==a.size()/2)  
      if(a.size()>s.size()||a>=s){  
        ans=a;
        flag=true;
      }
    return;
  }
  dfs(a+"4",req,cnt+1);  
  dfs(a+"7",req,cnt);  
}
int main(){ 
  flag=0;  
  cin>>s;
  if(s.size()%2){  
    dfs("4",s.size()+1,1);  
    dfs("7",s.size()+1,0);  
  }else{  
    dfs("4",s.size(),1);  
    dfs("7",s.size(),0);  
    if(!flag){  
      dfs("4",s.size()+2,1);  
      dfs("7",s.size()+2,0);  
    }  
  }  
  cout<<ans<<endl;  
  return 0;  
}