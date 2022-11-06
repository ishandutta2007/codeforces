#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL);

  int q; 
  cin >> q;

  while(q--) {
    int x, y, u, v;
    cin >> x >> y >> u >> v;
    bool sw = false;
    if(x > u) {
      swap(x, u);
      swap(y, v);
      sw = true;
    }
    if(sw) swap(x, v);
    cout << x << " " << v << endl;
  }
	
  return 0;
}