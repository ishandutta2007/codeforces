#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << ((a+b+c)%9 == 0 && min(a, min(b, c)) >= (a+b+c)/9 ? "YES" : "NO") << "\n";
  }
  return 0;
}