#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    ll x;
    cin >> x;
    ll lo = 0, hi = 1e9;
    while (lo<hi) {
      ll mid = (lo+hi)/2;
      if (mid*(mid+1)/2 < x) {
        lo = mid+1;
      } else {
        hi = mid;
      }
    }
    if (lo*(lo+1)/2 == x) {
      cout << lo << endl;
    } else if (lo*(lo+1)/2-1 == x) {
      cout << lo +1 << endl;
    } else {
      cout << lo << endl;
    }
  }
  return 0;
}