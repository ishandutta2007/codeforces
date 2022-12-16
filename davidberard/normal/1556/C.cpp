#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto& x : v) {
    cin >> x;
  }
  ll ans = 0;
  for (int i=0; i+1<n; i+=2) {
    ans += min(v[i], v[i+1]);
    ll fq = v[i]-v[i+1];
    ll extra = fq;
    bool good = v[i+1] <= v[i];
    for (int j=i+3; j<n && good; j+=2) {
      ans += min(max(v[j]-v[j-1]-extra+fq+1, 0LL), fq+1);

      extra += v[j-1] - v[j];
      if (extra < 0) {
        good = false;
      }
      fq = min(extra, fq);
    }
  }
  cout << ans << "\n";
  return 0;
}