//*in the name of GOD*\\

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// cout << fixed << setprecision(6);
int main(){
  string s;
  cin >> s;
  int cnt1 = 0,cnt2 = 0;
  for(int i = 0; i < s.size(); i++){
    if(s[i] < 'a'){
      cnt1++;
    }else{
      cnt2++;
    }
  }
  if(cnt1 > cnt2){
    for(int i = 0; i < s.size(); i++){
      s[i] = toupper(s[i]);
    }
  }else{
    for(int i = 0; i < s.size(); i++){
      s[i] = tolower(s[i]);
    }
  }
  cout <<  s;
}