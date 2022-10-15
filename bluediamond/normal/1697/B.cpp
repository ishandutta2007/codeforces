#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
///typedef long double ld;


signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE


  int n, q;
  cin >> n >> q;
  vector<int> P(n);
  for (auto &x : P) {
    cin >> x;
  }
  sort(P.rbegin(), P.rend());
  vector<ll> S(n + 1, 0);
  for (int i = 0; i < n; i++) {
    S[i + 1] = S[i] + P[i];
  }
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    cout << S[x] - S[x - y] << "\n";
  }

}