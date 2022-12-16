#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    ll n, m, k;
    cin >> n >> m >> k;
    cout << (n*(m-1) + (n-1) == k ? "YES" : "NO") << "\n";
  }
  return 0;
}