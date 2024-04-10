#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int n;
    cin >> n;
    vector<int> odd, even;
    for (int i=1; i<=n; ++i) {
      int x;
      cin >> x;
      (x%2 ? odd : even).push_back(x);
    }
    for (auto& x : odd) {
      cout << x << " ";
    }
    for (auto& x : even)  {
      cout << x << " ";
    }
    cout << '\n';
  }
  return 0;
}