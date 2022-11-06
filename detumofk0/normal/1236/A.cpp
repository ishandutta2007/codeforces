#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int t; cin >> t;
  while(t--) {
    int a, b, c;
    cin >> a >> b >> c;

    int ans = 0;
    for(int x = 0; x <= a; ++x){
      int w = min(x, b / 2);;
      int y = min(b - w * 2, c / 2);
      ans = max(ans, w + y);
    }
    cout << ans * 3 << endl;
  }

  return 0;
}