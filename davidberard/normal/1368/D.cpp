#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int cnt[23];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  for (int i=1; i<=n; ++i) {
    int x;
    cin >> x;
    for (int i=0; i<=20; ++i) {
      if ((x&(1<<i))) {
        ++ cnt[i];
      }
    }
  }
  ll sum = 0;
  for (int i=0; i<n; ++i) {
    ll cur = 0;
    for (int j=0; j<=20; ++j) {
      if (cnt[j]) {
        --cnt[j];
        cur |= (1<<j);
      }
    }
    sum += cur*cur;
  }
  cout << sum << "\n";
  return 0;
}