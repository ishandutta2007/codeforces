#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k, ret = k;
    cin >> n >> k;
    int value;
    value = (n + k - 1) / k;
    value *= k;
    cout << (value + n - 1) / n << "\n";
  }

}