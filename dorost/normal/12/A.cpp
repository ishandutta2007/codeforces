//in the name of GOD//

#include<bits/stdc++.h>

using namespace std;

int main(){
  string s[3];
  cin >> s[0] >> s[1] >> s[2];
  for(int i = 0; i < 3 ;i++){
    if(s[0][i] != s[2][2 - i]){
      cout << "NO";
      return 0;
    }
  }
  if(s[1][0] == s[1][2]){
    cout << "YES";
  }else{
    cout << "NO";
  }
}