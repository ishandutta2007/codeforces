#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    ll n;
    cin >> n;
    ll a = (ll) sqrt(n/2+.5);
    ll b = (ll) sqrt(n/4+.5);
    if (a*a == n/2 && n%2 == 0 && a>=1) {
      cout << "YES\n";
    } else if (b*b == n/4 && n%4 == 0 && b >= 1) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}