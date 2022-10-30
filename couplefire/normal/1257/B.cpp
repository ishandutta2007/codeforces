#include <bits/stdc++.h>
using namespace std;

int main() {
  int q; cin >> q;
  while(q--){
    int a, b; cin >> a >> b;
    if(a == 1){
      if(b != 1) cout << "NO" << endl;
      else cout << "YES" << endl;
    }
    else if(a == 2){
      if(b != 3 && b != 2 && b != 1) cout << "NO" << endl;
      else cout << "YES" << endl;
    }
    else if(a == 3){
      if(b != 3 && b != 2 && b != 1) cout << "NO" << endl;
      else cout << "YES" << endl;
    }
    else cout << "YES" << endl;
  }
}