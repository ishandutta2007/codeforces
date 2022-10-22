#include <bits/stdc++.h>
using namespace std;
int main(){
  int a;
  cin >> a;
  cout << a / 2 << endl;
  for(int i = 0; i < a / 2; i++){
    if((i == (a / 2)-1)&& (a % 2)){
      cout << 3 << ' ';
    }else{
      cout << 2 << ' ';
    }
  }
}