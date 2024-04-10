#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int nTest; cin >> nTest;
  while(nTest--) {
    int n; cin >> n;
    vector < int > a(n), b(n);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;

    bool flag = false, end = false, ok = true;
    int delta;

    for(int i = 0; i < n; ++i) {
      if(!flag) {
        if(a[i] == b[i]) continue;
        flag = true;
        delta = b[i] - a[i];
        if(delta < 0) {
          ok = false;
          break;
        }
      }
      else {
        if(a[i] == b[i]) {
          end = true;
        }
        else {
          if(end) ok = false;
          if(delta != b[i] - a[i]) {
            ok = false;
          }
        }
      }
    }
    cout << (ok ? "YES" : "NO") << endl;
  }

  return 0;
}