#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    ll a, b;
    cin >> a >> b;
    if (a == 0 && b == 0) {
      cout << "0\n";
    }
    else if (a == b) {
      cout << "1\n";
    }
    else if (a != b && abs(a-b)%2 == 0) {
      cout << "2\n";
    } else {
      cout << "-1\n";
    }
  }
  return 0;
}