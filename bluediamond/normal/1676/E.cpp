#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int& x: a) cin >> x;
    sort(a.begin(), a.end(), greater<int>());
    for (int i = 1; i < n; i++) {
      a[i] += a[i-1];
    }
    while (q--) {
      int x;
      cin >> x;
      auto it = lower_bound(a.begin(), a.end(), x);
      if (it == a.end()) {
        cout << "-1\n";
      }
      else {
        cout << it-a.begin()+1 << '\n';
      }
    }
  }
}