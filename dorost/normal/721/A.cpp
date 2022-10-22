#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,a = 1,b=0;
  cin >> n;
  string s;
  cin >> s;
  for(int i = 1; i < n; i++){
    if(s[i] != s[i - 1]){
      a++;
    }
  }
  for(int i = 0; i < n; i++){
    if((s[0] == 'B') && (s[n - 1] == 'B')){
      cout << a / 2 + 1 << endl;
      break;
    }else{
      cout << a / 2 << endl;
      break;
    }
  }
  for(int i = 0; i < n; i++){
    if(s[i] == 'B'){
      b++;
    }else if(b){
      cout << b << ' ';
      b = 0;
    }
    if(i == (n - 1) && b){
      cout << b;
    }
  }
}