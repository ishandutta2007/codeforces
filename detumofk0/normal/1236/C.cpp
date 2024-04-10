#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      if(j * 2 < n) cout << j * n + i + 1 << " ";
      else cout << j * n + n - i << " ";
    }
    cout << endl;
  }

  return 0;
}