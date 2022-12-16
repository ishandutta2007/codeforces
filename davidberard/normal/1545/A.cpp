#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) {
      cin >> x;
    }
    vector<pair<int, int>> b;
    for (int i=0; i<n; ++i) {
      b.push_back({a[i], i});
    }
    sort(b.begin(), b.end());
    bool good = true;
    for (int i=0; i<n; ++i) {
      int j = i;
      while (j<n && b[j].first == b[i].first) {
        ++j;
      }
      int odd = 0, even = 0;
      for (int k=i; k<j; ++k) {
        (k%2 == 0 ? even : odd)++;
        (b[k].second%2 == 0 ? even : odd)--;
        //cerr << " " << k << ": " << b[k].second << endl;
      }
      //cerr << endl;
      if (odd != 0 || even != 0) {
        good = false;
      }

      i = j-1;
    }
    cout << (good ? "YES" : "NO") << "\n";
  }
  return 0;
}