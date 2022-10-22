#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c=0;
  cin>>a>>b;
  if(a > b){
    cout << 0;
    return 0;
  }
  for(int i=0;i<1000; i++){
    a*=3;
    b*=2;
    c++;
    if(a > b){
      cout << c;
      return 0;
    }
  }
}