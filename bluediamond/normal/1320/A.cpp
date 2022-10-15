#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  map<int, ll> sol;
  for (int i = 1; i <= n; i++) {
    ll x;
    cin >> x;
    sol[x - i] += x;
  }
  ll ans = 0;
  for (auto &it : sol) {
    ans = max(ans, it.second);
  }
  cout << ans << "\n";
}