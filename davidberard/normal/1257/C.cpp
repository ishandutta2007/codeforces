#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  map<int, vector<int>> mp;
  while (TT--) {
    mp.clear();
    int n;
    cin >> n;
    for (int i=1; i<=n; ++i) {
      int x;
      cin >> x;
      mp[x].push_back(i);
    }
    int ans = 1e9;
    for (auto& [q, v] : mp) {
      for (int i=0; i+1<v.size(); ++i) {
        ans = min(ans, v[i+1]-v[i]);
      }
    }
    cout << (ans <= n ? ans+1 : -1) << "\n";
  }
  return 0;
}