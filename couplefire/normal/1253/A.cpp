#include <bits/stdc++.h>
using namespace std;

int main() {
  int q; cin >> q;
  while(q--){
    int n; cin >> n;
    int a[n];
    int b[n];
    bool end = false;
    int cur = 0;
    for(int i = 0; i<n; i++) cin >> a[i];
    for(int i = 0; i<n; i++) cin >> b[i];
    bool print = false;
    for(int i = 0; i<n; i++){
      int t = b[i];
      if(t-a[i] != 0){
        if(t - a[i] < 0){
          cout << "NO" << endl;
          print = true;
          break;
        }
        if(end){
          cout << "NO" << endl;
          print = true;
          break;
        }
        if(cur == 0){
          cur = t-a[i];
        }
        else if(t - a[i] != cur){
          cout << "NO" << endl;
          print = true;
          break;
        }
      }
      else{
        if(cur != 0) end=  true;
      }
    }
    if(!print) cout << "YES" << endl;
  }
}