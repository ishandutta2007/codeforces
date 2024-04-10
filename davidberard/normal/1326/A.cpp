#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << "-1\n";
      continue;
    }
    if (n%3 == 1) {
      cout << "3";
    } else {
      cout << "4";
    }
    for (int i=1; i<n-1; ++i) {
      cout << "4";
    }
    cout << "3\n";
  }
  return 0;
}