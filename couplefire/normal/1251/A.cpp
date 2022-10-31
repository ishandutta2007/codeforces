#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  while(t--){
    string s; cin >> s;
    int n = s.length();
    set<char> stc;
    char prev = '.';
    int ap = 0;
    for(int i = 0; i<n; i++){
      int c = s[i];
      if(c != prev){
        if(ap % 2 == 1) stc.insert(prev);
        ap = 1;
      }
      else ap++;
      prev = c;
    }
    if(ap % 2 == 1) stc.insert(prev);
    for(auto i : stc) cout << i;
    cout << endl;
  }
}