#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0); cin.tie(0);


  int t;
  cin >> t;
  while (t--) {
    vector<int> a(7);
    for (auto &x : a) {
      cin >> x;
    }
    sort(a.begin(), a.end());
    cout << a[0] << " " << a[1] << " " << a[6] - a[0] - a[1] << "\n";
  }


  return 0;
}