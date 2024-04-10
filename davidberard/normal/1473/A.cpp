#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (auto& x : a) {
      cin >> x;
    }
    sort(a.begin(), a.end());
    if (a[0]+a[1] <=d || a.back() <= d) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}