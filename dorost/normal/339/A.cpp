#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int a[((s.size()) / 2)+1];
  for(int i = 0; i < s.size(); i++){
    if(((i % 2) == 0) && s[i] == '1'){
      a[(i / 2)] = 1;
    }else if(((i % 2) == 0) && (s[i] == '2')){
      a[(i / 2)] = 2;
    }else if((i % 2) == 0){
      a[(i / 2)] = 3;
    }
  }
  sort(a, a+(((s.size()) / 2)+1));
    for(int i = 0; i <= s.size() / 2; i++){
      cout << a[i];
      if(i != s.size() / 2){
        cout << '+';
    }
  }
}