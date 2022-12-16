#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    ll x, y, a, b;
    cin >> x>> y >> a >> b;
    b = min(b, a*2);
    cout << abs(x-y)*a + min(x,y)*b << endl;
  }
  return 0;
}