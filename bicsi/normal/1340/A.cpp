#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> v(n);

    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i]; --v[i];
      pos[v[i]] = i;
    }
    
    int at = 0;
    int stop = n;
    bool bad = false;
    while (at < n) {
      int p = pos[at];
      for (int i = p; i < stop; ++i) {
        if (v[i] != at++) {
          bad = true;
          break;
        }
      }
      stop = p;
      if (bad) break;
    } 
    
    if (bad) cout << "No\n";
    else cout << "Yes\n";

  }

  return 0;
}