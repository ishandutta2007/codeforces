#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int n;
    cin >> n;
    for (int i=1; i<=n; ++i) {
      ll a;
      cin >> a;
      pair<ll, ll> best = {2e9, 0};
      for (int j=0; j<=29; ++j) {
        best = min(best, {abs((1LL<<j)-a), 1LL<<j});
      }
      cout << best.second << " ";
    }
    cout << "\n";
  }
  return 0;
}