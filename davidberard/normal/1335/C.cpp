#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    map<int, int> mp;
    int n;
    cin >> n;
    for (int i=1; i<=n; ++i) {
      int a;
      cin >> a;
      mp[a]++;
    }
    int ans = 0;
    for (auto& p : mp) {
      ans = max(ans, min(p.second-1, (int) mp.size()));
      ans = max(ans, min(p.second, (int) mp.size()-1));
    }
    cout << ans << "\n";
  }
  return 0;
}