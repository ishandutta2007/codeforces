#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  bool ans = false;
  for(int i = 0; i < s.size(); i++){
    bool p=true;
    for(int j = 0; j < 7; j++){
      if(s[i] != s[i - j]){
        p=false;
      }
    }
    if(p) ans = true;
  }
  if(ans){
    cout << "YES";
  }else{
    cout << "NO";
  }
}