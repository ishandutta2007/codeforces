#include <bits/stdc++.h>
using namespace std;
int main(){
  int a=0,b=0,n;
  string s;
  cin>>n;
  cin>>s;
  for(int i = 0; i < n; i++){
    if(s[i]=='0'){
      a++;
    }else{
      b++;
    }
  }
  if(b){
    cout << "1";
  }
  for(int g = 0; g < a; g++){
    cout << 0;
  }
}