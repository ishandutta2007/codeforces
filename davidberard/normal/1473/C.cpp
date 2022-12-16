#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int n, k;
    cin >> n >> k;
    vector<int> a;
    for (int i=1; i<=k; ++i) {
      a.push_back(i);
    }
    for (int i=k-1; i>=1 && a.size() < n; --i) {
      a.push_back(i);
    }
    int z = a.back();
    for (int i=1; i<=k; ++i) {
      int b = i;
      if (i >= z) {
        b = k-i + z;
      }
      cout << b << " ";
    }
    cout << "\n";
  }
  return 0;
}