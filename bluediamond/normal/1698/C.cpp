/// 486 -> 487
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int long long

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE

  int t;
  cin >> t;
  while (t--) {
    int n, z = 0;
    cin >> n;
    vector<int> a;
    set<int> s;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      s.insert(x);
      if (x == 0) {
        z++;
      } else {
        a.push_back(x);
      }
    }
    n = (int) a.size();
    sort(a.rbegin(), a.rend());
    bool ok = 1;
    for (int cntz = 0; cntz <= min(z, 3LL) && ok; cntz++) {
      int rem = 3 - cntz;
      assert(0 <= rem && rem <= 3);
      if (rem == 0) {
        ok &= (s.count(0));
      }
      if (rem == 1) {
        for (int i = 0; i < n && ok; i++) {
          ok &= (s.count(a[i]));
        }
      }
      if (rem == 2) {
        for (int i = 0; i < n && ok; i++) {
          for (int j = 0; j < i && ok; j++) {
            ok &= (s.count(a[i] + a[j]));
          }
        }
      }
      if (rem == 3) {
        for (int i = 0; i < n && ok; i++) {
          for (int j = 0; j < i && ok; j++) {
            for (int k = 0; k < j && ok; k++) {
              ok &= (s.count(a[i] + a[j] + a[k]));
            }
          }
        }
      }
    }
    cout << ((ok) ? ("YES") : ("NO")) << "\n";
  }
}