#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> v(n);
    vector<int> odd, even;
    for (int i = 0; i < n; ++i) {
      cin >> v[i]; v[i] %= 2; 
      if (v[i] % 2 == 0)
        even.push_back(i);
      else odd.push_back(i);
    }


    long long best = 2e18;
    for (int z = 0; z < 2; ++z) {
      int ptr = 0;
      long long ans = 0;
      bool bad = false;
      for (int i = 0; i < n; i += 2) {
        if (ptr == (int)even.size()) {
          bad = 1; break;
        }
        int pos = even[ptr++];
        int target = i;
        ans += abs(pos - target);
      }
      if (ptr != (int)even.size()) bad = 1;
      if (!bad) {
        best = min(best, ans);
      }
      swap(odd, even);
    }
    if (best == 2e18)
      best = -1;
    cout << best << '\n';
  }

  return 0;
}