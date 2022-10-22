#include <bits/stdc++.h>
using namespace std;
int main(){
  int a;
  cin >> a;
  if((a % 4) == 1){
    cout << 8;
  }else if((a % 4) == 2){
    cout << 4;
  }else if((a % 4) == 3){
    cout << 2;
  }else if(a == 0){
    cout << 1;
  }else{
    cout << 6;
  }
}