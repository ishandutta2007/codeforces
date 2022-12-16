#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll check(const vector<int>& idx, int pairity) {
  ll ans = 0;
  for (int i=pairity, j=0; j<idx.size(); ++j, i+=2) {
    ans += abs(i-idx[j]);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int n;
    cin >> n;
    vector<int> r(n);
    int odd = 0, even = 0;
    vector<int> ov, ev;
    for (int i=0; i<n; ++i) {
      int& x = r[i];
      cin >> x;
      (x%2 ? odd : even)++;
      (x%2 ? ov : ev).push_back(i);
    }
    if (max(odd, even) != (n+1)/2) {
      cout << "-1\n";
    } else {
      if (n%2) {
        cout << check((max(odd, even) == odd ? ov : ev), 0) << "\n";
      } else {
        ll res = min(check(ov, 0), check(ev, 0));
        cout << res << "\n";
      }
    }
  }
  return 0;
}