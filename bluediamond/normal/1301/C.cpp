#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f(ll n) {
  return n * (n + 1) / 2;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    ll n, m, z;
    cin >> n >> m;
    z = n - m;
    m++;
    ll fl = z / m;
    cout << f(n) - (f(fl + 1) * (z % m)) - f(fl) * (m - z % m) << "\n";
  }

}