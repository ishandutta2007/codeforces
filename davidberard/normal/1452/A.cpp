#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int x, y;
    cin >> x >> y;
    if (abs(x-y) < 2) {
      cout << x+y << "\n";
    } else {
      cout << 2*max(x,y)-1 << "\n";
    }
  }
  return 0;
}