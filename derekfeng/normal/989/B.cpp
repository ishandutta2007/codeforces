// DerekFeng creat rubbish code
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
char l(char c){
  if (c=='0') return '1';
  if (c=='1') return '0'; 
}
bool u[2003];
int main(){
  int n,p,qub=0;
  bool flag=false;
  cin>>n>>p;
  string s;
  cin>>s;
  for (int i=0;i<s.size()-p;i++){
    if (s[i]!='.' && s[i+p]!='.'){
      if (s[i]==s[i+p]){qub++;}
      else {flag=true;break;}
	}
  }
  if (qub==n-p){cout<<"No";return 0;}
  if (flag){for (int i=0;i<s.size();i++){
    if (s[i]=='.') cout<<"0";
    else cout<<s[i];
    }
    return 0;
  }
  for (int i=0;i<s.size()-p;i++){
    if (s[i]==s[i+p] && s[i]!='.'){continue;}
    if (s[i]==s[i+p] && s[i]=='.'){s[i]='0',s[i+p]='1';break;}
    if (s[i]!='.' && s[i+p]=='.'){s[i+p]=l(s[i]);break;}
    if (s[i]=='.' && s[i+p]!='.'){s[i]=l(s[i+p]);break;}
  }
  for (int i=0;i<s.size();i++){
    if (s[i]=='.') cout<<"0";
    else cout<<s[i];
  }
  return 0;
}