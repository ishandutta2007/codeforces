#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  ll a,b;
  cin >> a>> b;
  bool is = 0;
  if (b > a) {
    swap(a, b);
    is = 1;
  }
  ll sa = 0, sb = 0;
  ll g = __gcd(a, b);
  a /= g;
  b /= g;
  for (int i=1; i<=a; ++i) {
    int btake = min((ll) a-i, b);
    sb += btake;
    sa += b-btake;
  }
  if (is) {
    swap(sa, sb);
  }
  cout << (sa == sb ? "Equal" : (sa > sb ? "Dasha" : "Masha")) << "\n";
  return 0;
}