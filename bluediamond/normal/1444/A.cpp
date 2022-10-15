#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    ll p, q;
    cin >> p >> q;
    if (p % q) {
      cout << p << "\n";
      continue;
    }
    vector<pair<ll, int>> pr;
    ll d = 2;
    while (d * d <= q) {
      int cnt = 0;
      while (q % d == 0) {
        q /= d;
        cnt++;
      }
      if (cnt >= 1) {
        pr.push_back({d, cnt});
      }
      d++;
    }
    if (q > 1) {
      pr.push_back({q, 1});
    }
    ll sol = 0;
    for (auto &it : pr) {
      ll prime = it.first;
      int cnt = it.second;
      ll num = p;
      while (num % prime == 0) {
        num /= prime;
      }
      for (int j = 1; j < cnt; j++) {
        num *= prime;
      }
      sol = max(sol, num);
    }
    cout << sol << "\n";
  }

}