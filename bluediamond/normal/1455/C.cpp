#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);


  int t;
  cin >> t;
  while (t--) {
    int alice, bob;
    cin >> alice >> bob;
    if (alice <= bob) {
      cout << alice - 1 << " " << bob << "\n";
      continue;
    }
    /// alice > bob
    alice--;
    swap(alice, bob);
    cout << bob << " " << alice << "\n";
  }

}