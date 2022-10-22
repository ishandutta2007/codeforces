#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d,q=0;
  string s;
  cin >> a >>  b >> c >> d >> s;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == '1'){
      q+=a;
    }
    if(s[i] == '2'){
      q+=b;
    }
    if(s[i] == '3'){
      q+=c;
    }
    if(s[i] == '4'){
      q+=d;
    }
  }
  cout << q;
}