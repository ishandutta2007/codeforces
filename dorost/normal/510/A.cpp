//in the name of GOD//

#include<bits/stdc++.h>

using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    if(i % 2 == 0){
      for(int i = 0; i < m; i++){
        cout << '#';
      }
    }else if(i % 4 == 1){
      for(int i = 1; i < m; i++){
        cout << '.';
      }
      cout << '#';
    }else{
      cout << '#';
      for(int i = 1; i < m; i++){
        cout << '.';
      }
    }
    cout << endl;
  }
}