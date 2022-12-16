#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int a, b, c;
    cin >> a >> b >> c;
    int g = 1;
    while (to_string(g).size() < c) {
      g *= 5;
    }
    int x = g;
    int y = g;
    while (to_string(x).size() < a) {
      x *= 2;
    }
    while (to_string(y).size() < b) {
      y *= 3;
    }
    cout << x << " " << y << "\n";
  }
  return 0;
}