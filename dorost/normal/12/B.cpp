//in the name of GOD//

#include<bits/stdc++.h>

using namespace std;

int main(){
  bool f = true;
  string s,t;
  cin >> s >> t;
  int n = s.size();
  if(n != t.size()){
    f = false;
  }
  char c[n],h[n];
  for(int i = 0; i < n; i++){
    c[i] = s[i];
    h[i] = t[i];
  }
  sort(c, c + n);
  for(int i = 0; i < n; i++){
    if(c[i] != '0'){
      swap(c[i], c[0]);
      break;
    }
  }
  for(int i = 0; i < n; i++){
    if(c[i] != h[i]){
      f = false;
      break;
    }
  }
  if(f){
    cout << "OK";
  }else{
    cout << "WRONG_ANSWER";
  }
}