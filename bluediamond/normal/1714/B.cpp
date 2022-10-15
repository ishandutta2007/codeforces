#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> s;
    int sol = 0;
    for (auto &x : a) {
      cin >> x;
    }
    for (int i = n - 1; i >= 0; i--) {
      s.insert(a[i]);
      if ((int) s.size() != n - i) {
        break;
      }
      sol++;
    }
    cout << n - sol << "\n";
  }
  return 0;
}