#include <bits/stdc++.h>
#define int long long 

using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;

    int xor_sum = 0, sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      xor_sum ^= a[i];
      sum += a[i];
    }

    cout << 2 << '\n';
    cout << xor_sum << " " << sum + xor_sum << '\n'; 
    assert(sum + xor_sum + sum + xor_sum == 2 * (xor_sum ^ xor_sum ^ (sum + xor_sum)));
  }


  return 0;
}