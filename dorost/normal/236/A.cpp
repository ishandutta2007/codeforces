#include<bits/stdc++.h>

using namespace std;

#define ll long long int

int main(){
  string s;
  cin >> s;
  ll n = s.size();
  ll ans = n;
  for(int i = 0;i < n;i++){
    for(int j = 0; j < i; j++){
      if(s[i] == s[j]){
        ans--;
        break;
      }
    }
  }
  if(ans % 2){
    cout << "IGNORE HIM!";
  }else{
    cout << "CHAT WITH HER!";
  }
}