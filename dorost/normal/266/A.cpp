#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,a = 0, b = 0;
  cin >> n;
  string s;
  cin >> s;
  for(int i = 1; i < n; i++){
    if(s[i] == s[i - 1]){
      a++;
    }else{
      b+=a;
      a = 0;
    }
    if(i == (n - 1)){
      b+=a;
      a = 0;
    }
  }
  cout << b;
}