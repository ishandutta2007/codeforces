#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool ok(ll x) {
  ll n = x;
  while (x) {
    ll c = x % 10;
    if (c > 0 && n % c != 0) {
      return 0;
    }
    x /= 10;
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);


  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    while (!ok(n)) {
      n++;
    }
    cout << n << "\n";
  }


}