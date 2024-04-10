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
    int a, b, c;
    cin >> a >> b;
    if (a % b == 0) {
      c = 0;
    } else {
      c = b - a % b;
    }
    cout << c << "\n";
  }
}