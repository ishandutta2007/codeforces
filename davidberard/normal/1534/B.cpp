#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll a[400400];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int n;
    cin >> n;
    for (int i=1; i<=n; ++i) {
      cin >> a[i];
    }
    a[n+1] = 0;
    ll taken = 0;
    for (int i=1; i<=n; ++i) {
      if (a[i] > a[i-1] && a[i] > a[i+1]) {
        taken += a[i] - max(a[i-1], a[i+1]);
        a[i] = max(a[i-1], a[i+1]);
      }
    }
    ll sum = 0;
    for (int i=1; i<=n+1; ++i) {
      sum += abs(a[i] - a[i-1]);
    }
    cout << sum + taken << "\n";
  }
  return 0;
}