#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int T;
  cin >> T;

  while(T--) {
    int x, y;
    cin >> x >> y;

    if(x >= y) cout << "YES\n";
    else {
      if(x == 1) {
        if(y == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
      }
      else {
        if(x <= 3) {
          if(y <= 3) cout << "YES" << endl;
          else cout << "NO" << endl;
        }
        else {
          cout << "YES" << endl;
        }
      }
    }
  }

  return 0;
}