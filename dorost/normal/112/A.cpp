#include <bits/stdc++.h>
using namespace std;

int main(){
  string s,q;
  cin >> s >> q;
  for(int i = 0; i < s.size(); i++){
    s[i]=tolower(s[i]);
    q[i]=tolower(q[i]);
    if(s[i] > q[i]){
      cout << 1;
      return 0;
    }
    if(s[i] < q[i]){
      cout << -1;
      return 0;
    }
  }
  cout << 0;
}