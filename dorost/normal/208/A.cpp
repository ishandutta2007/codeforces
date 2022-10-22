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
  bool f = false;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B'){
      i += 2;
      if(f)
      cout << ' ';
      f = false;
    }else{
      f = true;
      cout << s[i];
    }
  }
}