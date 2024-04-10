#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a < c) {
      cout << 1 << " ";
    } else {
      cout << "-1 ";
    }
    if (a * b > c) {
      cout << b << "\n";
    } else {
      cout << "-1\n";
    }
  }
  return 0;
}