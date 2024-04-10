//*in the name of GOD*\\

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// cout << fixed << setprecision(6);
int main(){
  bool f = true;
  string s;
  cin >> s;
  int ans = 0;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == '4' || s[i] == '7'){
      ans++;
    }
  }
  for(int i = 0; i < 20; i++){
    if(ans % 10 != 4 && ans % 10 != 7){
      f = false;
      break;
    }
    ans /= 10;
    if(ans == 0){
      break;
    }
  }
  if(f){
    cout << "YES";
  }else{
    cout << "NO";
  }
}