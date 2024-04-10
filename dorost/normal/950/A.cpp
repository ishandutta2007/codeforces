#include<bits/stdc++.h>

using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  if(a + c < b){
    cout << (a + c) * 2;
  }else if(b + c < a){
    cout << (b + c) * 2;
  }else if(b > a){
    cout << (b + ((c - (b - a)) / 2)) * 2;
  }else{
    cout << (a + (c - (a - b)) / 2) * 2;
  }
}