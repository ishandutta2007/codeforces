//in the name of GOD//

#include<bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int a,b;
    cin >> a >> b;
    bool f = false;
    for(int i = 2; i <= min(a , b); i++){
      if(a % i == 0 && b % i == 0){
        f = true;
        break;
      }
    }
    if(f){
      cout << "Infinite";
    }else{
      cout << "Finite";
    }
    cout << endl;
  }
}