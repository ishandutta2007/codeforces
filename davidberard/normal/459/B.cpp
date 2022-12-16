#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  map<int, int> mp;
  int n;
  cin >> n;
  for (int i=1; i<=n; ++i) {
    int b;
    cin >> b;
    mp[b]++;
  }
  int diff = prev(mp.end())->first - mp.begin()->first;
  if (mp.size() == 1) {
    ll q = mp.begin()->second;
    cout << diff << " " << (ll) q*(q-1)/2 << "\n";
    return 0;
  }
  ll p = mp.begin()->second;
  ll q = prev(mp.end())->second;
  cout << diff << " " << p*q << "\n";
  return 0;
}