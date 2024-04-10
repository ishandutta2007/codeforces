#include<bits/stdc++.h>

using namespace std;

#define ll long long int

int main(){
  int ans = 0;
  bool b = 1;
  string s[8];
  for(int i = 0; i < 8;i++){
    cin >> s[i];
    if(s[i] == "BBBBBBBB"){
      ans++;
    }
  }
  if(ans == 8){
    cout << 8;
    return 0;
  }
  for(int i = 0 ; i < 8;i++){
    b = 1;
    for(int j = 0 ; j < 8;j++){
      if(s[j][i] == 'W'){
        b = 0;
      }
    }
    if(b){
      ans++;
    }
  }
  cout << ans;
}