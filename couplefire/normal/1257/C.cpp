#include <bits/stdc++.h>
using namespace std;

int main() {
  int q; cin >> q;
  while(q--){
    int n;
    cin >> n;
    int ans = INT_MAX;
    int arr[n];
    fill(arr, arr+n, -1);
    for(int i = 0; i<n; i++){
      int a; cin >> a; --a;
      if(arr[a] != -1){
        ans = min(ans, i-arr[a]+1);
      }
      arr[a] = i;
    }
    if(ans == INT_MAX){
      cout << -1 << endl;
    }
    else cout << ans << endl;
  }
}