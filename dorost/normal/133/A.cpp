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
  int n = s.size();
  for(int i = 0; i < n; i++){
    if(s[i] == 'H'  || s[i] == 'Q'  || s[i] == '9'){
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}