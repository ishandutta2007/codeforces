#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ///freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
    }
    sort(a.begin(), a.end());
    int sol = (int) 1e9 + 7;
    for (int i = 0; i + 2 < n; i++) {
      sol = min(sol, a[i + 2] - a[i]);
    }
    cout << sol << "\n";
  }

  return 0;
}