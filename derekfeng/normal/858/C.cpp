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
map<char,int>m;
int b[100000];
int vis[100000];  
int judge(char a){  
  if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u') return 1;  
  else return 0;  
}
int main(){  
  string s;  
  cin>>s;  
  int x=0;  
  for(int i=0; i<s.size(); i++){  
    if(judge(s[i])==1) x=0;  
    else x++;  
    if(x>2&&(s[i]!=s[i-1]||s[i-1]!=s[i-2])){  
      cout<<" ";  
      x=1;  
    }  
    cout<<s[i];  
  }   
}