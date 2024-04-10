#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

#define sz(s) s.size()

int main(){
  string str[6] = {"Power","Time","Space","Soul","Reality","Mind"};
  string c[6] = {"purple","green","blue","orange","red","yellow"};
  int n;
  cin >> n;
  string s;
  bool v[6] = {false,false,false,false,false,false};
  int x = 0;
  for(int i = 0; i < n; i++){
    cin >> s;
    for(int j = 0; j < 6; j++){
      if(s[0] == c[j][0]){
        v[j] = true;
      }
    }
  }
  cout << 6 - n << endl;
  for(int i = 0; i < 6; i++){
    if(!v[i]){
      cout << str[i] << endl;
    }
  }
}