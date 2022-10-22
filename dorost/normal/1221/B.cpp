//***In the name of GOD***\\

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(s) s.size()
// for(int i = 0;i < n; i++)

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n ;i++){
    for(int j = 0; j < n ;j++){
      if((i + j) % 2){
        cout << 'W';
      }else{
        cout << 'B';
      }
    }
    cout << endl;
  }
}