#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  long long a,b,c;
  cin >> t;
  for(int i = 0; i < t; i++){
    cin >> a >> b >> c;
    if(c % 2){
      cout << ((a - b) * (c / 2)) + a << endl;
    }else{
      cout << ((a - b) * c / 2) << endl;
    }
  }
}