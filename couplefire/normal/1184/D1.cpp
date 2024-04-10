#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, m, t;
  cin >> n >> k >> m >> t;
  for(int i = 0; i<t; i++){
    int a, b;
    cin >> a >> b;
    if(a == 0){
      if(b >= k){
        n = b;
      }
      else{
        n = n-b;
        k = k-b;
      }
    }
    else{
      ++n;
      if(b <= k) ++k;
    }
    cout << n << " " << k << endl;
  }
}