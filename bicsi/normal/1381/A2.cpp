#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    // string _a = a;

    int l = 0, r = n - 1;
    bool flipped = false;
    vector<int> ans;
    for (int it = 0; it < n; ++it) {
      // cerr << l << " " << r << endl;
      int pos = n - it - 1;
      if (a[r] == (b[pos] ^ flipped)) {
        if (l < r) r -= 1;
        else r += 1;
        continue;
      }
      if (a[l] != a[r]) {
        ans.push_back(1);
        a[l] ^= ('0' ^ '1');
      }
      ans.push_back(pos + 1);
      flipped ^= 1;
      swap(l, r);
      if (l < r) r -= 1;
      else r += 1;
    }
    
    // a = _a;
    // for (auto x : ans) {
    //   for (int i = 0; i < x; ++i)
    //     a[i] ^= ('0' ^ '1');
    //   reverse(a.begin(), a.begin() + x);
    //   cerr << "E: " << a << endl;
    // }
    
    cout << ans.size() << ' ';
    for (auto x : ans) 
      cout << x << " ";
    cout << '\n';
  }

  return 0;
}