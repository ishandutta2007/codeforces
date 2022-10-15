#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int tests;
  cin >> tests;
  for (int tc = 1; tc <= tests; tc++) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
    }
    int p = min_element(a.begin(), a.end()) - a.begin();
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      b[i] = a[(i + p) % n];
    }
    a = b;
    bool ok = 1;
    for (int i = 0; i < n; i++) {
      ok &= (a[i] <= i + 1);
      if (i) {
        if (a[i] > a[i - 1]) {
          ok &= (abs(a[i] - a[i - 1]) == 1);
        }
        ok &= (a[i] >= 2);
      }
    }
    cout << ((ok) ? ("YES") : ("NO")) << "\n";
  }


  return 0;
}