#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

int main(){
  string s,t;
  cin >> s >> t;
  int n = s.size();
  for(int i = 0; i < n; i++){
    if(s[i] != t[i]){
      cout << 1;
    }else{
      cout <<0;
    }
  }
}