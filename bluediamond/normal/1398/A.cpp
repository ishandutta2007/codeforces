#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i].first;
      a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    if (a[0].first + a[1].first <= a[n - 1].first) {
      vector<int> e = {a[0].second, a[1].second, a[n - 1].second};
      sort(e.begin(), e.end());
      for (auto &i : e) {
        cout << i << " ";
      }
      cout << "\n";
    } else {
      cout << "-1\n";
    }
  }
  return 0;
}
/**
**/