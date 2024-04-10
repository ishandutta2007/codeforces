#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  for(int j = 0; j<t; j++){
    int n, m, k;
    cin >> n >> m >> k;
    int h[n];
    for(int i = 0; i<n; i++){
      int a;
      cin >> a;
      h[i] = a;
    }
    bool work = true;
    for(int i = 0; i<n-1; i++){
      if(h[i] >= h[i+1]){
        if(h[i+1]-k<0){
          m+=h[i];
        }
        else{
          m+=h[i]-h[i+1]+k;
        }
      }
      else{
        if(h[i+1]-h[i] <= k){
          if(h[i+1]-k<0) m+= h[i];
          else m += k-h[i+1]+h[i];
        }
        else{
          if(m < h[i+1]-h[i]-k){
            work = false;
            break;
          }
          else m -= h[i+1]-h[i]-k;
        }
      }
    }
    if(work) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}