#include <bits/stdc++.h>
using namespace std;
int main(){
  int a=0,x=0,n;
  string s;
  cin >> n >> s;
  for(int i = 0; i < n; i++){
    if(s[i]=='x'){
      x++;
    }else{
      x=0;
    }
    if(x > 2){
      a++;
          }
  }
  cout << a;
}